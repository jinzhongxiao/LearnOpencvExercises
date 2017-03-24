#include "opencv2/highgui/highgui.hpp"
#include "cv.h"
#include <iostream>
using namespace std;
int main(int argc, char ** argv){
  CvPoint3D32f Point2 = cvPoint3D32f(200.0,240.0,3);
  cout<<Point2.x<<" , "<<Point2.y<<endl;
  return 0;

}
