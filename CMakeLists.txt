# CMakeLists.txt
cmake_minimum_required(VERSION 3.15)
project(RealTimeVision)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# OpenCV
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

# Include directories
include_directories(${OpenCV_INCLUDE_DIRS})

# Include project headers
include_directories(${CMAKE_SOURCE_DIR}/include)

# Source files
set(SOURCES
    main.cpp
    src/VideoProcessor.cpp
)

# Executable
add_executable(RealTimeVision ${SOURCES} "src/GrayscaleFilter.cpp" "src/BlurFilter.cpp" "src/EdgeDetectionFilter.cpp")
target_link_libraries(RealTimeVision PRIVATE ${OpenCV_LIBS})

# GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.12.1.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Add test directory
enable_testing()
add_subdirectory(tests)
