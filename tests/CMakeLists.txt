# Create test executable
add_executable(VideoProcessorTest
    test_video_processor.cpp
    ../src/VideoProcessor.cpp
)

# Include directories
target_include_directories(VideoProcessorTest PRIVATE
    ${CMAKE_SOURCE_DIR}/include
    ${OpenCV_INCLUDE_DIRS}
)

# Link libraries
target_link_libraries(VideoProcessorTest
    gtest_main
    ${OpenCV_LIBS}
)

# Add test to CTest
include(GoogleTest)
gtest_discover_tests(VideoProcessorTest)