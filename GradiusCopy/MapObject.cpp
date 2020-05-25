#include "pch.h"
#include "MapObject.h"

CMapObject::CMapObject(): m_bIsMove(false){
}

CMapObject::~CMapObject(){
	Release();
}

void CMapObject::SetIsMove(bool _bool){
	m_bIsMove = _bool;
}

void CMapObject::Release(){

}


void CMapObject::Initialize(){
	m_tInfo.fCX = MAPOBJ_OBJECT_CX;
	m_tInfo.fCY = MAPOBJ_OBJECT_CY;

	m_fSpeed = MAP_SCROLL_SPEED * 3.f;

	m_bIsMove = true;
	CGameObject::UpdateRect();
}

int CMapObject::Update(){
	if(m_bIsMove)
		m_tInfo.fX -= m_fSpeed;

	CGameObject::UpdateRect();

	return 0;
}

void CMapObject::Render(HDC _hdc){
	if(CKeyManager::GetInstance()->IsKeyPressing(KEY_CHAR_A))
		Rectangle(_hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}
