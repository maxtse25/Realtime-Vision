#include <gtest/gtest.h>
#include <opencv2/opencv.hpp>
#include "VideoProcessor.hpp"

/**
 * @brief A subclass of VideoProcessor for exposing applyFilter in tests.
 */
class TestableProcessor : public VideoProcessor {
public:
    /**
     * @brief Override applyFilter to expose it for unit testing.
     * @param frame Input image.
     * @param output Output image after applying filter.
     */
    void applyFilter(const cv::Mat& frame, cv::Mat& output) override {
        VideoProcessor::applyFilter(frame, output);
    }
};

/**
 * @brief Unit test to verify that grayscale conversion preserves image size and format.
 */
TEST(VideoProcessorTest, GrayscaleConversionPreservesSize) {
    // Load a sample image from relative path
    cv::Mat input = cv::imread("../../../../assets/test_image.png");
    ASSERT_FALSE(input.empty()) << "Failed to load test image";

    // Create a testable processor instance
    TestableProcessor processor;
    cv::Mat output;

    // Apply the grayscale filter
    processor.applyFilter(input, output);

    // Check that output image size matches input
    EXPECT_EQ(input.rows, output.rows);
    EXPECT_EQ(input.cols, output.cols);

    // Check that output is a single-channel grayscale image
    EXPECT_EQ(output.channels(), 1);
}
