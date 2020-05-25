#ifndef __BOOM_H__
#define __BOOM_H__
#include "GameObject.h"

class CBoom: public CGameObject{
private:
	int m_iImageState;
public:
	explicit CBoom();
	virtual ~CBoom();


	// CGameObject을(를) 통해 상속됨
private:
	virtual void Release() override;
public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC _hdc) override;

};
#endif // !__BOOM_H__
