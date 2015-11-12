// Lab1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

using namespace cv;

int _tmain(int argc, _TCHAR* argv[])
{
	Mat	imgL = imread(cv::String("F:\\Insight\\ImgRes\\aloeL.JPG"));
	Mat	imgR = imread(cv::String("F:\\Insight\\ImgRes\\aloeR.JPG"));

	namedWindow(String("Left Image"));
	namedWindow(String("Right Image"));

	imshow(String("Left Image"), imgL);
	imshow(String("Right Image"), imgR);

	waitKey();

	//system("pause");

	return 0;
}

