// LabRoom0.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include "Insight.h"

using namespace std;
using namespace Insight;

int _tmain(int argc, _TCHAR* argv[])
{
	ImageBitmap24	img24;
	ImageBitmap32	img32;

	try
	{
		img24.FromFile("F:\\FireField\\2\\t0.bmp");
		img32.CopyFrom(&img24);
		img32.ToFile("F:\\FireField\\2\\t1.bmp");

	}
	catch (Exception excep)
	{
		cout << excep.ReadInfo() << endl;
	}

	return 0;
}

