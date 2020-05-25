#pragma once
#include "GameObject.h"
class CMissile: public CGameObject{
private:
	bool m_bIsGround;
	int m_iImageState;
//생성자 및 소멸자
public:
	explicit CMissile();
	virtual ~CMissile();
	
// CGameObject을(를) 통해 상속됨
private:
	virtual void Release() override;
public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC _hdc) override;
};

