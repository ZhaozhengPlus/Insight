// OnOCV.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "lab.h"

using namespace std;
using namespace cv;

int _tmain(int argc, _TCHAR* argv[])
{
	Mat		img = imread("..\\..\\ImgRes\\t0.bmp");

	RELATIVEPXGRADIENT_3x3*	pGradients = nullptr;

	int nGradients = CalculateRelativePxGradient3x3(pGradients, img);

	return 0;
}

