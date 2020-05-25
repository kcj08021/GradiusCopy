#ifndef __DBULLET_H__
#define __DBULLET_H__

#include "GameObject.h"
class CDBullet: public CGameObject{
//������ �� �Ҹ���
public:
	explicit CDBullet();
	virtual ~CDBullet();

//CGameObject��(��) ���� ��ӵ�
private:
	virtual void Release() override;
public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC _hdc) override;
};

#endif // !__DBULLET_H__