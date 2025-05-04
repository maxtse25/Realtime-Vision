#include "EdgeDetectionFilter.hpp"

/**
 * @brief Applies Canny edge detection and converts to BGR for display.
 */

void EdgeDetectionFilter::apply(const cv::Mat& input, cv::Mat& output) {
	cv::Mat gray, edges;
	cv::cvtColor(input, gray, cv::COLOR_BGR2GRAY);
	cv::Canny(gray, edges, 100, 200);
	cv::cvtColor(edges, output, cv::COLOR_GRAY2BGR);
}