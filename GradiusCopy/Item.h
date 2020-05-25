#ifndef __ITEM_H__
#define __ITEM_H__

#include "GameObject.h"

class CItem: public CGameObject{
private:
	int m_iImageState;

public:
	explicit CItem();
	virtual ~CItem();

	// CGameObject을(를) 통해 상속됨
private:
	virtual void Release() override;
public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC _hdc) override;
};
#endif // !__ITEM_H__
