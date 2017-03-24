#include "opencv2/highgui/highgui.hpp"
//using namespace cv;
int main(int argc, char **argv){
  IplImage* img = cvLoadImage(argv[1]);
  cvNamedWindow("Example1", CV_WINDOW_AUTOSIZE);
  cvShowImage("Example1", img);
  cvWaitKey(0);
  cvReleaseImage(&img);
  cvDestroyWindow("Example1");
  return 0;
}
