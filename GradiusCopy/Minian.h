#pragma once
#include "Monster.h"

class Minian :public CMonster
{
public:
	void PawnMoving();
	void MinutePower();

public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;


private:
	virtual void Release() override;

private:
	float m_MinutePower;
	float m_toward;
};

