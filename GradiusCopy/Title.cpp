#include "pch.h"
#include "Title.h"
#include "Title2.h"
#include "Player.h"
#include "Map.h"
#include "UI.h"

CTitle::CTitle(){

}

CTitle::~CTitle(){
	Release();
}

void CTitle::Release(){
	CGameObject* pObj = CAbstractFactory<CMap>::CreateObject();
	CObjectManager::GetInstance()->AddObject(OBJ_MAP, pObj);

	pObj = CAbstractFactory<CUI>::CreateObject();
	CObjectManager::GetInstance()->AddObject(OBJ_UI, pObj);

	pObj = CAbstractFactory<CPlayer>::CreateObject();
	CObjectManager::GetInstance()->AddObject(OBJ_PLAYER, pObj);
}

void CTitle::Initialize(){
	m_tInfo.fCX = WINCX;
	m_tInfo.fCY = WINCY;
	m_tInfo.fX = -WINCX / 2;
	m_tInfo.fY = WINCY / 2;

	m_fSpeed = MAP_SCROLL_SPEED * 6.f;

	CGameObject::UpdateRect();

	CTextureManager::GetInstance()->AddTexture(STRING_IMG_TITLE1, IMG_TITLE1);
}

int CTitle::Update(){
	if(m_bIsDead)
		return m_bIsDead;

	if(CKeyManager::GetInstance()->IsKeyDown(KEY_CHAR_Z))
	{
		OBJLIST::iterator iter = CObjectManager::GetInstance()->GetObjectList(OBJ_UI).begin();
		++iter;
		if(m_tInfo.fX != WINCX / 2){
			m_tInfo.fX = WINCX / 2;

			dynamic_cast<CTitle2*>(*iter)->SetIsTitleSkip(true);
		}
		else{
			dynamic_cast<CTitle2*>(*iter)->SetIsGameStart(true);
		}
	}

	if(m_tInfo.fX < WINCX / 2)
		m_tInfo.fX += m_fSpeed;
	else
		m_tInfo.fX = WINCX / 2;

	
	CGameObject::UpdateRect();

	return m_bIsDead;
}

void CTitle::Render(HDC _hdc){
	StretchBlt(_hdc, m_tRect.left, m_tRect.top, WINCX, WINCY,
			   CTextureManager::GetInstance()->GetTextureDC(IMG_TITLE1), 0, 0, 256, 240, SRCCOPY);
}
