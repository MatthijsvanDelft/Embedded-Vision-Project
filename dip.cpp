#include "dip.h"

/** DIP()
 * Constructor of DIP
 */

DIP::DIP()
{

}

/** calcBinaryImage()
 * Creates binary image fom normal images.
 */
cv::Mat *DIP::calcThreshold(cv::Mat *srcImage, int threshold, int maxValue)
{
    cv::Mat *tmpImage;

    ///Convert the image to grayscale image
    cvtColor(*srcImage, *tmpImage, CV_RGB2GRAY);

    ///Calculate threshold image
    cv::threshold(*tmpImage, *tmpImage, threshold, maxValue, cv::THRESH_BINARY);

    return tmpImage;
}

/** calcBlobs()
 * Calculate blobs and put them into a vector.
 */
void DIP::calcBlobs()
{

}
