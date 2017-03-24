#include "cv.h"
#include "opencv2/highgui/highgui.hpp"


IplImage* doPyrDown(IplImage* in, int filter=IPL_GAUSSIAN_5x5){

  IplImage* out= cvCreateImage(cvSize(in->width/2,in->height/2),in->depth,in->nChannels);
  cvPyrDown(in, out);

  return out;
}

int main(int argc, char** argv){
  CvCapture* cap = cvCreateCameraCapture(0);
  assert(cap!=NULL);

  CvSize size = cvSize((int)cvGetCaptureProperty(cap, CV_CAP_PROP_FRAME_WIDTH),
                       (int)cvGetCaptureProperty(cap, CV_CAP_PROP_FRAME_HEIGHT));
  double fps = cvGetCaptureProperty(cap,CV_CAP_PROP_FPS);
  CvVideoWriter* writer = cvCreateVideoWriter(argv[2], CV_FOURCC('M','J','P','G'),fps,size);
  IplImage* bgr_frame;

  cvNamedWindow("exercise4");
  while((bgr_frame = cvQueryFrame(cap))!=NULL){
    IplImage* output = doPyrDown(bgr_frame);
    cvShowImage("exercise4", output);
    if(cvWaitKey(33)==27)break;
    cvWriteFrame(writer, output);
  }

  cvReleaseCapture(&cap);
  cvReleaseVideoWriter(&writer);


  return 0;
}
