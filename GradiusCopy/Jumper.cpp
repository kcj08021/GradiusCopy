#include "pch.h"
#include "Jumper.h"

Jumper::Jumper(): m_iHighest(0),m_iGround(0), m_iPosition(0){
}

Jumper::~Jumper(){

}

void Jumper::PawnMoving(){
	m_tInfo.fX -= m_fSpeed;
}

void Jumper::Jumping(){
	if(0 < m_iHighest){
		m_tInfo.fY -= m_fSpeed;
		m_iHighest -= m_fSpeed;
		m_iGround += m_fSpeed;
	} else{
		m_tInfo.fY += m_fSpeed;
		m_iGround -= m_fSpeed;
		if(0 > m_iGround)
			m_iHighest = MONSTER_JUMPER_HIEGHT;
	}
}

void Jumper::Initialize(){
	m_tInfo.fCX = MONSTER_JUMPER_CX;
	m_tInfo.fCY = MONSTER_JUMPER_CY;

	m_fSpeed = MONSTER_JUMPER_SPEED;

	m_iHighest = MONSTER_JUMPER_HIEGHT;
	CTextureManager::GetInstance()->AddTexture(STRING_IMG_MONSTER_JUMPER, IMG_JUMPER);
}

int Jumper::Update(){
	if(nullptr != CObjectManager::GetInstance()->GetPlayer()){
		if(m_bIsDead)
			return m_bIsDead;

		PawnMoving();
		Jumping();
		m_iPosition = m_iPosition < IMAGE_SET_TIMING * 4 - 1 ? m_iPosition + 1 : 0;
	}
	return m_bIsDead;
}

void Jumper::Render(HDC hDC){
	CGameObject::UpdateRect();
	if(CKeyManager::GetInstance()->IsKeyPressing(KEY_CHAR_A))
		Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	TransparentBlt(hDC, m_tRect.left, m_tRect.top, m_tInfo.fCX, m_tInfo.fCY,
				   CTextureManager::GetInstance()->GetTextureDC(IMG_JUMPER), (MONSTER_JUMPER_CX * (m_iPosition / IMAGE_SET_TIMING)), 0, MONSTER_JUMPER_CX, MONSTER_JUMPER_CY, RGB(255, 0, 255));
}

void Jumper::Release(){
}

