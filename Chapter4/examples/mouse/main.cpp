#include "cv.h"
#include "opencv2/highgui/highgui.hpp"
#include <iostream>
using namespace std;

CvRect box;
bool drawing_box = false;



void draw_box(IplImage* img, CvRect box){
  cvRectangle(img, cvPoint(box.x, box.y), cvPoint(box.y+box.width, box.y+box.height),
    cvScalar(0xff, 0x00, 0x00));
}
void my_mouse_callback(int event, int x, int y, int flags,void* param){
  IplImage* image = (IplImage*)param;
  switch (event) {
    case CV_EVENT_MOUSEMOVE:{
      if(drawing_box){

        box.width = x - box.x;
        box.height = y - box.y;
    cout<<x<<",     "<<y<<"wwhh"<<box.x<<"    ,"<<box.y<<"hhhh"<<box.width<<"    ,"<<box.height<<endl;
      }
    }
    break;
    case CV_EVENT_LBUTTONDOWN:{
      drawing_box = true;
      box = cvRect(x,y,0,0);
      cout<<"DOWN"<<endl;
    }
    break;
    case CV_EVENT_LBUTTONUP:{
      drawing_box = false;
     if(box.width<0){
          box.x+=box.width;
          box.width *= -1;
      }

      if(box.height<0){
        box.y+=box.height;
        box.height*=-1;
      }

  cout<<"hhhh"<<box.width<<"    ,"<<box.height<<endl;
      draw_box(image, box);
      cout<<"UP"<<endl;
    }break;
  }
}



int main(int argc, char** argv){
  box = cvRect(-1,-1,0,0);

  IplImage* image = cvCreateImage(cvSize(200,200),
    IPL_DEPTH_8U,
    3);

  cvZero(image);

  IplImage* temp = cvCloneImage(image);

  cvNamedWindow("Box example");

  cvSetMouseCallback("Box example", my_mouse_callback, (void*)image);

  while(1){
    cvCopyImage(image, temp);   //作用是只复制图上的最后一次画图
    
    draw_box(temp, box);
    cvShowImage("Box example", temp);
    if(cvWaitKey(15) == 27)break;
  }

  cvReleaseImage(&image);
  cvReleaseImage(&temp);

  cvDestroyWindow("Box example");
  return 0;
}
