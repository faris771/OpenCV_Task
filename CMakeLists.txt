cmake_minimum_required(VERSION 3.20)
project(OpenCV_Task)
find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})


add_executable(OpenCV_Task
        main.cpp
        Camera/frame_operations.cpp
        Camera/frame_operations.h
        Camera/web_cam.cpp
        Camera/web_cam.h
)
target_link_libraries(OpenCV_Task ${OpenCV_LIBS})
