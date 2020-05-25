#include "pch.h"
#include "MapGround.h"

CMapGround::CMapGround(): m_bIsMove(false){
}

CMapGround::~CMapGround(){
	Release();
}

void CMapGround::SetIsMove(bool _bool){
	m_bIsMove = _bool;
}

void CMapGround::Release(){
}

void CMapGround::Initialize(){
	m_tInfo.fCX = MAPOBJ_GROUND_CX;
	m_tInfo.fCY = MAPOBJ_GROUND_CY;

	m_fSpeed = MAP_SCROLL_SPEED * 3.f;

	m_iHP = 0;

	CGameObject::UpdateRect();
}

int CMapGround::Update(){
	if(m_tInfo.fX > PLAYREGION_X / 2 && !m_bIsMove)
		m_tInfo.fX -= m_fSpeed;
	else if (m_tInfo.fX < PLAYREGION_X / 2 && !m_bIsMove){
		m_tInfo.fX = PLAYREGION_X / 2;
	}

	if(m_bIsMove)
		m_tInfo.fX -= m_fSpeed;

	CGameObject::UpdateRect();

	return 0;
}

void CMapGround::Render(HDC _hdc){
	if(CKeyManager::GetInstance()->IsKeyPressing(KEY_CHAR_A))
		Rectangle(_hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}
