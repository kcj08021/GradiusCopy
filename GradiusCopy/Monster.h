#pragma once
#include "GameObject.h"
class CMonster :
	public CGameObject
{
public:
	explicit CMonster();
	virtual ~CMonster();

public:
	// CGameObject을(를) 통해 상속됨
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;

private:
	virtual void Release() override;

private:
	void IsMoving();

public:

private:
	CGameObject*	m_pTarget;
};

