#include "cv.h"
#include "opencv2/highgui/highgui.hpp"

#include <iostream>
using namespace std;
int main(int argc, char** argv){


  const char* libraries;
  const char* modules;
  cvGetModuleInfo(0,&libraries,&modules);

  cout<<"Libraries:"<<libraries<<endl;
  cout<<"Modules:"<<modules<<endl;
  return 0;
}
