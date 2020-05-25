#ifndef __GARUN_H__
#define __GARUN_H__

#include "Monster.h"

class Garun:public CMonster{
private:
	float m_fRadian;
	int m_iPosition;

public:
	explicit Garun();
	virtual ~Garun();

private:
	void PawnMoving();

private:
	virtual void Release() override;
public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;
};

#endif // !__GARUN_H__
