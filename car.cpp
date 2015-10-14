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

    /// Checks if keypoints is empty.
    if(keypoints.size() > 0){
        Logger::log()->warn("Keypoints is empty");

        /// Place keypoints coordinates in coor.
        coor = keypoints.at(0).pt;
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
