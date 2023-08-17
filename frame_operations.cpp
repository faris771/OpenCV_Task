//
// Created by faris on 8/17/23.
//

#include "frame_operations.h"

cv::Mat FrameOperations::makeFpsFrame( cv::Mat originalFrame, double curFPS) {

    cv::Mat fpsFrame = originalFrame.clone();

    std::string fpsString = "FPS = " + std::to_string(curFPS);

    cv::putText(fpsFrame, fpsString, cv::Point(50, 50), cv::FONT_HERSHEY_DUPLEX, 1, cv::Scalar(0, 255, 0), 2,
                false);


    return fpsFrame;


}

cv::Mat FrameOperations::makeBlueFrame( cv::Mat originalFrame) {

    cv::Mat blueFrame;
    cv::Mat splitChannelsForBlue[3];

    cv::split(originalFrame, splitChannelsForBlue);
    splitChannelsForBlue[1] = cv::Mat::zeros(splitChannelsForBlue[1].size(), CV_8UC1);
    splitChannelsForBlue[2] = cv::Mat::zeros(splitChannelsForBlue[2].size(), CV_8UC1);
    cv::merge(splitChannelsForBlue, 3, blueFrame);


    return blueFrame;
}

cv::Mat FrameOperations::makeNonBlueFrame(cv::Mat originalFrame) {

    cv::Mat nonBlueFrame = originalFrame.clone();

    cv::Mat splitChannelsForNonBlue[3];
    cv::split(originalFrame, splitChannelsForNonBlue);
    splitChannelsForNonBlue[0] = cv::Mat::zeros(splitChannelsForNonBlue[0].size(), CV_8UC1);

    cv::merge(splitChannelsForNonBlue, 3, nonBlueFrame);


    return nonBlueFrame;

}

cv::Mat FrameOperations::makeLogoFrame(cv::Mat originalFrame) {

    cv::Mat logoFrame = originalFrame.clone();

    cv::Mat logoImage = cv::imread("../Resources/imagry.png");

    cv::resize(logoImage, logoImage, cv::Size(200, 100));
    cv::Rect roi(originalFrame.cols - logoImage.cols, originalFrame.rows - logoImage.rows, logoImage.cols,
                 logoImage.rows);
    logoImage.copyTo(logoFrame(roi));

    return logoFrame;
}

cv::Mat FrameOperations::makeGrayFrame(cv::Mat originalFrame) {
    cv::Mat grayFrame = originalFrame.clone();
    cv::cvtColor(originalFrame, grayFrame, cv::COLOR_BGR2GRAY); //
    cv::cvtColor(grayFrame, grayFrame, cv::COLOR_GRAY2BGR);


    return grayFrame;


}

cv::Mat FrameOperations::makeMirrorFrame(cv::Mat originalFrame) {

    cv::Mat mirrorFrame = originalFrame.clone();
    cv::Mat upHalf = originalFrame.clone();
    cv::Mat downHalf;
    cv::flip(upHalf, downHalf, 0);
    cv::resize(upHalf, upHalf, cv::Size(upHalf.cols, upHalf.rows / 2));
    cv::resize(downHalf, downHalf, cv::Size(downHalf.cols, downHalf.rows / 2));
    cv::vconcat(upHalf, downHalf, mirrorFrame);

    return mirrorFrame;
}

cv::Mat FrameOperations::makeOutPutFrame(std::vector<cv::Mat> col1, std::vector<cv::Mat> col2) {


    cv::Mat out1;
    cv::Mat out2;
    cv::Mat out;


    cv::vconcat(col1, out1);
    cv::vconcat(col2, out2);
    cv::hconcat(out1, out2, out);


    return out;

}
