#include "dip.h"

/** DIP()
 *  \brief Constructor of DIP
 */
DIP::DIP()
{
    ///
    /// Allocate memory for two object of cv::Mat.
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
    cv::threshold(*enhcTrackImage, *enhcTrackImage, threshold, 255, cv::THRESH_BINARY);
}

/** makeGrayscale()
 *  \brief Creates binary image fom normal images.
 */
void DIP::calcImageMask()
{
    /// Convert image to grayscale image.
    cv::cvtColor(*image, *enhcImage, CV_RGB2GRAY);

    /// Convert grayscale image to binaire image;
    cv::threshold(*enhcImage, *enhcImage, threshold, 255, cv::THRESH_BINARY);

    /// Adaptive Thresholding
    //cv::adaptiveThreshold(*enhcImage, *enhcImage, 255, CV_ADAPTIVE_THRESH_GAUSSIAN_C, CV_THRESH_BINARY, 75, 25);
}

/** drawContours()
 *  \brief Draw contours in contImage.
 */
void DIP::drawContour()
{
    /// Find Contours
    cv::findContours(*enhcImage, contours, hierarchy, CV_RETR_TREE, CV_CHAIN_APPROX_SIMPLE, cv::Point(0, 0));

    /// Clear enhcImage
    *enhcImage = cv::Mat::zeros(enhcImage->size(), CV_8UC3);

    /// Draw all the contours in enhcImage
    for(unsigned long i = 0; i< contours.size(); i++){
            cv::drawContours(*enhcImage, contours, i, cv::Scalar(255,255,255), 2, 8, hierarchy, 0, cv::Point());
        }
}

/** setThreshold
 *  @brief Sets threshold value.
 *  @param unsigned integer thres.
 */
void DIP::setThreshold(unsigned int thres)
{
    threshold = thres;
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

    Logger::log()->info("TrackMask is succesfully created");
    return enhcTrackImage;
}

/** getEnhancedImage()
 *  \return Returns pointer to enhanced image.
 */
cv::Mat *DIP::getEnhancedImage()
{
    /// Calculates mask for image.
    calcImageMask();

    /// Calulates and draw countours in the image.
    drawContour();

    return enhcImage;
}

/** getContours()
 *  \return Returns pointer to vector contours.
 */
std::vector<std::vector<cv::Point>> *DIP::getContour()
{
    return &contours;
}

/** getHierarchy()
 *  \return Returns pointer to vector hierarchy.
 */
std::vector<cv::Vec4i> *DIP::getHierarchy()
{
    return &hierarchy;
}


