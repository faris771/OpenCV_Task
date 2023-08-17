#include <iostream>
#include <time.h>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

#include "frame_operations.h"


int main() {


    cv::VideoCapture cap(0);

    cv::Mat blueFrame, originalFrame, nonBlueFrame, grayFrame, fpsFrame, logoFrame, mirrorFrame;

    cv::Mat splitChannelsForNonBlue[3], splitChannelsForGray[3]; // BRG




    // Track time elapsed for computing FPS
    time_t startTime, curTime;

    time(&startTime);

    int numFramesCaptured = 0;
    double secElapsed;
    double curFPS;

    while (true) {


        cap.read(originalFrame);
        cv::resize(originalFrame, originalFrame, cv::Size(550, 320));


        cv::split(originalFrame, splitChannelsForGray);

        numFramesCaptured++;
        time(&curTime);
        secElapsed = difftime(curTime, startTime);
        curFPS = numFramesCaptured / secElapsed;

        fpsFrame = FrameOperations::makeFpsFrame(originalFrame, curFPS);
        blueFrame = FrameOperations::makeBlueFrame(originalFrame);
        nonBlueFrame = FrameOperations::makeNonBlueFrame(originalFrame);
        logoFrame = FrameOperations::makeLogoFrame(originalFrame);
        grayFrame = FrameOperations::makeGrayFrame(originalFrame);



        // mirror
        mirrorFrame = originalFrame.clone();

        cv::Mat upHalf = originalFrame.clone();
        cv::Mat downHalf;
        cv::flip(upHalf, downHalf, 0);
        cv::resize(upHalf, upHalf, cv::Size(upHalf.cols, upHalf.rows / 2));
        cv::resize(downHalf, downHalf, cv::Size(downHalf.cols, downHalf.rows / 2));
        cv::vconcat(upHalf, downHalf, mirrorFrame);


        std::vector<cv::Mat> col1 = {fpsFrame, nonBlueFrame, grayFrame};
        std::vector<cv::Mat> col2 = {blueFrame, logoFrame, mirrorFrame};


        cv::Mat out1;
        cv::Mat out2;
        cv::Mat out;


        cv::vconcat(col1, out1);
        cv::vconcat(col2, out2);
        cv::hconcat(out1, out2, out);


        cv::imshow("tst", out);


        cv::waitKey(1);

    }


    return 0;

}
