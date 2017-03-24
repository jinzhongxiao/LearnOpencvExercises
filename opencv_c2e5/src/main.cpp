#include <iostream>
#include <opencv/highgui.h>
#include <opencv/cv.h>
using namespace std;


CvCapture* capture;
int g_slider_posotion  = 0;
int n;

void onTrackbarSlide(int pos){
  cvSetCaptureProperty(capture,
                      CV_CAP_PROP_POS_FRAMES,
                      pos);
}
//the 1st example
void vedioShow(char str[]);
void smooth(IplImage* in);
IplImage* doPyrDown(IplImage* in, int filter );
IplImage* doCanny(IplImage* in, double lowThreshold, double highThreshold, double aperture);
int main(int argc, char* argv[]){
  /*IplImage* in = cvLoadImage(argv[1]);

  IplImage* out =   doPyrDown(in,IPL_GAUSSIAN_5x5);

  out = doCanny(out, 10, 100, 3);
  cvNamedWindow("exam");
  cvShowImage("exam", out);

  cvWaitKey(0);

  cvReleaseImage(&out);
  cvDestroyWindow("exam");
  */

  CvCapture* capture = 0;
  capture = cvCreateFileCapture(argv[1]);
  if(!capture){return -1;}
  IplImage* bgr_frame = cvQueryFrame(capture);

  double fps = cvGetCaptureProperty(capture, CV_CAP_PROP_FPS);

  CvSize size = cvSize((int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH),
        (int)cvGetCaptureProperty(capture,CV_CAP_PROP_FRAME_HEIGHT));

  CvVideoWriter * writer =  cvCreateVideoWriter(argv[2], CV_FOURCC('M','J','P','G'),fps,size);

  IplImage* logpolar_frame = cvCreateImage(size, IPL_DEPTH_8U, 3);

  while((bgr_frame = cvQueryFrame(capture))!=NULL){
    cvLogPolar(bgr_frame, logpolar_frame, cvPoint2D32f(bgr_frame->width/2 , bgr_frame->height/2),
        40, CV_INTER_LINEAR+CV_WARP_FILL_OUTLIERS);
    cvWriteFrame(writer, bgr_frame);

  }

  cvReleaseImage(&logpolar_frame);
  cvReleaseVideoWriter(&writer);
  cvReleaseCapture(&capture);




  return 0;
}

//the 2nd example
void smooth(IplImage* in){
  cvNamedWindow("in");
  cvNamedWindow("out");

  cvShowImage("in", in);

  IplImage* out = cvCreateImage(cvGetSize(in), IPL_DEPTH_8U, 3);

  cvSmooth(in, out, CV_GAUSSIAN, 3,3);

  cvShowImage("out", out);

  cvReleaseImage(&out);

  cvWaitKey(0);

  cvDestroyWindow("in");
  cvDestroyWindow("out");
}


void vedioShow(char str[]){

  //IplImage* img = cvLoadImage(argv[1]);
  cvNamedWindow("Example1", 0);
  capture = cvCreateFileCapture(str);
  int frames = cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_COUNT);
  if(frames != 0){
    cvCreateTrackbar("Position", "Example1", &g_slider_posotion, frames, onTrackbarSlide);
  }
  IplImage* img;
  while(1){
    img = cvQueryFrame(capture);
    cvSetTrackbarPos("Position", "Example1", g_slider_posotion++);
    if(!img)break;
    cvShowImage("Example1", img);
    cout<<g_slider_posotion<<endl;
    char c = cvWaitKey(33);
    if(c == 27)break;


  }


  cvReleaseCapture(&capture);
  cvDestroyWindow("Example1");


}


IplImage* doPyrDown(IplImage* in, int filter){

  assert( in->width%2 == 0 && in->height % 2 ==0 );

  IplImage* out = cvCreateImage(cvSize(in->width/2, in->height/2), in->depth, in->nChannels);
  cvPyrDown(in, out);

  return out;
}


IplImage* doCanny(IplImage* in, double lowThreshold, double highThreshold, double aperture){
  if(in->nChannels != 1)return 0;

  IplImage* out=cvCreateImage((cvGetSize(in)), IPL_DEPTH_8U, 1);

  cvCanny(in, out, lowThreshold, highThreshold, aperture);

  return out;
}
