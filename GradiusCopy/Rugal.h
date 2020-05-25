#ifndef __RUGAL_H__
#define __RUGAL_H__
#include "Monster.h"

class Rugal:public CMonster{
private:
	int	m_iPosition;

public:
	explicit Rugal();
	virtual ~Rugal();
private:
	void PawnMoving();

private:
	virtual void Release() override;
public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;
};



#endif // !__RUGAL_H__

