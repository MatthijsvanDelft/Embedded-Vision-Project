#include "grabber.h"

/** Grabber()
 *  \brief Constructor of Grabber.
 */
Grabber::Grabber() : cap(0)
{
    if(!cap.isOpened()){
        Logger::log()->error("Video capture is closed");
    }

    ///Set format of stream
    cap.set(CV_CAP_PROP_FRAME_HEIGHT, HEIGHT);
    cap.set(CV_CAP_PROP_FRAME_WIDTH, WIDTH);
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
    readImage(&trackImage);
    return &trackImage;
}

/** getImage()
 *  \return getImage() returns a pointer to the image file.
 */
cv::Mat *Grabber::getImage()
{
    readImage(&image);
    return &image;
}
