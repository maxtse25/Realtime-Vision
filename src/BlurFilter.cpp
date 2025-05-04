#include "BlurFilter.hpp"

/**
 * @brief Applies a Gaussian blur to the input image.
 */

void BlurFilter::apply(const cv::Mat& input, cv::Mat& output) {
	cv::GaussianBlur(input, output, cv::Size(11, 11), 0);
}