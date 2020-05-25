#ifndef __PENCE_H__
#define __PENCE_H__
#include "Monster.h"

class Pence: public CMonster{
private:
	int m_Timer;
	int m_iTargetX;
	int m_iTargetY;
	bool IsBack;

public:
	explicit Pence();
	virtual ~Pence();

private:
	void PawnMoving();

private:
	virtual void Release() override;
public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;
};

#endif
