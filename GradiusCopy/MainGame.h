#ifndef __MAINGAME_H__
#define __MAINGAME_H__

class CUI;

class CMainGame{
//멤버 변수
private:
	HDC m_hdc;
	HDC m_memDC;
	CUI* m_UI;
	int m_iCount;
	bool m_bGameStart;

//생성자 및 소멸자
public:
	explicit CMainGame();
	virtual ~CMainGame();
	 
//멤버함수
private:
	void Release();	

public:
	void Initialize();
	int Update();	
	void Render();

};

#endif // !__MAINGAME_H__
