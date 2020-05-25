#ifndef __ADDON_H__
#define __ADDON_H__

#include "GameObject.h"
class CAddOn: public CGameObject{
//��� ����
private:
	list<fPOINT*> m_PlayerXY;			//�÷��̾��� ��ǥ�� �����س��� ���� ����Ʈ
	const INFO* m_pPlayerInfo;			//�÷��̾��� INFO ����ü�� ����Ű�� ���� ������ ����
	int m_iImageState;
//������ �� �Ҹ���
public:
	explicit CAddOn();	
	virtual ~CAddOn();

//��� �Լ�
	void SetInfo(const INFO& _info);

	void InitList();			//����Ʈ�� �ʱⰪ push_back() ���ֱ� ���� �Լ�
	void CreateBullet();

// CGameObject��(��) ���� ��ӵ�
private:
	virtual void Release() override;
public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC _hdc) override;
};

#endif // !__ADDON_H__
