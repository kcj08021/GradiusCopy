#ifndef __FLAGDEFINE_H__
#define __FLAGDEFINE_H__

//플레이어 상태 플래그값
typedef unsigned short PLAYERFLAG;	//플래그 저장위한 타입 재정의(2바이트)

#define PFLAG_NULL 0x0000
#define PFLAG_MOVE 0x0001
#define PFLAG_SHOT 0x0002
#define PFLAG_SPED 0x0004
#define PFLAG_MISL 0x0008
#define PFLAG_DOBL 0x0010
#define PFLAG_LASR 0x0020
#define PFLAG_ADON 0x0040
#define PFLAG_SHLD 0x0080
#define PFLAG_SHMS 0x0100	 //미사일을 쐈을때의 판정
#define PFLAG_DEAD 0x0200

//입력키에 대한 플래그
typedef unsigned short KEYFLAG;		//플래그 저장위한 타입 재정의(2바이트)

#define KEY_NULL 0x0000
#define KEY_UP 0x0001
#define KEY_DOWN 0x0002
#define KEY_LEFT 0x0004
#define KEY_RIGHT 0x0008
#define KEY_CHAR_X 0x0010
#define KEY_CHAR_Z 0x0020
#define KEY_CHAR_C 0X0040
#define KEY_CHAR_A 0x0080
#define KEY_CHAR_S 0x0100

#endif // !__FLAGDEFINE_H__
