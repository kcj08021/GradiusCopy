#ifndef __UI_MANAGER_H__
#define __UI_MANAGER_H__
#include "GameObject.h"

class CUI: public CGameObject{
//��� ����
private:
	int m_iSelect;						//UI������ ���� ����
	bool m_bIsPossibleActive[6];		//UI������ ���� bool �迭
//������ �� �Ҹ���
public:
	explicit CUI();
	virtual ~CUI();

//��� �Լ�
private:
	bool ActivateUI(UI_VALUE _val) const;
	void UISetting(int _iVal);

public:
	void MoveCursor();					//������ ȹ��� Ŀ�� �̵��� ���� �Լ�

// CGameObject��(��) ���� ��ӵ�
private:
	virtual void Release();
public:
	virtual void Initialize();
	virtual int Update();	
	virtual void Render(HDC _hdc);
};

#endif // !__UI_MANAGER_H__