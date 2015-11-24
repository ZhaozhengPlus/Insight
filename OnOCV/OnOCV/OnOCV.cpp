// OnOCV.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "lab.h"

using namespace std;
using namespace cv;

int _tmain(int argc, _TCHAR* argv[])
{
	Mat		img = imread("..\\..\\ImgRes\\t0.bmp");


	Vec3b	*pRow = img.ptr<Vec3b>(0);

	for (int i = 0; i < 9; ++i)
	{
		cout << "<row " << i << ": " << (int)pRow[i].val[0] << ", " << (int)pRow[i].val[1] << ", " << (int)pRow[i].val[2] << ">" << endl;
	}
	imshow("A", img);

	pRow[0].val[0] = 0;
	pRow[0].val[1] = 0;
	pRow[0].val[2] = 0;

	imshow("B", img);

	waitKey();

	/*
	Mat		imgL = imread("..\\..\\ImgRes\\aloeL.jpg");
	Mat		imgR = imread("..\\..\\ImgRes\\aloeR.jpg");

	RELATIVEPXGRADIENT_5x5*	pGradientsL = nullptr;
	RELATIVEPXGRADIENT_5x5*	pGradientsR = nullptr;

	int nGradientsL = CalculateRelativePxGradient5x5(pGradientsL, imgL);
	int nGradientsR = CalculateRelativePxGradient5x5(pGradientsR, imgR);

	OutputAsTxt_PxGradient5x5("..\\..\\FireField\\aloeL_01_Gradient5x5.txt", pGradientsL, nGradientsL);
	OutputAsTxt_PxGradient5x5("..\\..\\FireField\\aloeR_01_Gradient5x5.txt", pGradientsR, nGradientsR);

	SAFE_DELETE_ARRAY(pGradientsL);
	SAFE_DELETE_ARRAY(pGradientsR);
	*/

	return 0;
}

