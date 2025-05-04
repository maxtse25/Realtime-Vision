#include "VideoProcessor.hpp"

/**
 * @brief Entry point of the application.
 * @return Exit status code.
 */
int main() {
    // Create a VideoProcessor object
    VideoProcessor processor;

    // Open the default camera (index 0)
    if (!processor.openCamera(0)) {
        return -1;
    }

    // Start processing frames from the camera
    try {
        processor.processFrames();
    }
    catch (const std::exception& e) {
        std::cerr << "[FATAL] Exception: " << e.what() << std::endl;
        return -1;
    }

    return 0;
}
