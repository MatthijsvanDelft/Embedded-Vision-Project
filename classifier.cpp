#include "classifier.h"

Classifier::Classifier()
{

}

void Classifier::classifyCars()
{
    cv::Mat tmp = cv::Mat::zeros(image->size(), CV_8UC3);

    for(unsigned int i=0; i<contours->size(); i++){

        double contourArea = cv::contourArea(contours->at(i));

        if(contourArea > 50.0 && contourArea < 100.0){/// Minus
            carVector.push_back(Car());
            cv::drawContours(tmp , *contours, i, cv::Scalar(255,255,255), 2, 8, *hierarchy, 0, cv::Point());
            carVector.at(0).setImage(&tmp);
            carVector.at(0).setSymbol("Minus");
            cv::imshow("Car1", *carVector.at(0).getImage());;
        }
        else if(contourArea > 100.0 && contourArea < 130.0){/// Plus
            carVector.push_back(Car());
            cv::drawContours(tmp , *contours, i, cv::Scalar(255,255,255), 2, 8, *hierarchy, 0, cv::Point());
            carVector.at(1).setImage(&tmp);
            carVector.at(1).setSymbol("Plus");
            cv::imshow("Car2", *carVector.at(1).getImage());;
        }
    }
}

void Classifier::setImage(cv::Mat *im)
{
    image = im;
}

void Classifier::setContours(std::vector<std::vector<cv::Point>> *cont)
{
    contours = cont;
}

void Classifier::setHierarchy(std::vector<cv::Vec4i> *hier)
{
    hierarchy = hier;
}
