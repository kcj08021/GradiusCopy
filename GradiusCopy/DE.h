#ifndef __DE_H__
#define __DE_H__

#include "Monster.h"

class DE: public CMonster{
private:
	int m_iCooltime;
	int m_iTimer;
	int m_iPosition;

public:
	explicit DE();
	virtual ~DE();

private:
	void PawnMoving();
	void Attack();
	void CalculatePosition();
	void CalculateAngle();

private:
	virtual void Release() override;
public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;
};

#endif // !__DE_H__
