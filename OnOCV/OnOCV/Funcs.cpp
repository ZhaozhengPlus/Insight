///	@file		Funcs.h
///	@brief		...
///	@licence	...
///	@designer	Tankle L.
///	@date		First created at < November 17th, 2015 >
///
///	@version	0.1.0
///
///	@programmer	Tankle L.
///	@programmer ...

#include "stdafx.h"

#include "lab.h"

using namespace cv;

int	CalculateRelativePxGradient3x3(RELATIVEPXGRADIENT_3x3* pGradients, const cv::Mat& imgMat)
{
	int width = imgMat.cols;
	int height = imgMat.rows;

	pGradients = new RELATIVEPXGRADIENT_3x3[(width - 2)*(height - 2)];

	register unsigned char	reg = 0;
	for (int y = 1; y < height - 1; ++y)
	{
		for (int x = 1; x < width - 1; ++x)
		{


			{
				//if (GetPixelBright());
				pGradients[x + (width - 2)*y];
			}


		}
	}
	return 0;
}