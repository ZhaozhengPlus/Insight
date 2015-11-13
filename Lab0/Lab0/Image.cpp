///	@file		Image.cpp
///	@brief		...
///	@licence	...
///	@designer	Tankle L.
///	@date		First created at < November 6th, 2015 >
///
///	@version	0.1.0
///
///	@programmer	Tankle L.
///	@programmer ...



#include "stdafx.h"

#include "Image.h"




// < IImage [class, abstract] >
///	@classname	IImage
///	@designer	Tankle L.
///
///	@brief		...
///	@modified	Tankle L.	2015.11.6

Insight::IImage::IImage() : _pBuffer(nullptr)
{}

Insight::IImage::~IImage()
{
	if (nullptr != _pBuffer)
	{
		delete[] _pBuffer;
		_pBuffer = nullptr;
	}
}

void Insight::IImage::CopyFrom(IImage* const pImage)
{
	if (nullptr != _pBuffer)
	{
		delete[] _pBuffer;
		_pBuffer = nullptr;
	}

	pImage->GetImgResolution(_resolution);

	if (_resolution.width == 0 ||
		_resolution.height == 0)
		return;

	_pBuffer = new PIXEL[_resolution.width * _resolution.height];
	
	memcpy(_pBuffer, pImage->GetPixelBuffer(), sizeof(PIXEL)* _resolution.width * _resolution.height);
}

void Insight::IImage::Blank()
{
	if (nullptr != _pBuffer)
	{
		memset(_pBuffer, 0, sizeof(PIXEL)* _resolution.width * _resolution.height);
	}
}

// </ IImage >




// < ImageBitmap24 [class, abstract] >
///	@classname	ImageBitmap24
///	@designer	Tankle L.
///
///	@brief		...
///	@modified	Tankle L.	2015.11.6

Insight::ImageBitmap24::ImageBitmap24()
{}

Insight::ImageBitmap24::ImageBitmap24(const RESOLUTION& reso)
{
	_resolution = reso;

	if (_resolution.width == 0 ||
		_resolution.height == 0)
		return;

	_pBuffer = new PIXEL[_resolution.width * _resolution.height];
	memset(_pBuffer, 0, sizeof(PIXEL)* _resolution.width * _resolution.height);	
}

Insight::ImageBitmap24::~ImageBitmap24()
{
	if (nullptr != _pBuffer)
	{
		delete[] _pBuffer;
		_pBuffer = nullptr;
	}
}

int Insight::ImageBitmap24::FromFile(const std::string& fileName)
{
	BITMAPFILEHEADER	bfh;
	BITMAPINFOHEADER	bih;



	return 0;
}

int Insight::ImageBitmap24::ToFile(const std::string& fileName)
{
	return 0;
}


Insight::IMAGEFILETYPE Insight::ImageBitmap24::GetImageFileType() const
{
	return Insight::IFT_BMP_24;
}

// </ ImageBitmap24 >





// < ImageBitmap32 [class, abstract] >
///	@classname	ImageBitmap32
///	@designer	Tankle L.
///
///	@brief		...
///	@modified	Tankle L.	2015.11.6

Insight::ImageBitmap32::ImageBitmap32()
{}

Insight::ImageBitmap32::ImageBitmap32(const RESOLUTION& reso)
{
	_resolution = reso;

	if (_resolution.width == 0 ||
		_resolution.height == 0)
		return;

	_pBuffer = new PIXEL[_resolution.width * _resolution.height];
	memset(_pBuffer, 0, sizeof(PIXEL)* _resolution.width * _resolution.height);
}

Insight::ImageBitmap32::~ImageBitmap32()
{
	if (nullptr != _pBuffer)
	{
		delete[] _pBuffer;
		_pBuffer = nullptr;
	}
}

int Insight::ImageBitmap32::FromFile(const std::string& fileName)
{
	return 0;
}

int Insight::ImageBitmap32::ToFile(const std::string& fileName)
{
	return 0;
}


Insight::IMAGEFILETYPE Insight::ImageBitmap32::GetImageFileType() const
{
	return Insight::IFT_BMP_24;
}

// </ ImageBitmap24 >