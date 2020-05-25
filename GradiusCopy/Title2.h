#pragma once
#include "GameObject.h"
class CTitle2: public CGameObject{
private:
	bool m_bGameStart;
	bool m_bImageOnOff;
	int m_iCount;
	bool m_bTitleSkip;

public:
	explicit CTitle2();
	virtual ~CTitle2();

public:
	void SetIsTitleSkip(bool _bool);
	void SetIsGameStart(bool _bool);

	// CGameObject을(를) 통해 상속됨
private:
	virtual void Release() override;
public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC _hdc) override;
};

