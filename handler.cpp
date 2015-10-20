#include "handler.h"

#define SAMPLING_TIMER 33

using namespace std;

/** Handler()
 *  \brief Constructor of Handler and starts main window.
 */
Handler::Handler()
{
    /// Setting for main window and opening of the main window.
    mainwindow.setWindowTitle("EngiRacing");
    mainwindow.setFixedSize(350,400);
    mainwindow.show();

    //test

    /// Connect the functionalty of a pushbutton to a member function from this class.
    connect(mainwindow.pbReadTrack, SIGNAL(clicked(bool)), this, SLOT(determineTrackMask()));
    connect(mainwindow.pbReadTrack, SIGNAL(clicked(bool)), this, SLOT(determineStartFinishMask()));
    connect(mainwindow.pbStartSampling, SIGNAL(clicked(bool)), this, SLOT(startSampling()));
    connect(mainwindow.pbStopSampling, SIGNAL(clicked(bool)), this, SLOT(stopSampling()));

    /// When timer reaches SAMPLING_TIMER call function runSampling()
    connect(&timer, SIGNAL(timeout()), this, SLOT(runSampling()));
}

/** determineTrackMask()
 *  \brief Determines the mask for the racetrack.
 */
void Handler::determineTrackMask()
{
    /// Logs start of determening the tack.
    mainwindow.setDisplayText("Determine track process");
    Logger::log()->info("Determine track process");

    /// Sets threshold from slider value.
    dip.setThreshold(mainwindow.thresSlider->value());

    /// Get pointer of track image and gives it to class DIP.
    dip.setTrackImage(grabber.getTrackImage());

    /// Returns the racetrack mask.
    trackMask = dip.getTrackMask();

    ///Display racetrack mask.
    cv::imshow("Track mask", *trackMask);
}

/** determineStartFinishMask()
 * \brief Determines the mask for the start finish
 */
void Handler::determineStartFinishMask(){
    ///Get pointer of start/finish image
    finishMask = grabber.getFinishImage();
}

/** startSampeling()
 *  \brief Starts the process of taking frames and procesing.
 */
void Handler::startSampling()
{
    ///Logs start of process in window and log file.
    mainwindow.setDisplayText("Start sampling process");
    Logger::log()->info("Start sampling process");

    ///Starts elapsedTimer.
    startTime(elapsedTime);

    ///Starts SAMPLING_TIMER timer.
    timer.start(SAMPLING_TIMER);
}

/** runSampling()
 *  \brief While loop sampling.
 */
void Handler::runSampling()
{
    /// Restart elapsedTimer
    restartTime(elapsedTime);

    /// Sets threshold from slider value.
    dip.setThreshold(mainwindow.thresSlider->value());

    /// Get pointer of image and gives it to class DIP.
    dip.setImage(grabber.getImage());

    ///
    cv::Mat *enhcImage = dip.getEnhancedImage();

    /// Get pointer of contour vector, hiercary and image and gives it to class classifier.
    classifier.setContours(dip.getContour());
    classifier.setHierarchy(dip.getHierarchy());
    classifier.setImage(dip.getEnhancedImage());

    ///
    classifier.classifyCars();

    checkPosCar();

    checkFinish();

    ///Display rawImage.
    cv::imshow("Video stream", *enhcImage);
    cv::moveWindow("Video stream", 0, 0);

    ///Display elapsedTime.
    //mainwindow.setDisplayText(checkTime(elapsedTime));
}

/** stopSampeling()
 *  \brief Stop the process of taking frames and procesing.
 */
void Handler::stopSampling()
{
    ///Logs end of process in window and log file.
    mainwindow.setDisplayText("Stop sampling process");
    Logger::log()->info("Stop sampling process");

    ///Stop timer.
    timer.stop();

    ///Closes all opencv windows.
    cv::destroyAllWindows();
}

/** startTime()
 *  \brief Starts timer.
 */
void Handler::startTime(QTime &time)
{
    time.start();
}

/** restartTime()
 * \brief Restarts timer.
 */
void Handler::restartTime(QTime &time)
{
    time.restart();
}

/** checkTime()
 *  \return elpased time in sting
 */
QString Handler::checkTime(const QTime &time)
{
    stringstream ss;
    QString s;

    ss << "Elapsed time: " << time.elapsed() << "ms";
    s = QString::fromStdString(ss.str());

    return s;
}

/** checkFinish()
 *  \brief check if car is on start/finish, if so start/restart timer.
 */
void Handler::checkFinish(){
    static bool toggleLap = false;
    static bool onFinish;
    std::vector<Car> *tempCarVector = classifier.getCars();

    QString sLaptime;
    int tmp = finishMask->at<uchar>(tempCarVector->at(0).getCoordinates());

    /// Check if car is on start/finish
    if(tmp > 0){
        Logger::log()->info("Car passed Start/finish!");

        /// Check if timer already runs & anti dender
        if(toggleLap == false && onFinish == false){
            tempCarVector->at(0).startLapTime();
            toggleLap = true;
            onFinish = true;
        }
        else if(toggleLap == true && onFinish == false){

            sLaptime = tempCarVector->at(0).getLapTime();
            tempCarVector->at(0).resetLapTime();
            mainwindow.setDisplayText(sLaptime);
            toggleLap = false;
        }
    }
    else{
        onFinish = false;
    }
}

/** checkPosCar()
 *  \brief check if car is on track, if not diskwalify car.
 */
void Handler::checkPosCar(){
    std::vector<Car> *tempCarVector = classifier.getCars();

    int tmp = trackMask->at<uchar>(tempCarVector->at(0).getCoordinates());

    /// Check if car is in or outside the track
    if(tmp == 0){
        mainwindow.setDisplayText("Car is outside the track");

        /// Set that car 0 is disqualified.
        tempCarVector->at(0).setDsqStatus(true);
    }
}
