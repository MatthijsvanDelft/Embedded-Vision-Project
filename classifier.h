#ifndef CLASSIFIER_H
#define CLASSIFIER_H
#include "car.h"
#include "opencv/highgui.h"
#include "opencv2/opencv.hpp"
#include <vector>

/*! \class Classifier class
    \brief Classifier contains all functions for image enhancement, segmentation and feature extraction.
*/
class Classifier
{
private:
    //void classifyCars();

    std::vector<Car> carVector;
    cv::Mat *image;
    std::vector<std::vector<cv::Point>> *contours;
    std::vector<cv::Vec4i> *hierarchy;

public:
    Classifier();
    void classifyCars();
    void setImage(cv::Mat *im);
    void setContours(std::vector<std::vector<cv::Point> > *cont);
    void setHierarchy(std::vector<cv::Vec4i> *hier);

protected:

};

#endif // CLASSIFIER_H
