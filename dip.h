#ifndef DIP_H
#define DIP_H

#include "opencv/highgui.h"
#include "opencv2/opencv.hpp"

//!  DIP class.
/*!
  DIP(Digital Image Processor) contains all functions for image enhancement, segmentation and feature extraction.
*/
class DIP
{
private:
    void calcBlobs();


public:
    DIP();
    cv::Mat *calcThreshold(cv::Mat *srcImage, int threshold, int maxValue);

protected:

};

#endif // DIP_H
