#ifndef _pulse_android_core_h_
#define _pulse_android_core_h_

#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include "ext/opencv.hpp"
#include "EvmGdownIIR.hpp"

class CoreFunctions {
public:
	CoreFunctions();
	void reset(int width, int height);
	void addFrame(cv::Mat &frame);
	void getGraph(cv::Mat &graph);
	double calculateBpm();
	~CoreFunctions();
protected:
	EvmGdownIIR _evm;
};

#endif // _pulse_android_core_h_
