#include "cv.h"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main(int argc, char** argv){
  Mat src = Mat::zeros(210,210,CV_8UC1);
  int ww = 10;
  int num = (src.cols - ww)/20;
  cout <<"ee"<<num<<endl;
  for(int i = 0; i < num; i++){
    Mat srcRoi(src, Rect(0 + i*ww, 0+ i*ww, src.cols - 2*i*ww,src.cols - 2*i*ww));
    //srcRoi(src.cols - 2*i*ww,src.cols - 2*i*ww,cvScalar(i*20));
    srcRoi.setTo(Scalar(i*20));
  }

  imshow("example", src);


  waitKey(0);
  return 0;
}
