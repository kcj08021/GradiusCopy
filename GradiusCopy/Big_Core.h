#pragma once
#include "Monster.h"

class Big_Core:public CMonster
{
public:
	explicit Big_Core();
	virtual ~Big_Core();

public:
	// CGameObject��(��) ���� ��ӵ�
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;

private:
	virtual void Release() override;

public:
	void BossMoving();
	bool BulletFire();

private:
	int m_Cooltime;

};

