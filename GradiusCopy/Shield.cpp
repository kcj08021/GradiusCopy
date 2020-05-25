#include "pch.h"
#include "Shield.h"
#include "Player.h"

CShield::CShield(): m_pPlayerInfo(nullptr), m_iImageState(0), m_iLastImagesatate(0){}

CShield::~CShield(){
	Release();
}

void CShield::SetInfo(const INFO& _info){
	m_pPlayerInfo = &_info;

	CGameObject::SetPos(_info.fX + SHILED_DIST, _info.fY);
}

void CShield::Release(){
	dynamic_cast<CPlayer*>(CObjectManager::GetInstance()->GetPlayer())->SetFlag(PFLAG_SHLD);
}

void CShield::Initialize(){
	m_tInfo.fCX = SHIELD_CX;
	m_tInfo.fCY = SHILED_CY;

	m_iHP = 5;

	CGameObject::UpdateRect();
	CTextureManager::GetInstance()->AddTexture(STRING_IMG_SHIELD, IMG_SHIELD);
}

int CShield::Update(){
	if(m_bIsDead)
		return m_bIsDead;

	if(m_iHP == 1)
		m_iLastImagesatate = 1;

	//폭탄은 이미지 4장, 각 0.2초씩 출력(0.8초뒤 첫 이미지로)
	m_iImageState = m_iImageState < IMAGE_SET_TIMING*4 -1 ? m_iImageState + 1 : 0;
	
	if(nullptr != CObjectManager::GetInstance()->GetPlayer()){
	//플레이어의 위치에서 적당한 거리를 유지하며 움직임
		m_tInfo.fX = m_pPlayerInfo->fX + SHILED_DIST;
		m_tInfo.fY = m_pPlayerInfo->fY;
	}
	CGameObject::UpdateRect();
	return m_bIsDead;
}

void CShield::Render(HDC _hdc){
	if(CKeyManager::GetInstance()->IsKeyPressing(KEY_CHAR_A))
		Rectangle(_hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	TransparentBlt(_hdc, m_tRect.left, m_tRect.top, (int)SHIELD_CX, (int)SHILED_CY, 
				   CTextureManager::GetInstance()->GetTextureDC(IMG_SHIELD), int(SHIELD_CX * (m_iImageState / IMAGE_SET_TIMING) + (m_iLastImagesatate * 120)), 0, (int)SHIELD_CX, (int)SHILED_CY, RGB(255, 0, 255));
}

