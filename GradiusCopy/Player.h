#ifndef __PLAYER_H__
#define __PLAYER_H__
#include "GameObject.h"
class CPlayer : public CGameObject {
//멤버 변수
private:
	PLAYERFLAG m_Flag;
	int m_iImageState;
	float m_fSpeedUp;
	RECT DisplayRect;

//생성자 및 소멸자
public:
	explicit CPlayer();
	virtual ~CPlayer();

//멤버 함수
private:
	void KeyInput();
	void CreateBullet();
	bool CreateAddOn();
	bool CreateShield();

public:
	const PLAYERFLAG& GetFlag() const;
	bool SetFlag(PLAYERFLAG _flag);

//CGameObject을(를) 통해 상속됨
private:
	virtual void Release() override;

public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC _hdc) override;
};

#endif //!__PLAYER_H__