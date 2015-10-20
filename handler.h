#ifndef HANDLER_H
#define HANDLER_H

#include <QObject>
#include <QTime>
#include <QTimer>
#include <sstream>
#include "classifier.h"
#include "dip.h"
#include "grabber.h"
#include "logger.h"
#include "mainwindow.h"

#include "opencv/cv.h"
#include "opencv/highgui.h"
#include "opencv2/opencv.hpp"

/*! \class Handler class
    \brief Handler connects classes en handles process.
*/
class Handler : public QObject
{
    Q_OBJECT
private:
    void startTime(QTime &time);
    void restartTime(QTime &time);
    QString checkTime(const QTime &time);

    Classifier classifier;
    DIP dip;
    Grabber grabber;
    MainWindow mainwindow;
    QTime elapsedTime;
    QTimer timer;
    cv::Mat *trackMask;
    cv::Mat *finishMask;
    void checkPosCar();
    void checkFinish();
    bool toggleLap;
    bool onFinish;

public:
    Handler();

protected:

private slots:
    void determineTrackMask();
    void determineStartFinishMask();
    void startSampling();
    void runSampling();
    void stopSampling();
};

#endif // HANDLER_H
