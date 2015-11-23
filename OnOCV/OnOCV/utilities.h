///	@file		utilities.h
///	@brief		...
///	@licence	...
///	@designer	Tankle L.
///	@date		First created at < November 17th, 2015 >
///
///	@version	0.1.0
///
///	@programmer	Tankle L.
///	@programmer ...

#ifndef _UTILITIES_H
#define	_UTILITIES_H



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

_inline float	GetPixelBright(PIXEL px)
{
	return (((float)GetPixelRValue(px)) + ((float)GetPixelGValue(px)) + ((float)GetPixelBValue(px))) / 3.0f;
}

_inline float	GetPixelBright(BYTE r, BYTE g, BYTE b)
{
	return (((float)r) + ((float)g) + ((float)b)) / 3.0f;
}

_inline float	GetPixelBrightWithAlpha(BYTE a, BYTE r, BYTE g, BYTE b)
{
	return (((float)r) + ((float)g) + ((float)b)) / 3.0f *((float)a) / 255.0f;
}

_inline float	GetPixelBrightWithAlpha(PIXEL px)
{
	return (((float)GetPixelRValue(px)) + ((float)GetPixelGValue(px)) + ((float)GetPixelBValue(px))) / 3.0f *((float)GetPixelAValue(px)) /255.0f;
}

#endif // !_UTILITIES_H
