#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>


using namespace std;
int main(int argc, char** argv){
  cv::namedWindow("22");
  cv::Mat mat = cv::Mat::zeros(100,100,CV_8UC3);
  cv::Scalar color(0,255,0,0);
  cout<<mat.cols;
  circle(mat,cv::Point(mat.cols/2,mat.rows/2),mat.rows/2,color);
  cv::imshow("22", mat);
  cv::waitKey(0);

  return 0;
}
