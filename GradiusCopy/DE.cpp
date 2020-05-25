#include "pch.h"
#include "DE.h"
#include "EnemyBullet.h"

DE::DE(): m_iCooltime(0), m_iTimer(0), m_iPosition(0){

}

DE::~DE(){
}

void DE::PawnMoving()
{
	m_tInfo.fX -= m_fSpeed;
}

void DE::Attack()
{
	float m_radian = Radian::GetRadian(m_tInfo.fX, m_tInfo.fY, CObjectManager::GetInstance()->GetPlayer()->GetInfo().fX, CObjectManager::GetInstance()->GetPlayer()->GetInfo().fY);
	
	if(m_iPosition)
		CObjectManager::GetInstance()->AddObject(OBJ_ENEMYBULLET, CAbstractFactory<EnemyBullet>::CreateObject(m_tInfo.fX, m_tInfo.fY, -m_radian));
	else
		CObjectManager::GetInstance()->AddObject(OBJ_ENEMYBULLET, CAbstractFactory<EnemyBullet>::CreateObject(m_tInfo.fX, m_tInfo.fY, m_radian));

}

void DE::CalculatePosition()
{
	if (m_tInfo.fY > PLAYREGION_Y/2)
		m_iPosition = 0;
	else m_iPosition = 1;
}

void DE::CalculateAngle()
{
	if (Radian::GetRadian( CObjectManager::GetInstance()->GetPlayer()->GetInfo().fX, CObjectManager::GetInstance()->GetPlayer()->GetInfo().fY, m_tInfo.fX, m_tInfo.fY) > RADIAN(45))
	{
		m_iTimer = 0;
	}
	else if (Radian::GetRadian(CObjectManager::GetInstance()->GetPlayer()->GetInfo().fX, CObjectManager::GetInstance()->GetPlayer()->GetInfo().fY, m_tInfo.fX, m_tInfo.fY) <= RADIAN(45) &&
			 Radian::GetRadian(CObjectManager::GetInstance()->GetPlayer()->GetInfo().fX, CObjectManager::GetInstance()->GetPlayer()->GetInfo().fY, m_tInfo.fX, m_tInfo.fY) > RADIAN(15))
	{
		m_iTimer = 1;
	}
	else if (Radian::GetRadian(CObjectManager::GetInstance()->GetPlayer()->GetInfo().fX, CObjectManager::GetInstance()->GetPlayer()->GetInfo().fY, m_tInfo.fX, m_tInfo.fY) <= RADIAN(15))
	{
		m_iTimer = 2;
	}
}

void DE::Release(){
}

void DE::Initialize()
{
	m_tInfo.fCX = MONSTER_DE_CX;
	m_tInfo.fCY = MONSTER_DE_CY;

	m_iCooltime = MONSTER_DE_COOLTIME;		//1ÃÊ
	m_fSpeed = MONSTER_DE_SPEED;

	CTextureManager::GetInstance()->AddTexture(STRING_IMG_MONSTER_DE, IMG_DE);
}

int DE::Update()
{
	if (nullptr != CObjectManager::GetInstance()->GetPlayer())
	{
		if (m_bIsDead)
			return m_bIsDead;

		CalculatePosition();
		CalculateAngle();
		PawnMoving();
		if (!(m_iCooltime--))
		{
			Attack();
			m_iCooltime = MONSTER_DE_COOLTIME;
		}
	}
	return m_bIsDead;
}

void DE::Render(HDC hDC)
{
	CGameObject::UpdateRect();
	if(CKeyManager::GetInstance()->IsKeyPressing(KEY_CHAR_A))
		Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	TransparentBlt(hDC, m_tRect.left, m_tRect.top, m_tInfo.fCX, m_tInfo.fCY, 
		CTextureManager::GetInstance()->GetTextureDC(IMG_DE), (MONSTER_DE_CX * m_iTimer), (MONSTER_DE_CY * m_iPosition), MONSTER_DE_CX, MONSTER_DE_CY, RGB(255, 0, 255));
}

