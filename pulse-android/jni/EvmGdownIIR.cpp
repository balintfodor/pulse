#include "EvmGdownIIR.hpp"
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/types_c.h>
#include <opencv2/core/core.hpp>

using cv::pyrDown;
using cv::pyrUp;
using cv::resize;

EvmGdownIIR::EvmGdownIIR()
{
    first = true;
    blurredSize = Size(10, 10);
    fLow = 70/60./10;
    fHigh = 80/60./10;
    alpha = 200;
}

void EvmGdownIIR::magnify(const Mat& src, Mat& out)
{
    // convert to float
    src.convertTo(srcFloat, CV_32F);

    // apply spatial filter: blur and downsample
    resize(srcFloat, blurred, blurredSize, 0, 0, CV_INTER_AREA);

    if (first) {
        first = false;
        blurred.copyTo(lowpassHigh);
        blurred.copyTo(lowpassLow);
        src.copyTo(out);
    } else {
        // apply temporal filter: subtraction of two IIR lowpass filters
        lowpassHigh = lowpassHigh * (1-fHigh) + fHigh * blurred;
        lowpassLow = lowpassLow * (1-fLow) + fLow * blurred;
        blurred = lowpassHigh - lowpassLow;

        // amplify
        blurred *= alpha;

        // resize back to original size
        resize(blurred, outFloat, src.size(), 0, 0, CV_INTER_LINEAR);

        // add back to original frame
        outFloat += srcFloat;

        // convert to 8 bit
        outFloat.convertTo(out, CV_8U);
    }
}
