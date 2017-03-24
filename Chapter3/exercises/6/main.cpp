#include "cv.h"
#include "highgui.h"

int main(int argc, const char** argv)
{
    IplImage *src = cvLoadImage("result1.png",0);


    IplImage* dst1 = cvCreateImageHeader(cvSize(20,30),src->depth,src->nChannels);


    IplImage* dst2 = cvCreateImageHeader(cvSize(20,30),src->depth,src->nChannels);

    dst1->origin = src->origin;
    dst2->origin = src->origin;
    dst1->widthStep = src->widthStep;
    dst2->widthStep = src->widthStep;

    dst1->imageData = src->imageData + 10 * src->widthStep + 5 * src->nChannels;
    dst2->imageData = src->imageData + 60 * src->widthStep + 50 * src->nChannels;
    cvNot(dst1, dst1);
    cvNot(dst2, dst2);


    cvNamedWindow("src", 1);
    cvShowImage("src", src);
    cvWaitKey(0);

    cvReleaseImage(&src);
    cvReleaseImage(&dst1);
    cvReleaseImage(&dst2);
    cvDestroyWindow("src");
    return 0;
}
