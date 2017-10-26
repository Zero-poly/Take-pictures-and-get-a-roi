#pragma once

#include<opencv2/opencv.hpp>

using namespace cv;

void on_MouseHandle(int event, int x, int y, int flags, void* param);
void drawRect(Mat& frame, Rect Box);

bool drawBox= false;
bool start = false;
Rect Box;

void on_MouseHandle(int event, int x, int y, int flags, void* param)
{
	Mat& image = *(Mat*)param;
	switch (event)
	{
	case EVENT_LBUTTONDOWN:
	{
		drawBox = true;
		Box = Rect(x, y, 0, 0);
	}break;
	
	case EVENT_MOUSEMOVE:
	{
		if (drawBox)
		{
			Box.width = x - Box.x;
			Box.height = y - Box.y;
		}
	}break;

	case EVENT_LBUTTONUP:
	{
		drawBox = false;
		if (Box.width < 0)
		{
			Box.x += Box.width;
			Box.width *= -1;
		}
		if (Box.height < 0)
		{
			Box.y += Box.height;
			Box.height *= -1;
		}
		drawRect(image, Box);
		start = true;
	}break;
	}
}

void drawRect(Mat& frame, Rect Box)
{
	rectangle(frame, Box.tl(), Box.br(), Scalar(0, 0, 255));
}
