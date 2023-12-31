//
// Created by faris on 8/20/23.
//
#include <iostream>
#include <time.h>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "web_cam.h"
#include "frame_operations.h"

void WebCam::run() {


    cv::VideoCapture cap(this->index); // get index from constructor


    cv::Mat blueFrame, originalFrame, nonBlueFrame, grayFrame, fpsFrame, logoFrame, mirrorFrame, outPutFrame;



    // Track time elapsed for computing FPS
    time_t startTime, curTime;

    time(&startTime);

    int numFramesCaptured = 0;
    double secElapsed;
    double curFPS;

    while (true) {


        cap.read(originalFrame);
        cv::resize(originalFrame, originalFrame, cv::Size(550, 320));


        numFramesCaptured++;
        time(&curTime);
        secElapsed = difftime(curTime, startTime);
        curFPS = numFramesCaptured / secElapsed;

        fpsFrame = FrameOperations::makeFpsFrame(originalFrame, curFPS);

        blueFrame = FrameOperations::makeBlueFrame(originalFrame);
        nonBlueFrame = FrameOperations::makeNonBlueFrame(originalFrame);
        logoFrame = FrameOperations::makeLogoFrame(originalFrame);
        grayFrame = FrameOperations::makeGrayFrame(originalFrame);
        mirrorFrame = FrameOperations::makeMirrorFrame(originalFrame);

        std::vector<cv::Mat> col1 = {fpsFrame, nonBlueFrame, grayFrame};
        std::vector<cv::Mat> col2 = {blueFrame, logoFrame, mirrorFrame};

        outPutFrame = FrameOperations::makeOutPutFrame(col1, col2);

        cv::imshow("tst", outPutFrame);


        cv::waitKey(1);

    }

}
