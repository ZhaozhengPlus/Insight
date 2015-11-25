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
using namespace std;

int	CalculateRelativePxGradient3x3(RELATIVEPXGRADIENT_3x3*& pGradients, const cv::Mat& imgMat)
{
	int width = imgMat.cols;
	int height = imgMat.rows;

	pGradients = new RELATIVEPXGRADIENT_3x3[(width - 2)*(height - 2)];

	Vec3b const*	pPxT = nullptr;			// Top
	Vec3b const*	pPxM = nullptr;			// Middle
	Vec3b const*	pPxB = nullptr;			// Bottom
	register unsigned char	regValue = 0;
	register unsigned int	regPos = 0;
	for (int y = 1; y < height - 1; ++y)
	{
		pPxT = imgMat.ptr<Vec3b>(y - 1);
		pPxM = imgMat.ptr<Vec3b>(y);
		pPxB = imgMat.ptr<Vec3b>(y + 1);
		for (int x = 1; x < width - 1; ++x)
		{
			regPos = x - 1 + (width - 2)*(y - 1);
			pGradients[regPos] = 0;

			//		T -- # # #
			//		M -- # o #
			//		B -- # # #

			{
				// Gradient 0.
				if (GetPixelBrightness(pPxM[x - 1]) > GetPixelBrightness(pPxM[x]))
					regValue = 1;
				else
					regValue = 0;
				pGradients[regPos] |= regValue << 0;

				// Gradient 1.
				if (GetPixelBrightness(pPxT[x - 1]) > GetPixelBrightness(pPxM[x]))
					regValue = 1;
				else
					regValue = 0;
				pGradients[regPos] |= regValue << 1;

				// Gradient 2.
				if (GetPixelBrightness(pPxT[x]) > GetPixelBrightness(pPxM[x]))
					regValue = 1;
				else
					regValue = 0;
				pGradients[regPos] |= regValue << 2;

				// Gradient 3.
				if (GetPixelBrightness(pPxT[x + 1]) > GetPixelBrightness(pPxM[x]))
					regValue = 1;
				else
					regValue = 0;
				pGradients[regPos] |= regValue << 3;

				// Gradient 4.
				if (GetPixelBrightness(pPxM[x + 1]) > GetPixelBrightness(pPxM[x]))
					regValue = 1;
				else
					regValue = 0;
				pGradients[regPos] |= regValue << 4;

				// Gradient 5.
				if (GetPixelBrightness(pPxB[x + 1]) > GetPixelBrightness(pPxM[x]))
					regValue = 1;
				else
					regValue = 0;
				pGradients[regPos] |= regValue << 5;

				// Gradient 7.
				if (GetPixelBrightness(pPxB[x]) > GetPixelBrightness(pPxM[x]))
					regValue = 1;
				else
					regValue = 0;
				pGradients[regPos] |= regValue << 6;

				// Gradient 8.
				if (GetPixelBrightness(pPxB[x - 1]) > GetPixelBrightness(pPxM[x]))
					regValue = 1;
				else
					regValue = 0;
				pGradients[regPos] |= regValue << 7;
			}


		}
	}
	return (width - 2)*(height - 2);
}




