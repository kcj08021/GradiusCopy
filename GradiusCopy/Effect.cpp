#include "pch.h"
#include "Effect.h"

CEffect::CEffect(): m_enum(IMG_END), m_iImageState(0), m_iImageCount(0){
}

CEffect::~CEffect(){
	Release();
}

void CEffect::SetInfo(const INFO& _info){
	m_tInfo.fX = _info.fX;
	m_tInfo.fY = _info.fY;
}

void CEffect::SetEnum(OBJ_ENUM _enum){
	switch(_enum){
	case OBJ_PLAYER:
		m_enum = IMG_PLAYER_DEAD;
		m_tInfo.fCX = EFFECT_PLAYER_DEAD_CX;
		m_tInfo.fCY = EFFECT_PLAYER_DEAD_CY;
		m_iImageCount = 4;
		break;
	case OBJ_MONSTER:
		m_enum = IMG_ENEMY_DEAD;
		m_tInfo.fCX = EFFECT_ENEMY_DEAD_CX;
		m_tInfo.fCY = EFFECT_ENEMY_DEAD_CY;
		m_iImageCount = 3;
		break;
	case OBJ_BOSS:
		m_enum = IMG_BOSS_DEAD;
		m_tInfo.fCX = EFFECT_BOSS_DEAD_CX;
		m_tInfo.fCY = EFFECT_BOSS_DEAD_CY;
		m_iImageCount = 5;
		break;
	default:
		break;
	}

	CGameObject::UpdateRect();
}

void CEffect::Release(){

}

void CEffect::Initialize(){

}

int CEffect::Update(){
	++m_iImageState;
	if(EFFECT_SET_TIMING * m_iImageCount - 1 < m_iImageState){
		m_bIsDead = true;
	}

	CGameObject::UpdateRect();
	return m_bIsDead;
}

void CEffect::Render(HDC _hdc){
	if(CKeyManager::GetInstance()->IsKeyPressing(KEY_CHAR_A))
		Rectangle(_hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	TransparentBlt(_hdc, m_tRect.left, m_tRect.top, (int)m_tInfo.fCX, (int)m_tInfo.fCY,
				   CTextureManager::GetInstance()->GetTextureDC(m_enum), (int)m_tInfo.fCX * (m_iImageState / EFFECT_SET_TIMING), 0, (int)m_tInfo.fCX, (int)m_tInfo.fCY, RGB(255, 0, 255));
}
