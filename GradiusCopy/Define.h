#ifndef __DEFINE_H__
#define __DEFINE_H__

#include "FlagDefine.h"
#include "ObjectDefine.h"
#include "KeyCodeDefine.h"
#include "ImageWStringDefine.h"

//윈도우 크기
#define WINCX 768
#define WINCY 720
#define GAP 0
#define PLAYREGION_X WINCX
#define PLAYREGION_Y 600

//매크로 상수 선언
#define PI 3.141592f
#define G_Gravity 3.f

//매크로 함수
#define INIT_STRUCT(tag) memset(&tag,0,sizeof(tag))		//구조체 초기화
#define INIT_ARRAY(arr) memset(arr,0,sizeof(arr))		//배열 초기화
#define SQUERE(tag) (tag * tag)							//제곱
#define RADIAN(degree) (degree * PI / 180.f)			//각도->라디안 변환
#define DEGREE(radian) (radian * 180.f / PI)			//라디안->각도 변환

#endif // !__DEFINE_H__
