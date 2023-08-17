#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <time.h>

#include <iostream>

int main() {


    cv::VideoCapture cap(0);

    cv::Mat originalFrame, blueFrame, nonBlueFrame, grayFrame, fpsFrame, logoFrame, mirrorFrame;

    cv::Mat splitChannelsForBlue[3], splitChannelsForNonBlue[3], splitChannelsForGray[3]; // BRG



    // Track time elapsed for computing FPS
    time_t startTime, curTime;

    time(&startTime);

    int numFramesCaptured = 0;
    double secElapsed;
    double curFPS;
    double averageFPS = 0.0;

    while (true) {


        cap.read(originalFrame);
        cv::resize(originalFrame, originalFrame, cv::Size(550, 320));

        cv::split(originalFrame, splitChannelsForBlue);
        cv::split(originalFrame, splitChannelsForNonBlue);
        cv::split(originalFrame, splitChannelsForGray);


        splitChannelsForBlue[1] = cv::Mat::zeros(splitChannelsForBlue[1].size(), CV_8UC1);
        splitChannelsForBlue[2] = cv::Mat::zeros(splitChannelsForBlue[2].size(), CV_8UC1);
        cv::merge(splitChannelsForBlue, 3, blueFrame);


        splitChannelsForNonBlue[0] = cv::Mat::zeros(splitChannelsForNonBlue[0].size(), CV_8UC1);
        cv::merge(splitChannelsForNonBlue, 3, nonBlueFrame);



        splitChannelsForGray[0] = cv::Mat::zeros(splitChannelsForGray[1].size(), CV_8UC1);
        splitChannelsForGray[1] = cv::Mat::zeros(splitChannelsForGray[1].size(), CV_8UC1);
        splitChannelsForGray[2] = cv::Mat::zeros(splitChannelsForGray[2].size(), CV_8UC1);


        cv::cvtColor(originalFrame, grayFrame, cv::COLOR_BGR2GRAY); //
        cv::cvtColor(grayFrame, grayFrame, cv::COLOR_GRAY2BGR);




        numFramesCaptured++;
        time(&curTime);
        secElapsed = difftime(curTime, startTime);
        curFPS = numFramesCaptured / secElapsed;


        // fps
        fpsFrame = originalFrame.clone();
        std::string fpsString = "FPS = " + std::to_string(curFPS);

        cv::putText(fpsFrame, fpsString, cv::Point(50, 50), cv::FONT_HERSHEY_DUPLEX, 1, cv::Scalar(0, 255, 0), 2,
                    false);


        logoFrame = originalFrame.clone();
        cv::Mat logoImage = cv::imread("../Resources/imagry.png");
        cv::resize(logoImage, logoImage, cv::Size(200, 100));
        cv::Rect roi(originalFrame.cols - logoImage.cols, originalFrame.rows - logoImage.rows, logoImage.cols, logoImage.rows);
        logoImage.copyTo(logoFrame(roi));


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
