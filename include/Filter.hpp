// === include/Filter.hpp ===
#pragma once

#include <opencv2/core.hpp>

/**
 * @brief Abstract base class for image filters.
 */
class Filter {
public:
	virtual ~Filter() = default;

	/**
	 * @brief Apply a transformation to the input frame.
	 * @param input Input frame (usually BGR).
	 * @param output Output frame (after filter applied).
	 */
	virtual void apply(const cv::Mat& input, cv::Mat& output) = 0;

	/**
	 * @brief Create a UI trackbar for controlling filter parameters.
	 * @param windowName Name of the window where the trackbar will be created.
	 */
	virtual void createTrackbar(const std::string& windowName) {
		// Default implementation does nothing
	};
};