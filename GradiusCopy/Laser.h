#ifndef __LASER_H__
#define __LASER_H__

#include "GameObject.h"
class CLaser: public CGameObject{
//멤버 변수
private:
	const INFO* m_pPlayerInfo;		//플레이어의 INFO 구조체를 가리키기 위한 포인터

//생성자 및 소멸자
public:
	explicit CLaser();
	virtual ~CLaser();

//멤버 함수
	void SetInfo(const INFO& _info);
	

// CGameObject을(를) 통해 상속됨
private:
	virtual void Release() override;
public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC _hdc) override;
};


#endif // !__LASER_H__


