#ifndef __MAINGAME_H__
#define __MAINGAME_H__

class CUI;

class CMainGame{
//��� ����
private:
	HDC m_hdc;
	HDC m_memDC;
	CUI* m_UI;
	int m_iCount;
	bool m_bGameStart;

//������ �� �Ҹ���
public:
	explicit CMainGame();
	virtual ~CMainGame();
	 
//����Լ�
private:
	void Release();	

public:
	void Initialize();
	int Update();	
	void Render();

};

#endif // !__MAINGAME_H__
