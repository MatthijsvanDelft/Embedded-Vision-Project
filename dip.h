#ifndef DIP_H
#define DIP_H

#include "opencv/highgui.h"
#include "opencv2/opencv.hpp"

/*! \class DIP class
    \brief DIP(Digital Image Processor) contains all functions for image enhancement, segmentation and feature extraction.
*/
class DIP
{
private:
    void makeGrayscale(cv::Mat *srcImage);
    void calcThreshold(cv::Mat *srcImage, int threshold, int maxValue);
    void calcBlobs();

    cv::Mat enhcImage;


public:
    DIP();
    cv::Mat *getEnhancedImage();

protected:

};

#endif // DIP_H
