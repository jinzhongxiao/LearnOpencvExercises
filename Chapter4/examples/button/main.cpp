#include "cv.h"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
using namespace std;

int g_switch_value = 0;
void switch_callback(int position){
  if(position == 0)cout<<"OFF"<<endl;
  else cout<<"ON"<<endl;

}

int main(int argc, char** argv){
  cvNamedWindow("Demo", 1);
  cvCreateTrackbar("Switch", "Demo", &g_switch_value, 1, switch_callback);


  while(1){
    if(27 == cvWaitKey(15))break;
  }
  return 0;
}
