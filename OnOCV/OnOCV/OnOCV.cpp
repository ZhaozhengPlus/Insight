// OnOCV.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "lab.h"

using namespace std;
using namespace cv;

LARGE_INTEGER	g_perfFeq;
LARGE_INTEGER	g_perfCountOld;
LARGE_INTEGER	g_perfCountNew;

#define	TIMETOUCH(Counter)	QueryPerformanceCounter(&Counter)
#define	PRINTTIME(TEXT)		{ cout << TEXT << ",\t#" << (((double)g_perfCountNew.QuadPart) - ((double)g_perfCountOld.QuadPart)) / (double)g_perfFeq.QuadPart * 1000 << "ms" << endl; }


int _tmain(int argc, _TCHAR* argv[])
{
	QueryPerformanceFrequency(&g_perfFeq);

	TIMETOUCH(g_perfCountOld);
	Mat		imgL = imread("..\\..\\ImgRes\\Small_L_S0.jpg");
	TIMETOUCH(g_perfCountNew);
	PRINTTIME("Load Left Image");

	TIMETOUCH(g_perfCountOld);
	Mat		imgR = imread("..\\..\\ImgRes\\Small_R_S0.jpg");
	TIMETOUCH(g_perfCountNew);
	PRINTTIME("Load Right Image");


	RELATIVEPXGRADIENT_5x5*	pGradientsL = nullptr;
	RELATIVEPXGRADIENT_5x5*	pGradientsR = nullptr;

	TIMETOUCH(g_perfCountOld);
	int nGradientsL = CalculateRelativePxGradient5x5(pGradientsL, imgL);
	TIMETOUCH(g_perfCountNew);
	PRINTTIME("Analyzed Left Image");


	TIMETOUCH(g_perfCountOld);
	int nGradientsR = CalculateRelativePxGradient5x5(pGradientsR, imgR);
	TIMETOUCH(g_perfCountNew);
	PRINTTIME("Analyzed Right Image");


	TIMETOUCH(g_perfCountOld);
	OutputAsTxt_PxGradient5x5("..\\..\\FireField\\aloeL_01_Gradient5x5.txt", pGradientsL, nGradientsL);
	TIMETOUCH(g_perfCountNew);
	PRINTTIME("Exported Left Image");

	TIMETOUCH(g_perfCountOld);
	OutputAsTxt_PxGradient5x5("..\\..\\FireField\\aloeR_01_Gradient5x5.txt", pGradientsR, nGradientsR);
	TIMETOUCH(g_perfCountNew);
	PRINTTIME("Exported Right Image");

	SAFE_DELETE_ARRAY(pGradientsL);
	SAFE_DELETE_ARRAY(pGradientsR);


	return 0;
}

