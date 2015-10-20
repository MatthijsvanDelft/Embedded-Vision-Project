#include "grabber.h"

/** Grabber()
 *  \brief Constructor of Grabber.
 */
Grabber::Grabber() : cap(0), trackCap("/Users/Mike/Desktop/Testafbeeldingen Vision/TrackFilled.png"), finishCap("/Users/Mike/Desktop/Testafbeeldingen Vision/StartFinish.png")
{
    if(!cap.isOpened()){
        Logger::log()->error("Video capture is closed");
    }

    ///Set format of stream
    cap.set(CV_CAP_PROP_FRAME_HEIGHT, HEIGHT);
    cap.set(CV_CAP_PROP_FRAME_WIDTH, WIDTH);
    Logger::log()->info("Frame height & width is set");
}

/** readImage()
 *  \brief readImage() reads the image.
 *  \param *image or adres to a cv::Mat object where the image has to be stored.
 */
void Grabber::readImage(cv::Mat *image)
{
    ///Get a new raw image from camera
    cap >> *image;

    ///Check if image is empty
    if(image->empty()){
        Logger::log()->error("Image is empty");
    }
}

/** getTrackImage()
 *  \return getTrackImage() returns a pointer to the image file.
 */
cv::Mat *Grabber::getTrackImage()
{
    //readImage(&trackImage);
    trackCap >> trackImage;


    Logger::log()->info("Track is succesfully scanned");
    return &trackImage;
}

/** getFinishImage()
 *  \return getFinishImage() returns a pointer to the image file.
 */
cv::Mat *Grabber::getFinishImage()
{
    //readImage(&trackImage);
    finishCap >> finishImage;

    if(finishImage.empty()){
        Logger::log()->warn("Finish mask cannot be opened!");
    }
    else{
    Logger::log()->info("Finish is succesfully scanned");

    /// Convert image to grayscale image.
    cv::cvtColor(finishImage, finishImage, CV_RGB2GRAY);

    /// Convert grayscale image to binaire image;
    cv::threshold(finishImage, finishImage, 230, 255, cv::THRESH_BINARY);
    }
    return &finishImage;
}

/** getImage()
 *  \return getImage() returns a pointer to the image file.
 */
cv::Mat *Grabber::getImage()
{
    readImage(&image);
    return &image;
}
