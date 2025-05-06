# RealTimeVision

A real-time video processing application built in modern C++ using OpenCV. This project demonstrates clean object-oriented design, basic computer vision techniques, and foundational system-level C++ concepts.

---

## 🎯 Features

* Real-time video processing from camera or stream
* Grayscale filter with Picture-in-Picture (PIP) overlay
* Blur filter with adjustable strength (trackbar UI)
* Edge detection filter using Canny algorithm
* Sepia tone filter using kernel transformation
* Modular OOP design using virtual methods
* Easy-to-extend filter architecture
* Unit-tested `applyFilter()` using Google Test

---

## 🛠️ Technologies

* C++17
* OpenCV 4.x
* CMake
* GoogleTest (for unit testing)
* Visual Studio / Ninja / Command Line build compatible

---

## 📂 Project Structure

```bash
RealTimeVision/
├── include/                # Header files (e.g., VideoProcessor.hpp)
├── src/                    # Implementation files (e.g., VideoProcessor.cpp)
├── main.cpp                # Main entry point
├── assets/                # Test assets (e.g., test_image.png)
├── tests/                 # Unit tests using GoogleTest
├── CMakeLists.txt         # Build configuration
├── README.md              # Project documentation
```

---

## 🚀 Getting Started

### 1. Clone the Repository

```bash
git clone https://github.com/maxtse25/Realtime-Vision.git
cd Realtime-Vision
```

### 2. Build the Project

```bash
mkdir build && cd build
cmake ..
cmake --build .
```

### 3. Run the Application

```bash
./RealTimeVision        # Linux/macOS
RealTimeVision.exe      # Windows
```

---

## 🧪 Run Unit Tests

```bash
# From inside build/ directory
ctest --output-on-failure
```

You can also directly run the test executable:

```bash
./tests/VideoProcessorTest      # Linux/macOS
.\tests\Debug\VideoProcessorTest.exe  # Windows
```

---

## 🎛️ Controls

* Press `g` – Grayscale
* Press `b` – Blur (adjustable)
* Press `e` – Edge Detection (Canny)
* Press `s` – Sepia tone
* Press `q` / `ESC` – Quit

---

## 📌 Roadmap

* [ ] Add face detection + face blur
* [ ] Implement filter switching with hotkeys
* [ ] Add FPS counter and performance stats
* [ ] Add video recording (via OpenCV VideoWriter)
* [ ] Live parameter sliders for filter tuning

---

## 🎓 Learning Highlights

* OOP architecture with polymorphism and virtual dispatch
* OpenCV real-time frame processing and GUI
* Modular system design for extensible filter plugins
* CMake build system with Google Test integration

---

## 📜 License

MIT License. See `LICENSE` file.

---

## 🙌 Acknowledgments

* [OpenCV](https://opencv.org/)
* [GoogleTest](https://github.com/google/googletest)
* All open-source contributors and C++ educators.
