#include<opencv2/opencv.hpp>
#include<vector>
#include<iostream>
#include"drawROI.hpp"

using namespace cv;

int main()
{
	std::vector<Mat> temp;
	VideoCapture capture(0);
	while (1)
	{
		Mat frame;
		capture >> frame;
		imshow("拍照", frame);
		if (waitKey(10) == 32)                    //按空格，拍照
		{
			temp.push_back(frame);
			std::cout << "已拍照" << std::endl;
			waitKey(500);
		}
		if (waitKey(10) == 27) {                  //按esc退出拍照界面
			destroyWindow("拍照");
			break;
		}
	}
	

	Mat tempImage;
	namedWindow("roi选取");                      //对于鼠标操作，必须先命名一个窗口，不可以直接在imshow中建立，否则鼠标操作无效
	setMouseCallback("roi选取", on_MouseHandle, (void*)& tempImage);
	while (1)
	{
		(temp[0]).copyTo(tempImage);
		if (drawBox) {
			drawRect(tempImage, Box);
		}
		imshow("roi选取", tempImage);
		waitKey(30);                             //必须加上时间间隔，否则刷新频率太高会加载不出图像
		if (start == true)                       //鼠标左键抬起，区域选择结束，退出选取区域界面
		{
			waitKey(500);
			destroyWindow("roi选取");            //destroyWindow必须在break之前执行，否则一旦跳出循环就只能在循环外关闭此窗口
			break;
		}
	}
	Mat roi;
	roi = (temp[0])(Box);
	namedWindow("截取的区域", CV_WINDOW_AUTOSIZE);
	imshow("截取的区域", roi);
	waitKey(0);
}