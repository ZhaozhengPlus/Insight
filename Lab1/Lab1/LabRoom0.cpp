// Lab1.cpp : �������̨Ӧ�ó������ڵ㡣
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

