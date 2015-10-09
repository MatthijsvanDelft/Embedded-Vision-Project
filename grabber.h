#ifndef GRABBER_H
#define GRABBER_H

#include "opencv/cv.h"
#include "opencv/highgui.h"
#include "opencv2/opencv.hpp"

#include "logger.h"

/*! \class Grabber class
    \brief Grabber grabs an image and different information of that image and returns it.
*/
class Grabber
{
private:
    void readImage(cv::Mat *image);

    cv::VideoCapture cap;
    cv::Mat trackImage;
    cv::Mat image;

public:
    Grabber();

    cv::Mat *getTrackImage();
    cv::Mat *getImage();

protected:

};

#endif // GRABBER_H
