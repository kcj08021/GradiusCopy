#include "pch.h"
#include "Boom.h"

CBoom::CBoom(): m_iImageState(0){
	
}

CBoom::~CBoom(){
	Release();
}

void CBoom::Release(){
	if(m_bIsDead)
		for(CGameObject* elem : CObjectManager::GetInstance()->GetObjectList(OBJ_MONSTER))
			elem->SetDead(true);
}

void CBoom::Initialize(){
	m_tInfo.fCX = BOOM_CX;
	m_tInfo.fCY = BOOM_CY;

	m_fSpeed = BOOM_SPEED;

	m_iDamage = 0;
	m_iHP = 0;

	CTextureManager::GetInstance()->AddTexture(STRING_IMG_BOOM, IMG_BOOM);

	CGameObject::UpdateRect();
}

int CBoom::Update(){
	if(m_bIsDead)
		return m_bIsDead;

	//폭탄은 이미지 3장, 각 0.2초씩 출력(0.6초뒤 첫 이미지로)
	m_iImageState = m_iImageState < 59 ? m_iImageState + 1 : 0;
	m_tInfo.fX -= m_fSpeed;

	CGameObject::UpdateRect();
	return m_bIsDead;
}

void CBoom::Render(HDC _hdc){
	if(CKeyManager::GetInstance()->IsKeyPressing(KEY_CHAR_A))
		Rectangle(_hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	TransparentBlt(_hdc, m_tRect.left, m_tRect.top, (int)BOOM_CX, (int)BOOM_CY, 
				   CTextureManager::GetInstance()->GetTextureDC(IMG_BOOM), ((int)BOOM_CX * (m_iImageState / 20)), 0, (int)BOOM_CX, (int)BOOM_CY, RGB(255, 0, 255));
}
