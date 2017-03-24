#include <iostream>
#include "opencv2/core/core.hpp"

#include "cv.h"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;
using namespace std;

int kernel_size = 3;

Mat img,dst;
Mat img_temp;


int main(int argc, char ** argv){
  //a
  VideoCapture cap("show.mp4");
  if(cap.isOpened())cout<<"OK"<<endl;

  while(1){
    cap >> img;
    imshow("11", img);
    if(27==waitKey(33))break;

    cvtColor(img,dst,CV_BGR2GRAY);

    imshow("12", dst);

    namedWindow("13");
    img_temp = img.clone();
    Canny( img_temp, img_temp, 10, 100, kernel_size );
    imshow( "13", img_temp );

    //b

    Mat img_left = img;
      Mat img_right = img;

      Size size(img_left.cols + img_right.cols, (img_left.rows));

      Mat img_merge;
      Mat outImg_left, outImg_right;

      img_merge.create(size, img.type());
      img_merge = Scalar::all(0);
      outImg_left = img_merge(Rect(0, 0, img_left.cols, img_left.rows));
      outImg_right = img_merge(Rect(img_left.cols, 0, img_right.cols, img_right.rows));

          img_left.copyTo(outImg_left);

          //outImg_left = img_left.clone();

          //outImg_right = img_right.clone();
          img_right.copyTo(outImg_right);
          CvFont font;
        cvInitFont(&font, CV_FONT_HERSHEY_COMPLEX, 1.0, 1.0, 0, 2, 8);


          IplImage jin = img_merge;
        cvPutText(&jin, "Hello, Chen Lee!", cvPoint(0, 40), &font, CV_RGB(255,0,0));

      cvPutText(&jin, "Hello, Chen 3w!", cvPoint(img.cols, 40), &font, CV_RGB(255,0,0));

      imshow("merge", img_merge);



}

  return 0;
}
