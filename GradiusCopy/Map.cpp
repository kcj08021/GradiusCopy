#include "pch.h"
#include "Map.h"

CMap::CMap(): m_fMapScoll(0.f), m_bIsMapStop(false), m_fCheckPoint(0.f){

}

CMap::~CMap(){

}

void CMap::SetIsMapStop(bool _bool){
	m_bIsMapStop = _bool;
}

void CMap::SetCheckPoint(){
	m_fCheckPoint = m_fMapScoll;
}

void CMap::LoadCheckPoint(){
	m_fMapScoll = m_fCheckPoint;
}

void CMap::Release(){

}

void CMap::Initialize(){
	m_fSpeed = MAP_SCROLL_SPEED;

	CTextureManager::GetInstance()->AddTexture(STRING_IMG_MAP, IMG_MAP);
}

int CMap::Update(){
	if(m_fMapScoll > 3324)
		m_fMapScoll -= 3324;
	if(!m_bIsMapStop)
		m_fMapScoll = m_fMapScoll + m_fSpeed;

	return 0;
}

void CMap::Render(HDC _hdc){
	StretchBlt(_hdc, 0, 0, WINCX, WINCY, CTextureManager::GetInstance()->GetTextureDC(IMG_MAP), int(m_fMapScoll), 0, 256, 240, SRCCOPY);
}
