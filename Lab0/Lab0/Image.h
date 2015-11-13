///	@file		Image.h
///	@brief		...
///	@licence	...
///	@designer	Tankle L.
///	@date		First created at < November 6th, 2015 >
///
///	@version	0.1.0
///
///	@programmer	Tankle L.
///	@programmer ...




#pragma once

namespace Insight
{




	typedef	struct Pixel24
	{
		BYTE	r;
		BYTE	g;
		BYTE	b;
	} PIXEL24, *PPIXEL24;

	typedef	unsigned int	PIXEL, PIXEL32;
	typedef PIXEL			*PPIXEL, *PPIXEL32;
	typedef BYTE			PIXELCHANNEL, *PPIXELCHANNEL;

	typedef enum _ImageFileType
	{
		IFT_Unknown = 0,
		IFT_BMP_24,
		IFT_BMP_32,
		IFT_JPEG,
		IFT_PNG
	} IMAGEFILETYPE, *PIMAGEFILETYPE;

	typedef struct resolution
	{
		resolution() : width(0), height(0)
		{}

		resolution(const resolution& reso) :
			width(reso.width), height(reso.height)
		{}

		int		width;
		int		height;
	} RESOLUTION, *PRESOLUTION;
	
	_inline PIXELCHANNEL GetPixelAValue(PIXEL pixel)
	{
		return LOBYTE((pixel) >> 24);
	}

	_inline PIXELCHANNEL GetPixelRValue(PIXEL pixel)
	{
		return LOBYTE((pixel) >> 16);
	}

	_inline PIXELCHANNEL GetPixelGValue(PIXEL pixel)
	{
		return LOBYTE(((WORD)(pixel)) >> 8);
	}

	_inline PIXELCHANNEL GetPixelBValue(PIXEL pixel)
	{
		return LOBYTE(pixel);
	}

	_inline	PIXEL PixelRGB(BYTE r, BYTE g, BYTE b)
	{
		return (PIXEL)(((BYTE)(b) | ((WORD)((BYTE)(g)) << 8)) | (((DWORD)(BYTE)(r)) << 16) | (((DWORD)(BYTE)(0xff)) << 24));
	}

	_inline	PIXEL PixelARGB(BYTE a, BYTE r, BYTE g, BYTE b)
	{
		return (PIXEL)(((BYTE)(b) | ((WORD)((BYTE)(g)) << 8)) | (((DWORD)(BYTE)(r)) << 16) | (((DWORD)(BYTE)(a)) << 24));
	}




	// < IImage [class, abstract] >
	///	@classname	IImage
	///	@designer	Tankle L.
	///
	///	@brief		...
	/// @modified	Tankle L.	2015.11.6

	class IImage abstract
	{
	public:		// Constructors and Deconstructor.
		IImage();
		virtual ~IImage() = 0;

		IImage(const IImage& image) = delete;
		
	public:		// Useful Methods
		void					CopyFrom(IImage* const pImage);
		void					Blank();

	public:		// Inline Methods.
		inline PPIXEL			GetPixelBuffer() const
		{
			return _pBuffer;
		}

		inline PIXEL			GetPixel(const int& x, const int& y) const
		{
			PIXEL	pixel = 0;

			if (x >= _resolution.width ||
				y >= _resolution.height ||
				_pBuffer == nullptr)
				return pixel;

			return _pBuffer[x + y*_resolution.width];
		}

		inline int				GetImgWidth() const
		{
			return _resolution.width;
		}

		inline int				GetImgHeight() const
		{
			return _resolution.height;
		}

		inline void				GetImgResolution(RESOLUTION& reso) const
		{
			reso = _resolution;
		}

	public:		// Interfaces.
		virtual int				FromFile(const std::string& fileName) = 0;
		virtual int				ToFile(const std::string& fileName) = 0;

		virtual IMAGEFILETYPE	GetImageFileType() const = 0;
		
	protected:	// Standar Properties.
		PPIXEL			_pBuffer;
		RESOLUTION		_resolution;
	};

	// </ IImage >



	
	// < ImageBitmap24 [class, abstract] >
	///	@classname	ImageBitmap24
	///	@designer	Tankle L.
	///
	///	@brief		...
	/// @modified	Tankle L.	2015.11.6

	class ImageBitmap24 : public IImage
	{
	public:
		ImageBitmap24();
		ImageBitmap24(const RESOLUTION& reso);
		virtual ~ImageBitmap24();

	public:
		virtual int				FromFile(const std::string& fileName) override;
		virtual int				ToFile(const std::string& fileName) override;
		virtual IMAGEFILETYPE	GetImageFileType() const override;

	};

	// </ ImageBitmap24 >




	// < ImageBitmap32 [class, abstract] >
	///	@classname	ImageBitmap32
	///	@designer	Tankle L.
	///
	///	@brief		...
	/// @modified	Tankle L.	2015.11.6

	class ImageBitmap32 : public IImage
	{
	public:
		ImageBitmap32();
		ImageBitmap32(const RESOLUTION& reso);
		virtual ~ImageBitmap32();

	public:
		virtual int				FromFile(const std::string& fileName) override;
		virtual int				ToFile(const std::string& fileName) override;
		virtual IMAGEFILETYPE	GetImageFileType() const override;

	};

	// </ ImageBitmap32 >

}
