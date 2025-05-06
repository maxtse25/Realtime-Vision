#include "SepiaFilter.hpp"
#include <opencv2/imgproc.hpp>

/**
 * @brief Applies a sepia tone effect using a fixed kernel matrix.
 * @param input Input image (BGR).
 * @param output Output sepia-toned image.
 */

void SepiaFilter::apply(const cv::Mat& input, cv::Mat& output) {
	// Define the sepia kernel
	cv::Mat kernel = (cv::Mat_<float>(3,3) <<
		0.272f, 0.534f, 0.131f,
		0.349f, 0.686f, 0.168f,
		0.393f, 0.769f, 0.189f);

	// Convert to float for accurate transformation
	cv::Mat floatInput;
	input.convertTo(floatInput, CV_32F, 1.0 / 255.0);

	// Apply the sepia kernel
	cv::transform(floatInput, floatInput, kernel);

	// Clip values and convert back to 8-bit
	cv::threshold(floatInput, floatInput, 1.0, 1.0, cv::THRESH_TRUNC);
	floatInput.convertTo(output, CV_8U, 255.0);
}