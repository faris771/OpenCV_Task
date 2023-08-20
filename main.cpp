#include <iostream>
#include <time.h>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "Camera/frame_operations.h"
#include "Camera/web_cam.h"


int main() {
    //run

    WebCam::run();

    return 0;

}
