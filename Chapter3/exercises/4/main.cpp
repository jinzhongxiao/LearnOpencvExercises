#include "cv.h"
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main(int argc, char** argv){
  Mat src = Mat::zeros(100,100,CV_8UC3);

  for(int i = 0; i < src.cols; i++)
  {
    for(int j = 0; j < src.rows; j++){
      if(i>=5 && i<=20 && j<=40 && j>=20)
          src.at<Vec3b>(j,i)[1] = 255;
    }
  }

  imshow("example", src);

  waitKey(0);
  return 0;
}
