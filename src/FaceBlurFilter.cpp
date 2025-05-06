#include "FaceBlurFilter.hpp"
#include <opencv2/imgproc.hpp>
#include <iostream>

/**
* @brief Construtor: loads the Haar cascade classifier for face detection.
*/
FaceBlurFilter::FaceBlurFilter() {
	// Load the Haar cascade classifier for face detection
	loadSuccessfully = face_cascade.load("../../../assets/haarcascade_frontalface_default.xml");
	if (!loadSuccessfully) {
		std::cerr << "Error loading Haar cascade classifier." << std::endl;
	}
}

/**
* @brief Apply Gaussian blur to the detected faces regions.
*/
void FaceBlurFilter::apply(const cv::Mat& input, cv::Mat& output) {
	if (!loadSuccessfully) {
		output = input.clone();
		return;
	}
	output = input.clone(); // Clone the input image to output
	std::vector<cv::Rect> faces; // Vector to store detected faces
	cv::Mat gray; // Grayscale image for face detection
	
	// Convert the input image to grayscale
	cv::cvtColor(input, gray, cv::COLOR_BGR2GRAY);
	cv::equalizeHist(gray, gray); // Equalize histogram for better detection
	
	// Detect faces in the grayscale image
	face_cascade.detectMultiScale(gray, faces, 1.1, 3, 0 | cv::CASCADE_SCALE_IMAGE, cv::Size(30, 30));
	
	// Apply Gaussian blur to each detected face
	for (const auto& face : faces) {
		cv::Mat faceROI = output(face); // Region of interest for the detected face
		int k = std::max(15, (face.width / 5) | 1);
		cv::GaussianBlur(faceROI, faceROI, cv::Size(k, k), 0);
	}
}