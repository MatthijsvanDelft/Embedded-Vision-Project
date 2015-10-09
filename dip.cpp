#include "dip.h"

/** DIP()
 *  \brief Constructor of DIP
 */
DIP::DIP()
{
    ///Allocate memory for two object of cv::Mat.
    enhcImage = new cv::Mat;
    enhcTrackImage = new cv::Mat;
}

/** ~DIP()
 *  \brief Destructor of DIP
 */
DIP::~DIP()
{
    /// Deletes allocated memory.
    delete enhcImage;
    delete enhcTrackImage;
}

/** calcTrackMask()
 *  \brief Creates mask of racetrack image.
 */
void DIP::calcTrackMask()
{
    /// Convert image to grayscale image.
    cv::cvtColor(*trackImage, *enhcTrackImage, CV_RGB2GRAY);

    /// Convert grayscale image to binaire image;
    cv::threshold(*enhcTrackImage, *enhcTrackImage, 100, 255, cv::THRESH_BINARY);
}

/** makeGrayscale()
 *  \brief Creates binary image fom normal images.
 */
void DIP::calcImageMask()
{
    /// Convert image to grayscale image.
    cv::cvtColor(*image, *enhcImage, CV_RGB2GRAY);

    /// Convert grayscale image to binaire image;
    cv::threshold(*enhcImage, *enhcImage, 100, 255, cv::THRESH_BINARY);
}

/** calcBlobs()
 *  \brief Calculate blobs and put them into a vector.
 */
void DIP::calcBlobs()
{

}

/** setImage()
 *  \brief Sets the pointer pointing to the raw image.
 *  \param img pointer to cv::Mat image.
 */
void DIP::setImage(cv::Mat *img)
{
    image = img;
}

/** setTrackImage()
 *  \brief Sets the pointer pointing to raw racetrack image.
 *  \param *img pointer to cv::Mat image.
 */
void DIP::setTrackImage(cv::Mat *img)
{
    trackImage = img;
}

/** getTrackMasks()
 *  \return Returns pointer to track mask.
 */
cv::Mat *DIP::getTrackMask()
{
    /// Calculates mask for racetrack image.
    calcTrackMask();

    return enhcTrackImage;
}

/** getEnhancedImage()
 *  \return Returns pointer to enhanced image.
 */
cv::Mat *DIP::getEnhancedImage()
{
    /// Calculates mask for image.
    calcImageMask();

    return enhcImage;
}
