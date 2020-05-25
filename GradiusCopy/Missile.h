#pragma once
#include "GameObject.h"
class CMissile: public CGameObject{
private:
	bool m_bIsGround;
	int m_iImageState;
//������ �� �Ҹ���
public:
	explicit CMissile();
	virtual ~CMissile();
	
// CGameObject��(��) ���� ��ӵ�
private:
	virtual void Release() override;
public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC _hdc) override;
};

