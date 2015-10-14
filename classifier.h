#ifndef CLASSIFIER_H
#define CLASSIFIER_H
#include "car.h"
#include "opencv2/opencv.hpp"
#include <vector>

/*! \class Classifier class
    \brief Classifier contains all functions for image enhancement, segmentation and feature extraction.
*/
class Classifier
{
private:
    void classifyCars();

    std::vector<Car> carVector;
    std::vector<std::vector<cv::Point>> *contours;

public:
    Classifier();
    void setContours(std::vector<std::vector<cv::Point> > *cont);

protected:

};

#endif // CLASSIFIER_H
