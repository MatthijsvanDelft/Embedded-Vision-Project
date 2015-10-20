#include "car.h"

Car::Car()
{

}

void Car::calcCoordinates()
{

    /// Set up the detector with default parameters.
    cv::SimpleBlobDetector detector;

    /// Detect blobs.
    std::vector<cv::KeyPoint> keypoints;
    detector.detect(image, keypoints);
/*
    drawKeypoints( image, keypoints, image, CV_RGB(0,0,255), cv::DrawMatchesFlags::DEFAULT);
    cv::imshow("Car", image);*/
    /// Check if image is empty.
    if(image.data != 0){

    /// Checks if keypoints is empty.
    if(keypoints.empty()){
        Logger::log()->warn("Keypoints in calcCoordinates is empty");

    }
    else{
        /// Place keypoints coordinates in coor.
        coor = keypoints.at(0).pt;
        }
    }
    else{
        Logger::log()->warn("image in calcCoordinates is empty");
    }
}

cv::Point2f Car::getCoordinates()
{
    calcCoordinates();
    return coor;
}

unsigned int Car::getLaps()
{
    return laps;
}

void Car::setLaps(unsigned int lps)
{
    laps = lps;
}

void Car::setSymbol(QString s)
{
    symbol = s;
}

QString Car::getSymbol()
{
    return symbol;
}

void Car::setImage(cv::Mat *im)
{
    image = *im;
}

cv::Mat *Car::getImage()
{
    return &image;
}

void Car::startLapTime(){
    lapTime.start();
}

void Car::resetLapTime(){
    lapTime.restart();
}

QString Car::getLapTime(){
    std::stringstream ss;
    QString s;

    ss << "Laptime: " << lapTime.elapsed() << "ms";
    s = QString::fromStdString(ss.str());

    return s;
}
