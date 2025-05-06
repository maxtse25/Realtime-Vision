#pragma once

#include "Filter.hpp"
#include <opencv2/imgproc.hpp>

/**
 * @brief A filter that applies Gassian blur to the input image.
 */

class BlurFilter : public Filter {
public:
	/**
	 * @brief Constructor.
	 */
	BlurFilter();

	/**
	 * @brief Apply Gaussian blur to the input frame.
	 * @param input Input image (BGR).
	 * @param output Blurred image.
	 */
	void apply(const cv::Mat& input, cv::Mat& output) override;

	/**
	 * @brief Create a UI trackbar for controlling the blur strength.
	 */
	void createTrackbar(const std::string& windowName) override;

	/**
	 * @brief Set the blur size. Ensures a minimum of 1.
	 * @param size New blur size.
	 */
	void setBlurSize(int size);

private:
	int blurSize; // kernel sizes
};