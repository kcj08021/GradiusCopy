#include "pch.h"
#include "Rugal.h"

Rugal::Rugal() : m_iPosition(0){
}

Rugal::~Rugal(){
	Release();
}

void Rugal::PawnMoving()
{
	if (m_tInfo.fY > CObjectManager::GetInstance()->GetPlayer()->GetInfo().fY)
	{
		m_tInfo.fX -= m_fSpeed;
		m_tInfo.fY -= m_fSpeed;
		m_iPosition = 2;
	}
	else if (m_tInfo.fY < CObjectManager::GetInstance()->GetPlayer()->GetInfo().fY)
	{
		m_tInfo.fX -= m_fSpeed;
		m_tInfo.fY += m_fSpeed;
		m_iPosition = 0;
	}
	else
	{
		m_tInfo.fX -= m_fSpeed * 2.f;
		m_iPosition = 1;
	}
}

void Rugal::Release(){
}

void Rugal::Initialize()
{
	m_tInfo.fCX = MONSTER_RUGAL_CX;
	m_tInfo.fCY = MONSTER_RUGAL_CY;

	m_fSpeed = MONSTER_RUGAL_SPEED;
	CTextureManager::GetInstance()->AddTexture(STRING_IMG_MONSTER_RUGAL, IMG_RUGAL);
}

int Rugal::Update()
{
	if (nullptr != CObjectManager::GetInstance()->GetPlayer())
	{
		if (m_bIsDead)
			return m_bIsDead;

		PawnMoving();
	}

	return m_bIsDead;
}

void Rugal::Render(HDC hDC)
{
	CGameObject::UpdateRect();
	if(CKeyManager::GetInstance()->IsKeyPressing(KEY_CHAR_A))
		Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	TransparentBlt(hDC, m_tRect.left, m_tRect.top, m_tInfo.fCX, m_tInfo.fCY, 
				   CTextureManager::GetInstance()->GetTextureDC(IMG_RUGAL), (MONSTER_RUGAL_CX * m_iPosition), 0, MONSTER_RUGAL_CX, MONSTER_RUGAL_CY, RGB(255, 0, 255));
}

