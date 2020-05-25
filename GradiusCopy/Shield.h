#ifndef __SHIELD_H__
#define __SHIELD_H__

#include "GameObject.h"
class CShield: public CGameObject{
private:
	const INFO* m_pPlayerInfo;			//플레이어의 INFO 구조체를 가리키기 위한 포인터
	int m_iImageState;					//이미지 변경을 위한 변수
	int m_iLastImagesatate;				//이미지 변경을 위한 변수
//생성자 및 소멸자
public:
	explicit CShield();
	virtual ~CShield();
//멤버 함수
public:
	void SetInfo(const INFO& _info);
// CGameObject을(를) 통해 상속됨
private:
	virtual void Release() override;
public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC _hdc) override;
};

#endif // !__SHIELD_H__