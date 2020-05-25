#include "pch.h"
#include "Minian.h"

void Minian::PawnMoving()
{
	m_tInfo.fX -= (m_toward * m_fSpeed);
	m_tInfo.fY -= m_MinutePower;
}

void Minian::MinutePower()
{
	m_MinutePower -= G_Gravity;
}

void Minian::Initialize()
{

	m_tInfo.fCX = 33.f;
	m_tInfo.fCY = 30.f;

	m_fSpeed = 2.f;
	m_toward = float(rand() % 20 - 10.f);
	m_MinutePower = float(rand() % 20 + 30.f);
	CTextureManager::GetInstance()->AddTexture(STRING_IMG_MONSTER_MINIAN, IMG_MINIAN);
}

int Minian::Update()
{
	if (nullptr != CObjectManager::GetInstance()->GetPlayer())
	{
		if (m_bIsDead)
			return m_bIsDead;

		MinutePower();
		PawnMoving();
	}

	return m_bIsDead;
}

void Minian::Render(HDC hDC)
{
	CGameObject::UpdateRect();
	if(CKeyManager::GetInstance()->IsKeyPressing(KEY_CHAR_A))
		Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	GdiTransparentBlt(hDC, m_tRect.left, m_tRect.top, m_tInfo.fCX, m_tInfo.fCY, CTextureManager::GetInstance()->GetTextureDC(IMG_MINIAN), 0, 0, 33, 30, RGB(255, 0, 255));
}

void Minian::Release()
{
}

