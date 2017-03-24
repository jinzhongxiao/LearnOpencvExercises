#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
using namespace std;
using namespace cv;

int main(int argc, const char** argv)
{
  Mat src = imread("result1.png");
  vector<Mat> channels;

  split(src, channels);
  cout<<channels.size()<<endl;

  //a
  imshow("green",channels[1]);
  //b
  Mat clone1 = channels[1].clone();
  Mat clone2 = channels[1].clone();

  //c
  double minVal = 0, maxVal = 0;
  minMaxIdx(channels[1], &minVal, &maxVal);
  cout<<minVal<<"       "<<maxVal<<endl;


  //d
  clone1.setTo(Scalar((maxVal-minVal)/2));
  imshow("d",clone1);


  //e
  clone2.setTo(Scalar(0));
  compare(channels[1],channels[1],channels[1],CMP_GE);


  //f'
  CvMat* greenImage = (CvMat *)&channels[1];
  CvMat* CLone2 = (CvMat *)&clone2;
  cvSubS(greenImage,cvScalar((maxVal-minVal)/4), greenImage,CLone2);

  Mat img(greenImage);
  imshow("ff",img);
  waitKey(0);
  return 0;
}
