#ifndef __SHIELD_H__
#define __SHIELD_H__

#include "GameObject.h"
class CShield: public CGameObject{
private:
	const INFO* m_pPlayerInfo;			//�÷��̾��� INFO ����ü�� ����Ű�� ���� ������
	int m_iImageState;					//�̹��� ������ ���� ����
	int m_iLastImagesatate;				//�̹��� ������ ���� ����
//������ �� �Ҹ���
public:
	explicit CShield();
	virtual ~CShield();
//��� �Լ�
public:
	void SetInfo(const INFO& _info);
// CGameObject��(��) ���� ��ӵ�
private:
	virtual void Release() override;
public:
	virtual void Initialize() override;
	virtual int Update() override;
	virtual void Render(HDC _hdc) override;
};

#endif // !__SHIELD_H__