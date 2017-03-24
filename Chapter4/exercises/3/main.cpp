#include <iostream>
#include "opencv2/core/core.hpp"

#include "cv.h"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;
using namespace std;
int xtemp,ytemp,xtemp2,ytemp2;
void my_mouse_callback(int event, int x, int y, int, void *data){
  Mat *t = (Mat*)(data);
  Mat cloneTemp = (*t).clone();
int x2,y2;
  if(event==EVENT_LBUTTONDOWN){
    xtemp = x;ytemp = y;//ll=x;rr=y;

  }
  if(event==EVENT_LBUTTONUP){
    xtemp2 = x;ytemp2 = y;

    rectangle(cloneTemp,Point(xtemp,ytemp),Point(xtemp2,ytemp2),Scalar(255,0,0));
    imshow("23",cloneTemp);
  }
}
int main(int argc, char ** argv){
  Mat src = imread("123.png");
  namedWindow("23");
  setMouseCallback("23", my_mouse_callback, &src);
  imshow("23",src);
  waitKey(0);
  return 0;
}
