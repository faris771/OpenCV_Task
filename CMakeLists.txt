cmake_minimum_required(VERSION 3.20)
project(OpenCV)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})


add_executable(OpenCV
        main.cpp
        frame_operations.cpp
        frame_operations.h
)
target_link_libraries(OpenCV ${OpenCV_LIBS})
