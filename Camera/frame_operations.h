//
// Created by faris on 8/17/23.
//
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <time.h>

#include <iostream>
#pragma once


class FrameOperations {
public:

//    static cv::Mat makeFpsFrame(cv::Mat originalFrame, double curFPS);

//    static cv::Mat makeBlueFrame(cv::Mat originalFrame);

    static cv::Mat makeNonBlueFrame(cv::Mat originalFrame);

    static cv::Mat makeLogoFrame(cv::Mat originalFrame);

    static cv::Mat makeGrayFrame(cv::Mat originalFrame);

    static cv::Mat makeMirrorFrame(cv::Mat originalFrame);

    static cv::Mat makeFpsFrame(cv::Mat originalFrame, double curFPS);

    static cv::Mat makeBlueFrame(cv::Mat originalFrame);

    static cv::Mat makeOutPutFrame(std::vector<cv::Mat> col1, std::vector<cv::Mat> col2);




};

