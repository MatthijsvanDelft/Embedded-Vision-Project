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
    void drawContour();

    cv::Mat *trackImage;
    cv::Mat *enhcTrackImage;
    cv::Mat *image;
    cv::Mat *enhcImage;

    unsigned int threshold;
    std::vector<std::vector<cv::Point>> contours;
    std::vector<cv::Vec4i> hierarchy;

public:
    DIP();
    ~DIP();
    void setThreshold(unsigned int thres);
    void setImage(cv::Mat *img);
    void setTrackImage(cv::Mat *img);
    cv::Mat *getTrackMask();
    cv::Mat *getEnhancedImage();
    std::vector<std::vector<cv::Point>> *getContour();
    std::vector<cv::Vec4i> *getHierarchy();

protected:

};

#endif // DIP_H
