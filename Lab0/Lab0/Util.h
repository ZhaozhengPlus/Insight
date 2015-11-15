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

#define	SAFE_RELEASE(pObj)			{if(nullptr != pObj) {(pObj)->Release(); pObj = nullptr;}}
#define	SAFE_DELETE(pObj)			{if(nullptr != pObj) {delete pObj; pObj = NULL;}}
#define SAFE_DELETE_ARRAY(pObj)		{if(nullptr != pObj) {delete[] pObj; pObj = NULL;}}
#define SAFE_FREE(pObj)				{if(nullptr != pObj) {free(pObj); pObj = NULL;}}
#define	SAFE_CLOSEHANDLE(pObj)		{if(nullptr != pObj || INVALID_HANDLE_VALUE != pObj) {CloseHandle(pObj); pObj = NULL;}}