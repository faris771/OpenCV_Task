cmake_minimum_required(VERSION 3.20)
project(OpenCV)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})


add_executable(OpenCV
        main.cpp
        Camera/frame_operations.cpp
        Camera/frame_operations.h
        Camera/web_cam.cpp
        Camera/web_cam.h
)
target_link_libraries(OpenCV ${OpenCV_LIBS})
