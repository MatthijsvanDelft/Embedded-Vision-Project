#ifndef HANDLER_H
#define HANDLER_H

#include <QObject>
#include <QTime>
#include <QTimer>
#include <sstream>
#include "dip.h"
#include "grabber.h"
#include "logger.h"
#include "mainwindow.h"

#include "opencv/cv.h"
#include "opencv/highgui.h"
#include "opencv2/opencv.hpp"

//!  Handler class.
/*!
  Handler connects classes en handles process.
*/
class Handler : public QObject
{
    Q_OBJECT
private:
    void startTime(QTime &time);
    void restartTime(QTime &time);
    QString checkTime(const QTime &time);

    DIP dip;
    Grabber grabber;
    Logger logger;
    MainWindow mainwindow;
    QTime elapsedTime;
    QTimer timer;

public:
    Handler();

protected:

private slots:
    void startSampling();
    void runSampling();
    void stopSampling();
};

#endif // HANDLER_H
