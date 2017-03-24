#include "cv.h"
#include "opencv2/highgui/highgui.hpp"
#define MIN_VAL 2
#define MAX_VAL 8

IplImage* doPyrDown(IplImage* in, int size, int filter=IPL_GAUSSIAN_5x5){

  IplImage* out= cvCreateImage(cvSize(in->width/2,in->height/2),in->depth,in->nChannels);
  cvPyrDown(in, out);

  return out;
}
CvCapture* cap;
void onTrackbarSlide(int pos){

  cvSetCaptureProperty(cap,CV_CAP_PROP_POS_FRAMES,pos);
}
int g_silder_position = MIN_VAL;
int main(int argc, char** argv){
  cap = cvCreateCameraCapture(0);
  assert(cap!=NULL);


  IplImage* bgr_frame;
  cvNamedWindow("exercise5");
  cvCreateTrackbar("Po", "exercise5", &g_silder_position, MAX_VAL, onTrackbarSlide);
  while((bgr_frame = cvQueryFrame(cap))!=NULL){

    if(g_silder_position<2)g_silder_position = 2;
    IplImage* output = doPyrDown(bgr_frame,g_silder_position);
    cvShowImage("exercise5", output);

    if(cvWaitKey(33)==27)break;
  }

  cvReleaseCapture(&cap);
  cvDestroyWindow("exercise5");


  return 0;
}
