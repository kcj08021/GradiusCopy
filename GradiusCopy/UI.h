#ifndef __UI_MANAGER_H__
#define __UI_MANAGER_H__
#include "GameObject.h"

class CUI: public CGameObject{
//멤버 변수
private:
	int m_iSelect;						//UI선택을 위한 변수
	bool m_bIsPossibleActive[6];		//UI구분을 위한 bool 배열
//생성자 및 소멸자
public:
	explicit CUI();
	virtual ~CUI();

//멤버 함수
private:
	bool ActivateUI(UI_VALUE _val) const;
	void UISetting(int _iVal);

public:
	void MoveCursor();					//아이템 획득시 커서 이동을 위한 함수

// CGameObject을(를) 통해 상속됨
private:
	virtual void Release();
public:
	virtual void Initialize();
	virtual int Update();	
	virtual void Render(HDC _hdc);
};

#endif // !__UI_MANAGER_H__