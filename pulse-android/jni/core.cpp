#include "core.h"

CoreFunctions::CoreFunctions()
{}

void CoreFunctions::reset(int width, int height)
{}

void CoreFunctions::addFrame(cv::Mat &frame)
{
	_evm.magnify(frame, frame);
}

void CoreFunctions::getGraph(cv::Mat &graph)
{
	graph = cv::Mat::zeros(10,1, CV_64F);
	cv::randu(graph, cv::Scalar(0), cv::Scalar(10));
}

double CoreFunctions::calculateBpm()
{
	return 56.0;
}

CoreFunctions::~CoreFunctions()
{}

