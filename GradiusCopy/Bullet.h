#ifndef __BULLET_H__
#define __BULLET_H__

#include "GameObject.h"
class CBullet : public CGameObject {
//멤버 변수
private:

//생성자 및 소멸자
public:
	explicit CBullet();
	virtual ~CBullet();

//멤버 함수

// CGameObject을(를) 통해 상속됨
private:
	virtual void Release() override;
public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC _hdc) override;
};


#endif // !__BULLET_H__

