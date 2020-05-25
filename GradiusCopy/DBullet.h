#ifndef __DBULLET_H__
#define __DBULLET_H__

#include "GameObject.h"
class CDBullet: public CGameObject{
//생성자 및 소멸자
public:
	explicit CDBullet();
	virtual ~CDBullet();

//CGameObject을(를) 통해 상속됨
private:
	virtual void Release() override;
public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC _hdc) override;
};

#endif // !__DBULLET_H__