#ifndef __BULLET_H__
#define __BULLET_H__

#include "GameObject.h"
class CBullet : public CGameObject {
//��� ����
private:

//������ �� �Ҹ���
public:
	explicit CBullet();
	virtual ~CBullet();

//��� �Լ�

// CGameObject��(��) ���� ��ӵ�
private:
	virtual void Release() override;
public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC _hdc) override;
};


#endif // !__BULLET_H__

