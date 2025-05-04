#pragma once

#include <map>
#include <memory>
#include <string>
#include <iostream>

#include <opencv2/core.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include <string>
#include <iostream>

#include "Filter.hpp"
#include "GrayscaleFilter.hpp"

/**
 * @brief A class for processing video frames from a camera.
 */
class VideoProcessor {
public:
    /**
     * @brief Default constructor.
     */
    VideoProcessor() noexcept;

    /**
     * @brief Constructor that opens the camera with the given index.
     * @param cameraIndex Index of the camera to open.
     */
    explicit VideoProcessor(int cameraIndex) noexcept;

    /**
     * @brief Destructor.
     */
    ~VideoProcessor() noexcept;

    /**
     * @brief Opens the camera with the given index.
     * @param index Index of the camera to open.
     * @return True if the camera was successfully opened, false otherwise.
     */
    bool openCamera(int index = 0);

    /**
     * @brief Starts processing frames from the camera.
     */
    void processFrames();

    /**
     * @brief Checks if the camera is opened.
     * @return True if the camera is opened, false otherwise.
     */
    bool isOpened() const noexcept;

    // Delete copy constructor and copy assignment to avoid accidental duplication of camera resources
    VideoProcessor(const VideoProcessor&) = delete;
    VideoProcessor& operator=(const VideoProcessor&) = delete;

    // Enable move semantics
    VideoProcessor(VideoProcessor&&) = default;
    VideoProcessor& operator=(VideoProcessor&&) = default;

protected:
    /**
     * @brief Applies a filter to the input frame.
     * @param frame Input frame.
     * @param output Output frame after applying the filter.
     */
    virtual void applyFilter(const cv::Mat& frame, cv::Mat& output);

private:
    cv::VideoCapture cap;                ///< Video capture object
    const std::string windowOriginal = "Original Frame";   ///< Window name for original frame
    const std::string windowProcessed = "Processed Frame"; ///< Window name for processed frame

    std::map<char, std::shared_ptr<Filter>> filters; ///< Map of key bindings to filters
    std::map<char, std::string> filterNames; ///< Map of key bindings to filter names
    std::shared_ptr<Filter> currentFilter; ///< Currently selected filter

    /**
     * @brief Registers available filters and initializes default filter.
     */
    void registerFilters();
};
