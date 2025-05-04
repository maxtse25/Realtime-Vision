#include "VideoProcessor.hpp"
#include "GrayscaleFilter.hpp"
#include "BlurFilter.hpp"

/**
 * @brief Default constructor.
 */
VideoProcessor::VideoProcessor() noexcept = default;

/**
 * @brief Constructor that opens the camera with the given index.
 * @param cameraIndex Index of the camera to open.
 */
VideoProcessor::VideoProcessor(int cameraIndex) noexcept {
    openCamera(cameraIndex);
}

/**
 * @brief Destructor that releases the camera and destroys all OpenCV windows.
 */
VideoProcessor::~VideoProcessor() noexcept {
    if (cap.isOpened()) {
        cap.release();
    }
    cv::destroyAllWindows();
}

/**
 * @brief Opens the camera with the specified index.
 * @param index Index of the camera to open.
 * @return True if the camera was successfully opened, false otherwise.
 */
bool VideoProcessor::openCamera(int index) {
    if (!cap.open(index)) {
        std::cerr << "[ERROR] Failed to open camera at index " << index << std::endl;
        return false;
    }
    return true;
}

/**
 * @brief Checks if the camera is opened.
 * @return True if the camera is opened, false otherwise.
 */
bool VideoProcessor::isOpened() const noexcept {
    return cap.isOpened();
}

/**
 * @brief Registered available filters and sets the default filter.
 */
void VideoProcessor::registerFilters() {
    filters['g'] = std::make_shared<GrayscaleFilter>();
    filters['b'] = std::make_shared<BlurFilter>();
    filterNames['g'] = "Grayscale";
    currentFilter = filters['g'];
}


/**
 * @brief Starts processing frames from the camera, applying filters and displaying the results.
 */
void VideoProcessor::processFrames() {
    registerFilters();

    if (!cap.isOpened()) {
        std::cerr << "[ERROR] Camera is not opened." << std::endl;
        return;
    }

    // Create windows to display the original and processed frames
    // cv::namedWindow(windowOriginal, cv::WINDOW_AUTOSIZE);
    cv::namedWindow(windowProcessed, cv::WINDOW_AUTOSIZE);

    cv::Mat frame, processed;
    std::cout << "[INFO] Press ESC or Q to exit." << std::endl;

    while (true) {
        cap >> frame;
        if (frame.empty()) {
            std::cerr << "[WARNING] Empty frame captured." << std::endl;
            break;
        }

        // Resize input for consistent processing performance
        cv::resize(frame, frame, cv::Size(640, 480));

        // Apply user-defined or default filter
        applyFilter(frame, processed);

        // Display the original and processed frames (PIP overlay of original frame into processed frame)
        // cv::imshow(windowOriginal, frame);
        cv::imshow(windowProcessed, processed);

        // Wait for 10 ms and check if the user pressed ESC or Q to exit
        char key = static_cast<char>(cv::waitKey(10));
        if (key == 27 || key == 'q' || key == 'Q') {
            break;
        }

        // Allow runtime switching of filters by key
        if (filters.count(key)) {
            currentFilter = filters[key];
            std::string name = filterNames.count(key) ? filterNames[key] : "Unknown";
            std::cout << "[INFO] Switched to filter: " << name << " (key '" << key << "')" << std::endl;
        }
    }

    // Destroy all OpenCV windows
    cv::destroyAllWindows();
}

/**
 * @brief Applies a filter to the input frame. Default implementation converts the frame to grayscale.
 * @param frame Input frame.
 * @param output Output frame after applying the filter.
 */
void VideoProcessor::applyFilter(const cv::Mat& frame, cv::Mat& output) {
    if (currentFilter) {
        currentFilter->apply(frame, output);
    }
    else {
        output = frame.clone();
    }

    // Resize original frame to small thumbnail
    cv::Mat thumbnail;
    double scale = 0.2;
    cv::resize(frame, thumbnail, cv::Size(), scale, scale);

    // Define bottom-left position with padding
    int x = 10;
    int y = output.rows - thumbnail.rows - 10; // 10px padding bottom

    // Check ROI bounds
    if (x + thumbnail.cols <= output.cols && y + thumbnail.rows <= output.rows) {
        // Copy thumbnail into output image
        thumbnail.copyTo(output(cv::Rect(x, y, thumbnail.cols, thumbnail.rows)));
    }
}

