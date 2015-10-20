#ifndef GRABBER_H
#define GRABBER_H

#include "opencv/cv.h"
#include "opencv/highgui.h"
#include "opencv2/opencv.hpp"
#include "logger.h"

#define WIDTH 640
#define HEIGHT 480

/*! \class Grabber class
    \brief Grabber grabs an image and different information of that image and returns it.
*/
class Grabber
{
private:
    void readImage(cv::Mat *image);

    cv::VideoCapture cap;
    cv::VideoCapture trackCap;
    cv::VideoCapture finishCap;
    cv::Mat trackImage;
    cv::Mat finishImage;
    cv::Mat image;

public:
    Grabber();

    cv::Mat *getTrackImage();
    cv::Mat *getFinishImage();
    cv::Mat *getImage();

protected:

};

#endif // GRABBER_H
