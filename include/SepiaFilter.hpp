#pragma once

#include "Filter.hpp"
#include <opencv2/core.hpp>

/**
 * @brief A filter that applies a sepia tone effect to the image.
 */
class SepiaFilter : public Filter {
public:
    void apply(const cv::Mat& input, cv::Mat& output) override;
};
