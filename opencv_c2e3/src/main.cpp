#include <iostream>
#include <opencv/highgui.h>
#include <opencv/cv.h>
using namespace std;

IplImage* dragSize(IplImage * img, int g_slide){
    int i = g_slide+1;
    IplImage* src1 = cvCreateImage(cvSize(img->width, img->height), img->depth, img->nChannels);
    IplImage* src2 = cvCreateImage(cvSize(img->width, img->height), img->depth, img->nChannels);
    cvCopy(img, src1);
    cvCopy(img, src2);
    for (; i > 1; i--)
    {
        if (i % 2 == 0){
            src2 = cvCreateImage(cvSize(src1->width / 2, src1->height / 2), src1->depth, src1->nChannels);
            cvPyrDown(src1, src2);
        }
        if (i % 2 != 0){
            src1 = cvCreateImage(cvSize(src2->width / 2, src2->height / 2), src2->depth, src2->nChannels);
            cvPyrDown(src2, src1);
        }
    }
    cvShowImage("test", src2);
}
IplImage* doCryDown(IplImage* in, int filter, int s){
  assert(in->width %2 == 0 && in->height %2 ==0);

  IplImage* out = cvCreateImage(cvSize(in->width/2, in->height/2), in->depth, in->nChannels);

  cvPyrDown(in, out);
  return out;

}
CvCapture* capture = 0;
void onTrackerslide(int pos){

}
int g_position = 2;
int main(int argc, char* argv[]){

  cvNamedWindow("exam", CV_WINDOW_AUTOSIZE);
  IplImage* frame = 0;

  capture = cvCreateFileCapture(argv[1]);

  CvSize size = cvSize((int)cvGetCaptureProperty(capture,CV_CAP_PROP_FRAME_WIDTH),
                      (int)cvGetCaptureProperty(capture,CV_CAP_PROP_FRAME_HEIGHT));

  double fps = cvGetCaptureProperty(capture, CV_CAP_PROP_FPS);
  int count = cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_COUNT);
  if(count!=0)
  {
    cvCreateTrackbar(
        "scalar",
        "exam",
        &g_position,
        8,
        onTrackerslide
    );
  }

  while((frame = cvQueryFrame(capture))!=NULL){

    IplImage* temp = dragSize(frame, g_position); //doCryDown(frame, IPL_GAUSSIAN_5x5,g_position);

    cvShowImage("exam" , temp);
    cout<<g_position<<endl;
    char c = cvWaitKey(33);
    if(c == 27) break;
  }
  cvDestroyWindow("exam");
  cvReleaseCapture(&capture);
  return 0;
}
