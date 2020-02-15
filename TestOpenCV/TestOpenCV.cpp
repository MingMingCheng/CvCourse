#include <iostream>

#include <opencv2/opencv.hpp> 
#define CV_VERSION_ID CVAUX_STR(CV_MAJOR_VERSION) CVAUX_STR(CV_MINOR_VERSION) CVAUX_STR(CV_SUBMINOR_VERSION)
#define cvLIB(name) lnkLIB("opencv_" name CV_VERSION_ID)


#ifdef _DEBUG
#define lnkLIB(name) name "d"
#else
#define lnkLIB(name) name
#endif

#pragma comment(lib, cvLIB("world"))
//#pragma comment( lib, cvLIB("core"))
//#pragma comment( lib, cvLIB("imgproc"))
//#pragma comment( lib, cvLIB("highgui"))
//#pragma comment(lib, cvLIB("imgcodecs"))
using namespace cv;


int main()
{
    Mat img(200, 600, CV_8UC1);
    Mat one = Mat::ones(200, 1, CV_8U);
    for (int c = 0; c < img.cols; c++)
        img.col(c) = one * (c * 255/img.cols) ;

    cv::Mat turbo;
    cv::applyColorMap(img, turbo, cv::COLORMAP_TURBO);
    cv::imwrite("colorscale_turbo.png", turbo);

    imshow("Color map", turbo);
    waitKey(0);
}
