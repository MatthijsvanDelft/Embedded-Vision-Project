#include "classifier.h"

Classifier::Classifier()
{

}

void Classifier::classifyCars()
{
    for(int i=0; i<contours->size(); i++){
        double contourArea = cv::contourArea(contours->at(i));
    }
    //carVector.push_back();
}

void Classifier::setContours(std::vector<std::vector<cv::Point>> *cont)
{
    contours = cont;
}
