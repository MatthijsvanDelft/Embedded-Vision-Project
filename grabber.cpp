#include "grabber.h"

/** Grabber()
 * Constructor of Grabber.
 */
Grabber::Grabber() : cap(0)
{
    ///Set format of stream
    cap.set(CV_CAP_PROP_FRAME_HEIGHT, 480);
    cap.set(CV_CAP_PROP_FRAME_WIDTH, 640);
}

/** readImage()
 * readImage() reads the image and seprates the file and different information into objects.
 */
void Grabber::readImage()
{
    ///Get a new raw image from camera
    cap >> rawImage;
}

/** getImage()
 * getImage() returns a pointer to the image file.
 */
cv::Mat *Grabber::getImage()
{
    readImage();
    return &rawImage;
}
