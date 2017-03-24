#include "cv.h"
#include <stdlib.h>
#include <iostream>
using namespace std;
int main(int argc, char** argv){

  double result = (double)abs(atoi(argv[1]));

  cout<<cvCeil(result)<<endl;


  CvRNG rng = cvRNG(cvGetTickCount());
  for(int i = 0; i < 10; i++ ){
    cout << cvRandInt(&rng)%10 << endl;

  }

  CvPoint2D32f pointf = cvPoint2D32f(2.4,3.3);
  CvPoint temp1 = cvPointFrom32f(pointf);
  cout<<temp1.x<<"   "<<temp1.y<<endl;

  CvPoint2D32f temp2 = cvPointTo32f(temp1);
  cout<<temp2.x<<"   "<<temp2.y<<endl;
  return 0;
}
