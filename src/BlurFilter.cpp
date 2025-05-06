#include "BlurFilter.hpp"
#include <opencv2/highgui.hpp>

/**
 * @brief Callback function for the OpenCV trackbar. Update blur size.
 * @param pos Position of the trackbar.
 * @param userData Pointer to the BlurFilter object.
 */

static void onTrackbarChange(int pos, void* userData) {
	BlurFilter* filter = static_cast<BlurFilter*>(userData);
	filter->setBlurSize(pos);
}
/**
 * @brief Constructor. Initializes default blur kernel size.
 */
BlurFilter::BlurFilter() : blurSize(11), trackbarCreated(false) {}

/**
 * @brief Applies Gaussian blur to the input image using the current kernel size.
 * @param input Input image (BGR).
 * @param output Blurred image.
 */
void BlurFilter::apply(const cv::Mat& input, cv::Mat& output) {
	// Ensure the kernel size is odd and greater than 1
	int k = (blurSize % 2 == 1) ? blurSize : blurSize + 1;
	cv::GaussianBlur(input, output, cv::Size(k, k), 0);
}
/**
 * @brief Create a UI trackbar for controlling the blur strength.
 * @param windowName Name of the window where the trackbar will be created.
 */
void BlurFilter::createTrackbar(const std::string& windowName) {
	if (trackbarCreated) {
		return; // Trackbar already created
	}
	cv::createTrackbar("Blur Size", windowName, &blurSize, 31, onTrackbarChange, this);
	trackbarCreated = true;
}

/**
 * @brief Set the blur size. Ensures a minimum of 1.
 * @param size New blur size.
 */
void BlurFilter::setBlurSize(int size) {
	blurSize = std::max(1, size);
}