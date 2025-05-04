#pragma once

#include "Filter.hpp"
#include <opencv2/imgproc.hpp>

/**
 * @brief A filter that applies Canny edge detection.
 */

class EdgeDetectionFilter : public Filter {
public:
	/**
	 * @brief Apply Canny edge detection to the input frame.
	 * @param input Input image (BGR).
	 * @param output Output edge-detected image (BGR).
	 */
	void apply(const cv::Mat& input, cv::Mat& output) override;
};