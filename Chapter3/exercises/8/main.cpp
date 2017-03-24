#include "opencv2/highgui/highgui.hpp"
#include "opencv2/core/core.hpp"
#include <iostream>
using namespace std;
using namespace cv;

typedef struct my_struct{
  int value;
  CvPoint pos;
  CvRect rect;
}my_struct;

void write_my_struct(CvFileStorage* fs, const char * name, my_struct* ms){
    cvWriteInt(fs,name,10);
  	//开始写入新的数据结构
  	cvStartWriteStruct(fs,"Value",CV_NODE_SEQ);
  	cvWriteInt(fs,0,ms->value);
  	//结束写入数据结构
  	cvEndWriteStruct(fs);

  	cvStartWriteStruct(fs,"Point",CV_NODE_SEQ);
  	cvWriteInt(fs,0,ms->pos.x);
  	cvWriteInt(fs,0,ms->pos.y);
  	cvEndWriteStruct(fs);

  	cvStartWriteStruct(fs,"Rect",CV_NODE_SEQ);
  	cvWriteInt(fs,0,ms->rect.x);
  	cvWriteInt(fs,0,ms->rect.y);
  	cvWriteInt(fs,0,ms->rect.width);
  	cvWriteInt(fs,0,ms->rect.height);
  	cvEndWriteStruct(fs);

}

void read_my_struct(CvFileStorage* fs, CvFileNode* ms_node, my_struct* ms){

    fs = cvOpenFileStorage("ms.xml",0,CV_STORAGE_READ);

    int value = cvReadIntByName(fs,0,"Value",1);

    CvSeq*  s= cvGetFileNodeByName(fs,0,"Point")->data.seq;
    int point_X = cvReadInt((CvFileNode*)cvGetSeqElem(s,0));
    int point_Y = cvReadInt((CvFileNode*)cvGetSeqElem(s,1));

    cout<<"x = "<<point_X<<",  "<<point_Y<<endl;
    cvReleaseFileStorage(&fs);
}
int main(int argc, const char** argv)
{
      CvFileStorage* fs=cvOpenFileStorage("ms.xml",0,CV_STORAGE_WRITE);
      //声明结构myst,并赋值
      my_struct myst={10,cvPoint(2,2),cvRect(0,0,5,5)};
      //调用write_my_struct函数完成数据写入磁盘
      write_my_struct(fs,"Struct",&myst);
      //使用cvReleaseFileStorage释放CvFileStorage结构句柄
      cvReleaseFileStorage(&fs);
      //将数据从磁盘读入内存
      read_my_struct(fs,NULL,&myst);
      return 0;
}
