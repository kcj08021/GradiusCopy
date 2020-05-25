#ifndef __EFFECT_H__
#define __EFFECT_H__
#include "GameObject.h"

class CEffect: public CGameObject{
private:
	IMG_ENUM m_enum;
	int m_iImageState;
	int m_iImageCount;
public:
	explicit CEffect();
	virtual ~CEffect();
public:
	void SetInfo(const INFO& _info);
	void SetEnum(OBJ_ENUM _enum);

	// CGameObject을(를) 통해 상속됨
private:
	virtual void Release() override;
public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC _hdc) override;

};
#endif // !__EFFECT_H__
