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


	return 0;
}

