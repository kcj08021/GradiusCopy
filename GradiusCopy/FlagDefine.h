#ifndef __FLAGDEFINE_H__
#define __FLAGDEFINE_H__

//�÷��̾� ���� �÷��װ�
typedef unsigned short PLAYERFLAG;	//�÷��� �������� Ÿ�� ������(2����Ʈ)

#define PFLAG_NULL 0x0000
#define PFLAG_MOVE 0x0001
#define PFLAG_SHOT 0x0002
#define PFLAG_SPED 0x0004
#define PFLAG_MISL 0x0008
#define PFLAG_DOBL 0x0010
#define PFLAG_LASR 0x0020
#define PFLAG_ADON 0x0040
#define PFLAG_SHLD 0x0080
#define PFLAG_SHMS 0x0100	 //�̻����� �������� ����
#define PFLAG_DEAD 0x0200

//�Է�Ű�� ���� �÷���
typedef unsigned short KEYFLAG;		//�÷��� �������� Ÿ�� ������(2����Ʈ)

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
