#ifndef __DEFINE_H__
#define __DEFINE_H__

#include "FlagDefine.h"
#include "ObjectDefine.h"
#include "KeyCodeDefine.h"
#include "ImageWStringDefine.h"

//������ ũ��
#define WINCX 768
#define WINCY 720
#define GAP 0
#define PLAYREGION_X WINCX
#define PLAYREGION_Y 600

//��ũ�� ��� ����
#define PI 3.141592f
#define G_Gravity 3.f

//��ũ�� �Լ�
#define INIT_STRUCT(tag) memset(&tag,0,sizeof(tag))		//����ü �ʱ�ȭ
#define INIT_ARRAY(arr) memset(arr,0,sizeof(arr))		//�迭 �ʱ�ȭ
#define SQUERE(tag) (tag * tag)							//����
#define RADIAN(degree) (degree * PI / 180.f)			//����->���� ��ȯ
#define DEGREE(radian) (radian * 180.f / PI)			//����->���� ��ȯ

#endif // !__DEFINE_H__
