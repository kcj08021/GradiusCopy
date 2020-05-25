#include "pch.h"
#include "Title2.h"

CTitle2::CTitle2(): m_bGameStart(false),m_bImageOnOff(false), m_iCount(0) , m_bTitleSkip(false){
}

CTitle2::~CTitle2(){
	CTitle2::Release();
}

void CTitle2::SetIsTitleSkip(bool _bool){
	m_bTitleSkip = _bool;
}

void CTitle2::SetIsGameStart(bool _bool){
	m_bGameStart = _bool;
}

void CTitle2::Release(){
	CObjectManager::GetInstance()->GetObjectList(OBJ_UI).front()->SetDead(true);
}

void CTitle2::Initialize(){
	m_tInfo.fCX = TITLE2_CX;
	m_tInfo.fCY = TITLE2_CY;
	m_tInfo.fX = -WINCX / 2;
	m_tInfo.fY = WINCY / 2 + 50;

	m_fSpeed = MAP_SCROLL_SPEED * 6.f;

	m_bImageOnOff = true;

	CGameObject::UpdateRect();

	CTextureManager::GetInstance()->AddTexture(STRING_IMG_TITLE2, IMG_TITLE2);
	CTextureManager::GetInstance()->AddTexture(STRING_IMG_PLAYER, IMG_PLAYER);
}

int CTitle2::Update(){

	if(m_bIsDead)
		return m_bIsDead;

	if(!m_bGameStart){
		if(m_tInfo.fX < WINCX / 2)
			m_tInfo.fX += m_fSpeed;
		else
			m_tInfo.fX = WINCX / 2;

		if(m_bTitleSkip)
			m_tInfo.fX = WINCX / 2;
	} else{
		++m_iCount;
		if(!(m_iCount % IMAGE_SET_TIMING))
			m_bImageOnOff = !m_bImageOnOff;

		if(50 < m_iCount)
			m_bIsDead = true;
	}

	CGameObject::UpdateRect();

	return m_bIsDead;
}

void CTitle2::Render(HDC _hdc){
	if(m_bImageOnOff)
		BitBlt(_hdc, m_tRect.left, m_tRect.top, TITLE2_CX, TITLE2_CY,
			  CTextureManager::GetInstance()->GetTextureDC(IMG_TITLE2), 0, 0, SRCCOPY);
	
	TransparentBlt(_hdc, m_tRect.left - 100, m_tRect.top, PLAYER_CX, PLAYER_CY,
				   CTextureManager::GetInstance()->GetTextureDC(IMG_PLAYER), 0, 0, PLAYER_CX, PLAYER_CY, RGB(255, 0, 255));
}

