#pragma once
#include "GameObject.h"
class EnemyBullet: public CGameObject{

private:
	BULLIT_TYPE	m_eType;

public:
	EnemyBullet();
	virtual ~EnemyBullet();
private:
	void IsMoving();

public:
	void SetType(BULLIT_TYPE eDir);
	// CGameObject��(��) ���� ��ӵ�
private:
	virtual void Release() override;
public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC hDC) override;


};

