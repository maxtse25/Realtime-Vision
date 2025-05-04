// === include/GrayscaleFilter.hpp ===
#pragma once

#include "Filter.hpp"
#include <opencv2/imgproc.hpp>

/**
 * @brief A filter that converts images to grayscale.
 */
class GrayscaleFilter : public Filter {
public:
	void apply(const cv::Mat& input, cv::Mat& output) override;
};