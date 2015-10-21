#include "car.h"

/** Car()
 * @brief Constructor of car.
 */
Car::Car() : dsqStatus(false)
{

}

/** calcCoordinates()
 * @brief Calculates coordinates of car image with help of a simple blob detector.
 */
void Car::calcCoordinates()
{
    /// Set up the detector with default parameters.
    cv::SimpleBlobDetector detector;

    /// Detect blobs.
    std::vector<cv::KeyPoint> keypoints;
    detector.detect(image, keypoints);

//    drawKeypoints( image, keypoints, image, CV_RGB(0,0,255), cv::DrawMatchesFlags::DEFAULT);
//    cv::imshow("Car", image);

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

/** getCoordinates()
 * @return Returns coordinates in point with floats.
 */
cv::Point2f Car::getCoordinates()
{
    calcCoordinates();
    return coor;
}

/** getLaps()
 * @return Returns number of driven laps.
 */
unsigned int Car::getLaps()
{
    return laps;
}

/** setLaps()
 * @param Sets number of driven laps.
 */
void Car::setLaps(unsigned int lps)
{
    laps = lps;
}

/** getSymbol()
 * @return Returns symbol as Qstring.
 */
QString Car::getSymbol()
{
    return symbol;
}

/** setSymbol()
 * @param Sets symbol of car.
 */
void Car::setSymbol(QString s)
{
    symbol = s;
}

/** getImage()
 * @return Returns image of car.
 */
cv::Mat *Car::getImage()
{
    return &image;
}

/** setImage()
 * @param Sets car image.
 */
void Car::setImage(cv::Mat *im)
{
    image = *im;
}

/** getDsqStatus()
 * @return Returns disqualification status as boolean.
 */
bool Car::getDsqStatus()
{
    return dsqStatus;
}

/** setDsqStatus()
 * @param Sets disqualification statis.
 */
void Car::setDsqStatus(bool dsq)
{
    dsqStatus = dsq;
}

/** startLapTime()
 * @brief Start lap timer.
 */
void Car::startLapTime(){
    lapTime.start();
}

/** resetLapTime()
 * @brief Reset lap timer.
 */
void Car::resetLapTime(){
    lapTime.restart();
}

/** getLapTime()
 * @return Returns lap time as Qstring.
 */
QString Car::getLapTime(){
    std::stringstream ss;
    QString s;

    ss << "Laptime: " << lapTime.elapsed() << "ms";
    s = QString::fromStdString(ss.str());

    return s;
}
