#include "pch.h"
#include "Pence.h"

Pence::Pence(): m_Timer(0), m_iTargetX(0), m_iTargetY(0), IsBack(0){

}

Pence::~Pence(){
	Release();
}

void Pence::PawnMoving(){
	const INFO& PlayerInfo = CObjectManager::GetInstance()->GetPlayer()->GetInfo();

	if(!IsBack){
		m_iTargetX = static_cast<int>(PlayerInfo.fX)+100;
		m_tInfo.fX -= m_fSpeed;
		if(m_iTargetX >= m_tInfo.fX){
			m_iTargetY = static_cast<int>(PlayerInfo.fY);
			IsBack = true;
		}
	} else{
		if(m_iTargetY == m_tInfo.fY){
			m_tInfo.fX += m_fSpeed;
		} else{
			if(abs(static_cast<int>(m_tInfo.fY) - m_iTargetY) < 5.f)
				m_tInfo.fY = m_iTargetY;
			if(m_iTargetY > m_tInfo.fY){
				m_tInfo.fY += m_fSpeed;
				m_tInfo.fX += m_fSpeed / 2.f;
			} else{
				m_tInfo.fY -= m_fSpeed;
				m_tInfo.fX += m_fSpeed / 2.f;
			}
		}
	}
}

void Pence::Release(){
}

void Pence::Initialize(){
	m_tInfo.fCX = MONSTER_PENCE_CX;
	m_tInfo.fCY = MONSTER_PENCE_CY;
	if(nullptr != CObjectManager::GetInstance()->GetPlayer()){
		const INFO& PlayerInfo = CObjectManager::GetInstance()->GetPlayer()->GetInfo();

		m_iTargetX = PlayerInfo.fX;
	}
	m_fSpeed = MONSTER_PENCE_SPEED;

	CTextureManager::GetInstance()->AddTexture(STRING_IMG_MONSTER_PENCE, IMG_PENCE);
}

int Pence::Update(){
	if(nullptr != CObjectManager::GetInstance()->GetPlayer()){
		if(m_bIsDead)
			return m_bIsDead;

		PawnMoving();

		m_Timer = m_Timer < IMAGE_SET_TIMING * 3 - 1 ? m_Timer + 1 : 0;
	}
	return m_bIsDead;
}

void Pence::Render(HDC hDC){
	CGameObject::UpdateRect();
	if(CKeyManager::GetInstance()->IsKeyPressing(KEY_CHAR_A))
		Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	TransparentBlt(hDC, m_tRect.left, m_tRect.top, m_tInfo.fCX, m_tInfo.fCY, 
					  CTextureManager::GetInstance()->GetTextureDC(IMG_PENCE), 0 + (MONSTER_PENCE_CX * (m_Timer / IMAGE_SET_TIMING)), 0, 39, 39, RGB(255, 0, 255));
}

