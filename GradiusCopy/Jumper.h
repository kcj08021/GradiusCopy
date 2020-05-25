#ifndef __JUMPER_H__
#define __JUMPER_H__
#include "Monster.h"

class Jumper :public CMonster
{
private:
	int m_iHighest;
	int m_iGround;
	int m_iPosition;

public:
	explicit Jumper();
	virtual ~Jumper();

private:
	void PawnMoving();
	void Jumping();

private:
	virtual void Release() override;

public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;

};

#endif // !__JUMPER_H__