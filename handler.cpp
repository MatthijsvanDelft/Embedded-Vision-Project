#include "handler.h"

using namespace std;

/** Handler()
 * Constructor of Handler and starts main window.
 */
Handler::Handler()
{
    ///Setting for main window and opening of the main window
    mainwindow.setWindowTitle("EngiRacing");
    mainwindow.setFixedSize(300,350);
    mainwindow.show();

    ///Connect the functionalty of a pushbutton to a member function from this class
    connect(mainwindow.pbStartSampling, SIGNAL(clicked(bool)), this, SLOT(startSampling()));
    connect(mainwindow.pbStopSampling, SIGNAL(clicked(bool)), this, SLOT(stopSampling()));

    ///When timer reaches 33ms call function runSampling()
    connect(&timer, SIGNAL(timeout()), this, SLOT(runSampling()));
}

/** startSampeling()
 * Starts the process of taking frames and procesing.
 */
void Handler::startSampling()
{
    mainwindow.setDisplayText("Start sampling process");

    ///Starts elapsedTimer
    startTime(elapsedTime);

    ///Starts 33ms timer
    timer.start(33);
}

/** runSampling()
 * While loop sampling
 */
void Handler::runSampling()
{
    ///Restart elapsedTimer
    restartTime(elapsedTime);

    ///Read image in IplImage pointer image and time this
    cv::Mat *srcImage = grabber.getImage();//grabber.getImage();
    cv::Mat *tmpImage = NULL;

    ///Check if rawImage is empty
    if(srcImage->empty()){
        mainwindow.setDisplayText("Image is empty");
    }

    ///Calculate threshold
    tmpImage = dip.calcThreshold(srcImage, 150, 255);

    ///Display rawImage
    cv::imshow("Video stream", *srcImage);
    cv::moveWindow("Video stream", 0, 0);

    ///Display elapsedTime
    mainwindow.setDisplayText(checkTime(elapsedTime));
}

/** stopSampeling()
 * Stop the process of taking frames and procesing.
 */
void Handler::stopSampling()
{
    mainwindow.setDisplayText("Stop sampling process.");

    ///Stop timer
    timer.stop();

    ///Closes all opencv windows
    cv::destroyAllWindows();
}

/** startTime()
 * Starts timer.
 */
void Handler::startTime(QTime &time)
{
    time.start();
}

/** restartTime()
 * Restarts timer.
 */
void Handler::restartTime(QTime &time)
{
    time.restart();
}

/** checkTime()
 * Checks how much time has elapsed and return this in QString
 */
QString Handler::checkTime(const QTime &time)
{
    stringstream ss;
    QString s;

    ss << "Elapsed time: " << time.elapsed() << "ms";
    s = QString::fromStdString(ss.str());

    return s;
}

