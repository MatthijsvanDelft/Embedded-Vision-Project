#ifndef CAR_H
#define CAR_H
#include <QTime>
#include <QString>

/*! \class Car class
    \brief Car is a data class that contains all information about the object car.
*/
class Car
{
private:
    QString symbol;
    unsigned int team;
    QTime lapTime;
    unsigned int laps;
    unsigned int xCoor;
    unsigned int yCoor;

public:
    Car(QString sym);
    void setLaps(unsigned int lps);
    unsigned int getLaps();

protected:

};

#endif // CAR_H
