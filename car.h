#ifndef CAR_H
#define CAR_H
#include "logger.h"
#include "opencv2/opencv.hpp"
#include <QTime>
#include <QString>

#define WIDTH 640
#define HEIGHT 480

/*! \class Car class
    \brief Car is a data class that contains all information about the object car.
*/
class Car
{
private:
    void calcCoordinates();

    cv::Mat image;
    QString symbol;
    unsigned int team;
    QTime lapTime;
    unsigned int laps;
    cv::Point2f coor;

public:
    Car();

    cv::Point2f getCoordinates();
    void setImage(cv::Mat *im);
    cv::Mat *getImage();
    void setSymbol(QString s);
    QString getSymbol();
    void setLaps(unsigned int lps);
    unsigned int getLaps();

protected:

};

#endif // CAR_H
