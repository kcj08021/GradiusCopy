#include "pch.h"
#include "Garun.h"
#include "Player.h"
Garun::Garun() : m_fRadian(0.f), m_iPosition(0){

}
Garun::~Garun(){

}

void Garun::PawnMoving()
{
	m_tInfo.fX -= m_fSpeed;
	m_tInfo.fY -= sinf(m_fRadian) * m_fSpeed * 5.f;
}

void Garun::Release(){

}

void Garun::Initialize()
{
	m_tInfo.fCX = MONSTER_GARUN_CX;
	m_tInfo.fCY = MONSTER_GARUN_CY;

	m_fSpeed = MONSTER_GARUN_SPEED;
	CTextureManager::GetInstance()->AddTexture(STRING_IMG_MONSTER_GARUN, IMG_GARUN);
}

int Garun::Update()
{
	if (nullptr != CObjectManager::GetInstance()->GetPlayer())
	{
		if (m_bIsDead)
			return m_bIsDead;

		m_fRadian += MONSTER_GARUN_RADIAN;
		PawnMoving();

		m_iPosition = m_iPosition < IMAGE_SET_TIMING * 4 - 1 ? m_iPosition + 1 : 0;
	}
	return m_bIsDead;
}

void Garun::Render(HDC hDC)
{
	CGameObject::UpdateRect();
	if(CKeyManager::GetInstance()->IsKeyPressing(KEY_CHAR_A))
		Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	TransparentBlt(hDC, m_tRect.left, m_tRect.top, m_tInfo.fCX, m_tInfo.fCY, 
					  CTextureManager::GetInstance()->GetTextureDC(IMG_GARUN), (MONSTER_GARUN_CX * (m_iPosition / IMAGE_SET_TIMING)), 0, MONSTER_GARUN_CX, MONSTER_GARUN_CY, RGB(255, 0, 255));
}

