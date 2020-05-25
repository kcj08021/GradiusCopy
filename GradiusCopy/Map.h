#ifndef __MAP_H__
#define __MAP_H__
#include "GameObject.h"

class CMap : public CGameObject{
private:
	float m_fMapScoll;
	bool m_bIsMapStop;
	float m_fCheckPoint;
public:
	explicit CMap();
	virtual ~CMap();
	// CGameObject을(를) 통해 상속됨

public:
	void SetIsMapStop(bool _bool);
	void SetCheckPoint();
	void LoadCheckPoint();
private:
	virtual void Release() override;
public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC _hdc) override;

};

#endif