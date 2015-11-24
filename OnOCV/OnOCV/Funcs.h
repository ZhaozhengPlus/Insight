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

#ifndef _FUNCS_H
#define	_FUNCS_H




// Image Analysis
int		CalculateRelativePxGradient3x3(RELATIVEPXGRADIENT_3x3*& pGradients, const cv::Mat& imgMat);
int		CalculateRelativePxGradient5x5(RELATIVEPXGRADIENT_5x5*& pGradients, const cv::Mat& imgMat);
int		CalculateRelativePxGradient9x9(RELATIVEPXGRADIENT_9x9*& pGradients, const cv::Mat& imgMat);


// File Process
int		OutputAsTxt_PxGradient3x3(const std::string& fileName, RELATIVEPXGRADIENT_3x3* const pGradients, const int& count);
int		OutputAsTxt_PxGradient5x5(const std::string& fileName, RELATIVEPXGRADIENT_5x5* const pGradients, const int& count);
int		OutputAsTxt_PxGradient9x9(const std::string& fileName, RELATIVEPXGRADIENT_9x9* const pGradients, const int& count);



#endif // !_FUNCS_H
