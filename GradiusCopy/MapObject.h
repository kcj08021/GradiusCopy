#ifndef __MAP_OBJECT_H__
#define __MAP_OBJECT_H__

#include "GameObject.h"
class CMapObject: public CGameObject{
private:
	bool m_bIsMove;
public:
	explicit CMapObject();
	virtual ~CMapObject();

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

#endif // !__MAP_OBJECT_H__

