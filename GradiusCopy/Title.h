#ifndef __TITLE_H__
#define __TITLE_H__

#include "GameObject.h"
class CTitle:
	public CGameObject{
private:

public:
	explicit CTitle();
	virtual ~CTitle();

	// CGameObject��(��) ���� ��ӵ�
private:
	virtual void Release() override;
public:
	virtual void Initialize() override;

	virtual int Update() override;

	virtual void Render(HDC _hdc) override;

};

#endif // !__TITLE_H__
