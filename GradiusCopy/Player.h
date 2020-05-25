#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "GameObject.h"
class CPlayer : public CGameObject {
//��� ����
private:
	PLAYERFLAG m_Flag;
	int m_iImageState;
	float m_fSpeedUp;
	RECT DisplayRect;

//������ �� �Ҹ���
public:
	explicit CPlayer();
	virtual ~CPlayer();

//��� �Լ�
private:
	void KeyInput();
	void CreateBullet();
	bool CreateAddOn();
	bool CreateShield();

public:
	const PLAYERFLAG& GetFlag() const;
	bool SetFlag(PLAYERFLAG _flag);

//CGameObject��(��) ���� ��ӵ�
private:
	virtual void Release() override;

public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC _hdc) override;
};

#endif //!__PLAYER_H__