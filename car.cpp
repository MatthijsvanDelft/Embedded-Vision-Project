#include "car.h"

Car::Car(QString sym)
{
    symbol = sym;
}

unsigned int Car::getLaps()
{
    return laps;
}

void Car::setLaps(unsigned int lps)
{
    laps = lps;
}
