#include <iostream>
#include "opencv2/core/core.hpp"

#include "cv.h"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;
using namespace std;
char* str = (char*)malloc(30 * sizeof(char*));
CvFont font;
//Mat src;

//byte转int
 int bytesToInt(unsigned char bytes,int size = 4)
{
    int addr = (int)bytes ;

    return addr;
 }


void my_mouse_callback(int event, int x, int y, int, void* data){
  Mat *t = (Mat*)data;

  IplImage temp = (IplImage)(*t);
  if(event==EVENT_LBUTTONDOWN){
    Vec3b s = t->at<Vec3b>(x,y);
    cout<<bytesToInt(s[0])<<",  "<<bytesToInt(s[1])<<",  "<<bytesToInt(s[2])<<endl;;
    sprintf(str, "B:%d,G:%d,R:%d", s[0], s[1], s[2]);
    cvPutText(&temp,str, cvPoint(x, y), &font, CV_RGB(255,0,0));
    imshow("src", *t);
  }
}
int main(int argc, char ** argv){
  Mat src = imread("123.png");
  cvInitFont(&font, CV_FONT_HERSHEY_COMPLEX, 1,1,1,2,8);
  namedWindow("src");

  setMouseCallback("src", my_mouse_callback, &src);
  imshow("src", src);
  cout<<CV_16SC3<<endl;
  cout<<CV_16SC2<<endl;
  cout<<CV_16SC1<<endl;
  cout<<CV_8UC1<<endl;
  cout<<CV_8UC2<<endl;
  cout<<CV_8UC3<<endl;
  waitKey(0);
  return 0;
}
