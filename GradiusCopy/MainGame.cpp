#include "pch.h"
#include "MainGame.h"
#include "Title.h"
#include "Title2.h"

CMainGame::CMainGame(): m_iCount(0){
	INIT_STRUCT(m_hdc);
}

CMainGame::~CMainGame(){
	Release();
}

void CMainGame::Release(){
	DeleteDC(m_memDC);
	ReleaseDC(g_hWnd, m_hdc);

	CObjectManager::DestroyInstance();
	CKeyManager::DestroyInstance();
	CTextureManager::DestroyInstance();
}

void CMainGame::Initialize(){
	CObjectManager::GetInstance();
	CKeyManager::GetInstance();
	CTextureManager::GetInstance();
	CEffectManager::GetInstance()->Initialize();
	PatternMgr::GetInstance();


	m_hdc = GetDC(g_hWnd);
	m_memDC = CTextureManager::GetInstance()->SetDC(m_hdc);

	CGameObject* pObj = nullptr;

	pObj = CAbstractFactory<CTitle>::CreateObject();
	CObjectManager::GetInstance()->AddObject(OBJ_UI, pObj);

	pObj = CAbstractFactory<CTitle2>::CreateObject();
	CObjectManager::GetInstance()->AddObject(OBJ_UI, pObj);
}

int CMainGame::Update(){
	CKeyManager::GetInstance()->Update();
	CObjectManager::GetInstance()->Update(); 
	
	
	if(CObjectManager::GetInstance()->GetObjectList(OBJ_MAP).size() == 1){
		m_bGameStart = true;
		PatternMgr::GetInstance()->Update();
	}

	if(nullptr == CObjectManager::GetInstance()->GetPlayer() && m_bGameStart){
		m_iCount += 1;
		if(50 < m_iCount){
			CObjectManager::GetInstance()->LoadCheckPoint();
			m_iCount = 0;
		}
	}

	return 0;
}

void CMainGame::Render(){

	CObjectManager::GetInstance()->Render(m_memDC);

	BitBlt(m_hdc, 0, 0, WINCX, WINCY, m_memDC, 0, 0, SRCCOPY);
}
