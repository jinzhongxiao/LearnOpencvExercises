#include "opencv2/highgui/highgui.hpp"
#include "cv.h"

int main(int argc, char ** argv){
  /*CvCapture* capture = 0;
  capture = cvCreateFileCapture(argv[1]);

  if(!capture)return -1;
  cvNamedWindow("TTT");
  IplImage* bgr_frame = cvQueryFrame(capture);

  double fps=cvGetCaptureProperty(capture, CV_CAP_PROP_FPS);

  CvSize size = cvSize((int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_WIDTH),
  (int)cvGetCaptureProperty(capture, CV_CAP_PROP_FRAME_HEIGHT)
);
  CvVideoWriter* writer = cvCreateVideoWriter(argv[2], CV_FOURCC('M','J','P','G'),fps,size);

  IplImage* logpolar_frame = cvCreateImage(size, IPL_DEPTH_8U,3);

  while((bgr_frame = cvQueryFrame(capture))!=NULL){
    cvLogPolar(bgr_frame, logpolar_frame,
        cvPoint2D32f(bgr_frame->width/2, bgr_frame->height/2),40,CV_INTER_LINEAR+CV_WARP_FILL_OUTLIERS);

    cvShowImage("TTT", logpolar_frame);

    cvWriteFrame(writer,logpolar_frame);
    char c = cvWaitKey(33);
    if(c == 27)break;
  }

  cvReleaseCapture(&capture);
  cvReleaseVideoWriter(&writer);
  cvReleaseImage(&logpolar_frame);
  return 0;*/


  if(argc!=3) return -1;
//新建CvCapture*类型变量
CvCapture *capture=NULL;
//用cvCreateFileCapture函数从第一个输入参数读入视频文件
capture=cvCreateFileCapture(argv[1]);
//如果读入视频文件失败，则退出程序
if(!capture) return -1;
//用cvQueryFrame函数获取视频文件的第一帧保存到bgr_frame中
IplImage *bgr_frame=cvQueryFrame(capture);
//用cvGetCaptureProperty函数获取视频文件的帧率，使输入视频的帧率与其一致
double fps=cvGetCaptureProperty(capture,CV_CAP_PROP_FPS);
//用cvSize函数建立一个CvSize类型的变量size，其宽度和高度与输入视频文件相同
CvSize size=cvSize((int)cvGetCaptureProperty(capture,CV_CAP_PROP_FRAME_WIDTH),
      (int)cvGetCaptureProperty(capture,CV_CAP_PROP_FRAME_HEIGHT));
//用cvCreateVideoWriter函数新建一个CvVideoWriter*类型变量，用来输出视频文件
CvVideoWriter *writer=cvCreateVideoWriter(argv[2],CV_FOURCC('M','J','P','G'),
        fps,size);

cvNamedWindow("mainwin", CV_WINDOW_AUTOSIZE);//创建一个窗口显示修改后的视频；


//用cvCreateImage函数创建一个IplImage*类型变量logpolar_frame
IplImage *logpolar_grame=cvCreateImage(size,IPL_DEPTH_8U,3);
//用cvQueryFrame函数继续读入输入视频文件，直到文件尾
while((bgr_frame=cvQueryFrame(capture))!=NULL)
{
  //用cvLogPolar函数把图像映射到极指数空间
  cvLogPolar(bgr_frame,logpolar_grame,cvPoint2D32f(bgr_frame->width/2,
      bgr_frame->height/2),40,CV_INTER_LINEAR+CV_WARP_FILL_OUTLIERS);
  //用cvWriteFrame函数将极指数空间的图像保存到writer中
  cvWriteFrame(writer,logpolar_grame);

cvShowImage("mainwin", logpolar_grame); //在mainwin窗口中显示生成的视频；

char c=cvWaitKey(33);

if (c == 27) break; //当输入ESC键时，退出窗口；


}
//转化完毕，用cvReleaseVideoWriter函数释放CvVideoWriter*类型变量所占内存空间
cvReleaseVideoWriter(&writer);
//用cvReleaseImage函数释放IplImage*类型变量所占内存空间
cvReleaseImage(&logpolar_grame);
//用cvReleaseCapture函数释放CvCapture*类型变量所占内存空间
cvReleaseCapture(&capture);
//程序结束，返回0
return 0;

}
