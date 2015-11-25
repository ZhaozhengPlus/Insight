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
#define	PRINTTIME(Text)		{ cout << Text << ",\t#" << (((double)g_perfCountNew.QuadPart) - ((double)g_perfCountOld.QuadPart)) / (double)g_perfFeq.QuadPart * 1000 << "ms" << endl; }


int _tmain(int argc, _TCHAR* argv[])
{
	Mat	img = imread("..\\..\\ImgRes\\t2.png");

	RELATIVEPXGRADIENT_3x3*	pGra = nullptr;
	int nGra = CalculateRelativePxGradient3x3(pGra, img);

	OutputAsTxt_PxGradient3x3("..\\..\\FireField\\t2_3x3.txt", pGra, nGra);

	return 0;
}

