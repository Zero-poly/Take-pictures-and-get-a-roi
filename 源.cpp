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
		imshow("����", frame);
		if (waitKey(10) == 32)                    //���ո�����
		{
			temp.push_back(frame);
			std::cout << "������" << std::endl;
			waitKey(500);
		}
		if (waitKey(10) == 27) {                  //��esc�˳����ս���
			destroyWindow("����");
			break;
		}
	}
	

	Mat tempImage;
	namedWindow("roiѡȡ");                      //����������������������һ�����ڣ�������ֱ����imshow�н�����������������Ч
	setMouseCallback("roiѡȡ", on_MouseHandle, (void*)& tempImage);
	while (1)
	{
		(temp[0]).copyTo(tempImage);
		if (drawBox) {
			drawRect(tempImage, Box);
		}
		imshow("roiѡȡ", tempImage);
		waitKey(30);                             //�������ʱ����������ˢ��Ƶ��̫�߻���ز���ͼ��
		if (start == true)                       //������̧������ѡ��������˳�ѡȡ�������
		{
			waitKey(500);
			destroyWindow("roiѡȡ");            //destroyWindow������break֮ǰִ�У�����һ������ѭ����ֻ����ѭ����رմ˴���
			break;
		}
	}
	Mat roi;
	roi = (temp[0])(Box);
	namedWindow("��ȡ������", CV_WINDOW_AUTOSIZE);
	imshow("��ȡ������", roi);
	waitKey(0);
}