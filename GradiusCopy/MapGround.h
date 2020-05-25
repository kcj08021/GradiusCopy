#ifndef __MAPOBJECT_H__
#define __MAPOBJECT_H__

#include "GameObject.h"

class CMapGround: public CGameObject{
private:
	bool m_bIsMove;
public:
	explicit CMapGround();
	virtual ~CMapGround();

public:
	void SetIsMove(bool _bool);
	// CGameObject을(를) 통해 상속됨
private:
	virtual void Release() override;
public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC _hdc) override;
};

#endif // !__MAPOBJECT_H__