#pragma once

#include "Filter.hpp"
#include <opencv2/imgproc.hpp>

/**
 * @brief A filter that applies Gassian blur to the input image.
 */

class BlurFilter : public Filter {
public:
	/**
	 * @brief Apply Gaussian blur to the input frame.
	 * @param input Input image (BGR).
	 * @param output Blurred image.
	 */
	void apply(const cv::Mat& input, cv::Mat& output) override;
};