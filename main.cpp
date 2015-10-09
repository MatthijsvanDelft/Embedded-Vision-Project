#include "handler.h"
#include "logger.h"
#include <QApplication>

INITIALIZE_EASYLOGGINGPP

/*! \mainpage EngiRacing
 * This project is part of a bigger project called EngiRacing made for the HAN University of Applied Science.
 * For more information read the documentation about Engiracing.
 * This program foccuses on vision part of EngiRacing. This system has to measure lap times of the cars using a webcam.
 *  \author Made by Matthijs van Delft & Mike van Eerd from the study Embedded Systems Engineering.
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Handler handler;

    return a.exec();
}
