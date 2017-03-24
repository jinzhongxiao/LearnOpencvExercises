#include "cv.h"
#include "opencv2/highgui/highgui.hpp"

using namespace cv;



int main(int args, char** argv){
  Mat src = imread("hua.jpg");
  imshow("ii",src);
  Mat dst = src.clone();
  GaussianBlur( src, dst, Size( 3, 3 ), 0, 0 );
  imshow("ii1",dst);
  GaussianBlur( src, dst, Size( 5, 5 ), 0, 0 );  imshow("ii2",dst);
  GaussianBlur( src, dst, Size( 9, 9 ), 0, 0 );  imshow("ii3",dst);

  GaussianBlur( src, dst, Size( 9, 9 ), 0, 0 );  imshow("i11",dst);

  Mat t = src.clone();
  GaussianBlur( t, dst, Size( 5, 5 ), 0, 0 );
  t = dst.clone();
  GaussianBlur( t, dst, Size( 5, 5 ), 0, 0 );
  imshow("55",dst);


  waitKey(0);
  return 0;
}
