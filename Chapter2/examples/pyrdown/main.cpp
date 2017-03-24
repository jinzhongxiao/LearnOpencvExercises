#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "cv.h"
IplImage* doPyrDown(IplImage* in, int filter = IPL_GAUSSIAN_5x5){

  //assert( in->width%2 ==0 && in->height%2 == 0);
  IplImage* out=  cvCreateImage(cvSize(in->width/2, in->height/2), in->depth, in->nChannels);

  cvPyrDown(in, out);

  return out;
}

IplImage* doCanny(IplImage* in, double lowThresh, double highThresh, double aperture){
  //if(in->nChannels != 1)return 0;

  IplImage* out = cvCreateImage(cvGetSize(in), IPL_DEPTH_8U, 1);


  cvCanny(in, out, lowThresh, highThresh, aperture);

  return out;

}


int main(int argc, char** argv){

  IplImage* in = cvLoadImage(argv[1]);

  IplImage* img1 = doPyrDown(in, IPL_GAUSSIAN_5x5);
  IplImage* img2 = doPyrDown(img1, IPL_GAUSSIAN_5x5);

  IplImage* img3 = doCanny(img2, 10 ,100, 3);

  cvNamedWindow("canny");
  cvShowImage("canny", img3);
  cvWaitKey(0);
  cvReleaseImage(&img1);
  cvReleaseImage(&img2);
  cvReleaseImage(&img3);


}
