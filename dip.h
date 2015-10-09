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
    void calcImageMask();
    void calcTrackMask();
    void calcBlobs();

    cv::Mat *trackImage;
    cv::Mat *enhcTrackImage;
    cv::Mat *image;
    cv::Mat *enhcImage;

public:
    DIP();
    ~DIP();
    void setImage(cv::Mat *img);
    void setTrackImage(cv::Mat *img);
    cv::Mat *getTrackMask();
    cv::Mat *getEnhancedImage();

protected:

};

#endif // DIP_H
