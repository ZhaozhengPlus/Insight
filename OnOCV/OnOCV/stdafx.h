// stdafx.h : ��׼ϵͳ�����ļ��İ����ļ���
// ���Ǿ���ʹ�õ��������ĵ�
// �ض�����Ŀ�İ����ļ�
//

#pragma once
#pragma warning(disable:4819)

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>

#include <opencv2/opencv.hpp>

// TODO:  �ڴ˴����ó�����Ҫ������ͷ�ļ�

#include <iostream>
#include <fstream>

#ifdef _DEBUG

#pragma comment(lib, "opencv_ts300d.lib")
#pragma comment(lib, "opencv_world300d.lib")
#pragma comment(lib, "opencv_core300d.lib")

#else	// Release

#pragma comment(lib, "opencv_ts300.lib")
#pragma comment(lib, "opencv_world300.lib")
#pragma comment(lib, "opencv_core300.lib")

#endif // _DEBUG