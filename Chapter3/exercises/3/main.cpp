#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>

using namespace cv;
using namespace std;

CvPoint point1 = cvPoint(20,5);
CvPoint point2 = cvPoint(40,20);

bool eq(Mat m){

  for(int i = 0; i < m.rows; i++)
    for(int j = 0; j < m.cols; j++)
      for(int k = 0; k<3;k++)
        if(m.at<Vec3b>(i,j)[k]!=255){cout<<"d "<<i<<" x "<<j<<endl;
          return false;}
  return true;

}
///这里双重小于等于是坑！！！！！！   需改变///×××××××××××××××××××××//包括的循环边界
bool isThePointIsRect(int x, int y){
  if( x == point1.x && point1.y <= y && y <= point2.y)
        return true;
    else if (x == point2.x && point1.y <= y && y <= point2.y)
        return true;
    else if (y == point1.y && point1.x <= x && x <= point2.x)
        return true;
    else if (y == point2.y && point1.x <= x && x <= point2.x)
        return true;
    else
        return false;
}

int main(int argc, char** argv){
  vector<Mat> channels;
  namedWindow("q ");
  Mat src = Mat::zeros(100,100,CV_8UC3);

  Mat src1 = src.clone();
  Mat src2 = src.clone();
  Mat dst = src.clone();
  //
  for(int i=1;i<src1.rows;i++)
  {
      for(int j = 1;j<src1.cols;j++){
        if(isThePointIsRect(i,j)==true)
          src1.at<cv::Vec3b>(i,j)[1] = 255;
      }
  }
  imshow("q ",src1);


  split(src2,channels);

///×××××××××××××××××××××//
  Mat roi = channels[1](Rect(5,20,15,20));
  for(int i=0;i<=roi.rows;i++)
  {
    roi.at<uchar>(i,0)=255;  roi.at<uchar>(i,roi.cols)=255;
  }
  for(int j=0;j<=roi.cols;j++){
    roi.at<uchar>(0,j)=255;  roi.at<uchar>(roi.rows,j)=255;
  }
///×××××××××××××××××××××//
  merge(channels,src2);
  compare(src1,src2,dst,CMP_EQ);
  cout<<"result"<<eq(dst)<<endl;
  imshow("qd ",src2);
  waitKey(0);
  return 0;
}
