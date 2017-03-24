#include "cv.h"
#include "opencv2/highgui/highgui.hpp"

#include <iostream>
using namespace std;
int main(int argc, char* argv[]){
  /*CvFileStorage* fs = cvOpenFileStorage("cfg.xml", 0 , CV_STORAGE_WRITE);
  cvWriteInt(fs, "frame_count", 10);


  cvStartWriteStruct(fs, "frame_size", CV_NODE_SEQ);
  cvWriteInt(fs,0,320);
  cvWriteInt(fs,0,200);

  cvEndWriteStruct(fs);

  CvMat* cmatrix = cvCreateMat(6,6,CV_8UC1);
  cvWrite(fs, "color_cvt_matrix",cmatrix);
  cvReleaseFileStorage(&fs);*/


  CvFileStorage* fs = cvOpenFileStorage("cfg.xml", 0 , CV_STORAGE_READ);

  int frame_count = cvReadIntByName(fs, 0, "frame_count", 5);


  CvSeq* s=cvGetFileNodeByName(fs,0,"frame_size")->data.seq;

  int frame_width = cvReadInt((CvFileNode*)cvGetSeqElem(s,0));

  int frame_height = cvReadInt((CvFileNode*)cvGetSeqElem(s,1));

  cout<< "height :"<<frame_height<<",  width:"<<frame_width<<endl;
  CvMat* colot = (CvMat*)cvReadByName(fs,0,"color_cvt_matrix");

  cvReleaseFileStorage(&fs);
  return 0;
}