int	CalculateRelativePxGradient5x5(RELATIVEPXGRADIENT_5x5*& pGradients, const cv::Mat& imgMat)
{
	int width = imgMat.cols;
	int height = imgMat.rows;

	pGradients = new RELATIVEPXGRADIENT_5x5[(width - 4)*(height - 4)];

	Vec3b const*	pPxT = nullptr;			// Top
	Vec3b const*	pPxTM = nullptr;		// Top-Middle
	Vec3b const*	pPxM = nullptr;			// Middle
	Vec3b const*	pPxBM = nullptr;		// Bottom-Middle
	Vec3b const*	pPxB = nullptr;			// Bottom
	register unsigned char	regValue = 0;
	register unsigned int	regPos = 0;
	for (int y = 2; y < height - 2; ++y)
	{
		pPxT = imgMat.ptr<Vec3b>(y - 2);
		pPxTM = imgMat.ptr<Vec3b>(y - 1);
		pPxM = imgMat.ptr<Vec3b>(y);
		pPxBM = imgMat.ptr<Vec3b>(y + 1);
		pPxB = imgMat.ptr<Vec3b>(y + 2);

		for (int x = 2; x < width - 2; ++x)
		{
			regPos = x - 2 + (width - 4)*(y - 2);
			pGradients[regPos] = 0;

			//		T  -- # # # # #
			//		TM -- # * * * #
			//		M  -- # * o * #
			//		BM -- # * * * #
			//		B  -- # # # # #
			{
				// Gradient 0.
				if (GetPixelBrightness(pPxM[x - 2]) > ( GetPixelBrightness(pPxM[x - 1]) + GetPixelBrightness(pPxM[x]) ) * 0.5f)
					regValue = 1;
				else
					regValue = 0;
				pGradients[regPos] |= regValue << 0;

				// Gradient 1.
				if (GetPixelBrightness(pPxTM[x - 2]) > (GetPixelBrightness(pPxM[x - 1]) + GetPixelBrightness(pPxM[x])) * 0.5f)
					regValue = 1;
				else
					regValue = 0;
				pGradients[regPos] |= regValue << 1;

				// Gradient 2.
				if (GetPixelBrightness(pPxT[x - 2]) > (GetPixelBrightness(pPxTM[x - 1]) + GetPixelBrightness(pPxM[x])) * 0.5f)
					regValue = 1;
				else
					regValue = 0;
				pGradients[regPos] |= regValue << 2;

				// Gradient 3.
				if (GetPixelBrightness(pPxT[x - 1]) > (GetPixelBrightness(pPxTM[x - 1]) + GetPixelBrightness(pPxM[x])) * 0.5f)
					regValue = 1;
				else
					regValue = 0;
				pGradients[regPos] |= regValue << 3;

				// Gradient 4.
				if (GetPixelBrightness(pPxT[x]) > (GetPixelBrightness(pPxTM[x]) + GetPixelBrightness(pPxM[x])) * 0.5f)
					regValue = 1;
				else
					regValue = 0;
				pGradients[regPos] |= regValue << 4;

				// Gradient 5.
				if (GetPixelBrightness(pPxT[x + 1]) > (GetPixelBrightness(pPxTM[x]) + GetPixelBrightness(pPxM[x])) * 0.5f)
					regValue = 1;
				else
					regValue = 0;
				pGradients[regPos] |= regValue << 5;

				// Gradient 6.
				if (GetPixelBrightness(pPxT[x + 2]) > (GetPixelBrightness(pPxTM[x + 1]) + GetPixelBrightness(pPxM[x])) * 0.5f)
					regValue = 1;
				else
					regValue = 0;
				pGradients[regPos] |= regValue << 6;

				// Gradient 7.
				if (GetPixelBrightness(pPxTM[x + 2]) > (GetPixelBrightness(pPxTM[x + 1]) + GetPixelBrightness(pPxM[x])) * 0.5f)
					regValue = 1;
				else
					regValue = 0;
				pGradients[regPos] |= regValue << 7;

				// Gradient 8.
				if (GetPixelBrightness(pPxM[x + 2]) > (GetPixelBrightness(pPxM[x + 1]) + GetPixelBrightness(pPxM[x])) * 0.5f)
					regValue = 1;
				else
					regValue = 0;
				pGradients[regPos] |= regValue << 8;

				// Gradient 9.
				if (GetPixelBrightness(pPxBM[x + 2]) > (GetPixelBrightness(pPxM[x + 1]) + GetPixelBrightness(pPxM[x])) * 0.5f)
					regValue = 1;
				else
					regValue = 0;
				pGradients[regPos] |= regValue << 9;

				// Gradient 10.
				if (GetPixelBrightness(pPxB[x + 2]) > (GetPixelBrightness(pPxBM[x + 1]) + GetPixelBrightness(pPxM[x])) * 0.5f)
					regValue = 1;
				else
					regValue = 0;
				pGradients[regPos] |= regValue << 10;

				// Gradient 11.
				if (GetPixelBrightness(pPxB[x + 1]) > (GetPixelBrightness(pPxBM[x + 1]) + GetPixelBrightness(pPxM[x])) * 0.5f)
					regValue = 1;
				else
					regValue = 0;
				pGradients[regPos] |= regValue << 11;

				// Gradient 12.
				if (GetPixelBrightness(pPxB[x]) > (GetPixelBrightness(pPxBM[x]) + GetPixelBrightness(pPxM[x])) * 0.5f)
					regValue = 1;
				else
					regValue = 0;
				pGradients[regPos] |= regValue << 12;

				// Gradient 13.
				if (GetPixelBrightness(pPxB[x - 1]) > (GetPixelBrightness(pPxBM[x]) + GetPixelBrightness(pPxM[x])) * 0.5f)
					regValue = 1;
				else
					regValue = 0;
				pGradients[regPos] |= regValue << 13;

				// Gradient 14.
				if (GetPixelBrightness(pPxB[x - 2]) > (GetPixelBrightness(pPxBM[x - 1]) + GetPixelBrightness(pPxM[x])) * 0.5f)
					regValue = 1;
				else
					regValue = 0;
				pGradients[regPos] |= regValue << 14;

				// Gradient 15.
				if (GetPixelBrightness(pPxBM[x - 2]) > (GetPixelBrightness(pPxBM[x - 1]) + GetPixelBrightness(pPxM[x])) * 0.5f)
					regValue = 1;
				else
					regValue = 0;
				pGradients[regPos] |= regValue << 15;
			}


		}
	}
	return (width - 4)*(height - 4);
}




int		OutputAsTxt_PxGradient3x3(const std::string& fileName, RELATIVEPXGRADIENT_3x3* const pGradients, const int& count)
{
	ofstream	file(fileName);

	if (!file.is_open())
	{
		return -1;		// Cannot open file.
	}

	file << "Gradient[N]\tX-RadixValue\tII-RadixValue" << endl;

	for (int i = 0; i < count; ++i)
	{
		file << i << "\t" << (int)pGradients[i] << "\t" << IIRadix2XRadix_8bit(pGradients[i]) << endl;
	}

	return count;
}

int		OutputAsTxt_PxGradient5x5(const std::string& fileName, RELATIVEPXGRADIENT_5x5* const pGradients, const int& count)
{
	ofstream	file(fileName);

	if (!file.is_open())
	{
		return -1;		// Cannot open file.
	}

	file << "Gradient[N]\tX-RadixValue\tII-RadixValue" << endl;

	char	valueText[17] = "";
	for (int i = 0; i < count; ++i)
	{
		_itoa_s(pGradients[i], valueText, 2);
		file << i << "\t" << (int)pGradients[i] << "\t" << valueText << endl;
	}

	return count;
}
