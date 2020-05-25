#ifndef __ADDON_H__
#define __ADDON_H__

#include "GameObject.h"
class CAddOn: public CGameObject{
//멤버 변수
private:
	list<fPOINT*> m_PlayerXY;			//플레이어의 좌표를 저장해놓기 위한 리스트
	const INFO* m_pPlayerInfo;			//플레이어의 INFO 구조체를 가리키기 위한 포인터 변수
	int m_iImageState;
//생성자 및 소멸자
public:
	explicit CAddOn();	
	virtual ~CAddOn();

//멤버 함수
	void SetInfo(const INFO& _info);

	void InitList();			//리스트에 초기값 push_back() 해주기 위한 함수
	void CreateBullet();

// CGameObject을(를) 통해 상속됨
private:
	virtual void Release() override;
public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC _hdc) override;
};

#endif // !__ADDON_H__
