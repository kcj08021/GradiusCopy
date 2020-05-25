#ifndef __DUCKER_H__
#define __DUCKER_H__

#include "Monster.h"

class Ducker:public CMonster{
private:
	float m_radian;
	float m_Cooltime;
	bool m_bMoveEnd;
	int m_position;
	int m_Timer;
	int m_iCount;
public:
	explicit Ducker();
	virtual ~Ducker();

private:
	void PawnMoving();
	void CalculatePosition();
	bool Attack();

private:
	virtual void Release() override;
public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;
};

#endif // !__DUCKER_H__
