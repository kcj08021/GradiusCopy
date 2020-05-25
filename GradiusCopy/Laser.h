#ifndef __LASER_H__
#define __LASER_H__

#include "GameObject.h"
class CLaser: public CGameObject{
//��� ����
private:
	const INFO* m_pPlayerInfo;		//�÷��̾��� INFO ����ü�� ����Ű�� ���� ������

//������ �� �Ҹ���
public:
	explicit CLaser();
	virtual ~CLaser();

//��� �Լ�
	void SetInfo(const INFO& _info);
	

// CGameObject��(��) ���� ��ӵ�
private:
	virtual void Release() override;
public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC _hdc) override;
};


#endif // !__LASER_H__


