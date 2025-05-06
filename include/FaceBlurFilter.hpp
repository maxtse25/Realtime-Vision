#pragma once

#include "Filter.hpp"
#include <opencv2/objdetect.hpp>

/**
* @brief A filter that detects and blues faces using Haar cascades classifier.
*/
class FaceBlurFilter : public Filter {
public:
	FaceBlurFilter();

	/**
	* @brief Apply face detection and blur on the input image.
	* @param input The input image (BGR).
	* @param output The output image with blurred faces.
	*/
	void apply(const cv::Mat& input, cv::Mat& output) override;

private:
	cv::CascadeClassifier face_cascade; // Haar cascade classifier for face detection
	bool loadSuccessfully;
};