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

#include "Insight.h"

using namespace std;


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
	SAFE_DELETE_ARRAY(_pBuffer);
}

void Insight::IImage::CopyFrom(IImage* const pImage)
{
	SAFE_DELETE_ARRAY(_pBuffer);

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

void Insight::ImageBitmap24::FromFile(const std::string& fileName)
{
	Insight::Exception	excep;
	BITMAPFILEHEADER	bfh;
	BITMAPINFOHEADER	bih;

	ifstream	file(fileName, ios_base::in| ios_base::binary);

	if (!file.is_open())
	{
		excep.WriteInfo(string("Cannot open file."), -1);

		throw excep;
	}

	file.read(reinterpret_cast<char*>(&bfh), sizeof(bfh));
	if (file.fail())
	{
		excep.WriteInfo(string("Cannot read bitmap-file-header."), -1);
		file.close();

		throw excep;
	}

	file.read(reinterpret_cast<char*>(&bih), sizeof(bih));
	if (file.fail())
	{
		excep.WriteInfo(string("Cannot read bitmap-info-header."), -1);
		file.close();

		throw excep;
	}

	DWORD	btr = bfh.bfSize - bfh.bfOffBits;
	if (btr == 0)	// no image data
	{
		SAFE_DELETE_ARRAY(_pBuffer);
		_resolution.width = 0;
		_resolution.height = 0;
		return;
	}
	else			// image data exists
	{
		_resolution.width = bih.biWidth;
		_resolution.height = bih.biHeight;

		// Clear old buffer.
		SAFE_DELETE_ARRAY(_pBuffer);
		_resolution.width = 0;
		_resolution.height = 0;

		// create temporary buffer and read pixel24 data.
		BYTE* pBuf24 = new BYTE[btr];

		file.read((char*)pBuf24, btr);
		if (file.fail())
		{
			excep.WriteInfo(string("Cannot read image data."), -1);
			file.close();
			delete[] pBuf24;
			
			throw excep;
		}

		// create pixel buffer and convert 24bit-data into 32bit-data
		_pBuffer = new PIXEL[_resolution.width*_resolution.height];

			// convert
		BYTE*			pChannel = pBuf24;
		unsigned int	index = 0;
		unsigned int	alignoffset = 0;

		if ((3 * _resolution.width) % 4 != 0)
		{
			alignoffset = 4 - (3 * _resolution.width) % 4;
		}

		for (int y = 0; y < _resolution.height; ++y)
		{
			for (int x = 0; x < _resolution.width; ++x)
			{
				_pBuffer[index] = PixelRGB( pChannel[(x + y*_resolution.width) + y*alignoffset],		// r
											pChannel[1 + (x + y*_resolution.width) + y*alignoffset],	// g
											pChannel[2 + (x + y*_resolution.width) + y*alignoffset]);	// b
				++index;
			}			
		}
	}

	/*
	DWORD offset = 0;
	DWORD	btr = 0;
	DWORD	br = 0;
	LPBYTE	lpTemp = NULL;

	if (NULL == hFile)
		return false;

	if (ReadFile(hFile, &fh, sizeof(fh), &br, NULL))
	{
		if (ReadFile(hFile, &bf, sizeof(bf), &br, NULL))
		{
			btr = fh.bfSize - fh.bfOffBits;
			if (btr != 0)
			{
				lpBuf = new BYTE[btr];
				ReadFile(hFile, lpBuf, btr, &br, NULL);
				bufSize = btr;
				return true;
			}
			return true;
		}
		return false;
	}
	return false;
	*/
}

void Insight::ImageBitmap24::ToFile(const std::string& fileName)
{
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

void Insight::ImageBitmap32::FromFile(const std::string& fileName)
{
}

void Insight::ImageBitmap32::ToFile(const std::string& fileName)
{
}


Insight::IMAGEFILETYPE Insight::ImageBitmap32::GetImageFileType() const
{
	return Insight::IFT_BMP_24;
}

// </ ImageBitmap24 >