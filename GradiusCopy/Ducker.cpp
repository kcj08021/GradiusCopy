#include "pch.h"
#include "Ducker.h"
#include "EnemyBullet.h"

Ducker::Ducker(): m_radian(0), m_Cooltime(0), m_bMoveEnd(false), m_position(0), m_Timer(0), m_iCount(0){

}

Ducker::~Ducker(){
	Release();
}

void Ducker::PawnMoving(){
	if(!m_bMoveEnd && m_iCount > 0)
		if(CObjectManager::GetInstance()->GetPlayer()->GetInfo().fX + 400 > m_tInfo.fX){
			m_tInfo.fX += m_fSpeed;
			m_Timer = m_Timer < IMAGE_SET_TIMING * 2 - 1 ? m_Timer + 1 : 0;
		} else{
			m_Timer = IMAGE_SET_TIMING * 2;
			m_bMoveEnd = true;
		}
	else
		m_tInfo.fX -= MAP_SCROLL_SPEED * 3.f;
}

void Ducker::Initialize(){
	m_tInfo.fCX = MONSTER_DUCKER_CX;
	m_tInfo.fCY = MONSTER_DUCKER_CY;

	m_fSpeed = MONSTER_DUCKER_SPEED;
	m_Cooltime = MONSTER_DUCKER_COOLTIME;

	m_iCount = 5;
	CTextureManager::GetInstance()->AddTexture(STRING_IMG_MONSTER_DUCKER, IMG_DUCKER);
}

void Ducker::CalculatePosition(){
	if(m_tInfo.fY > float(PLAYREGION_Y / 2))
		m_position = 0;
	else m_position = 1;
}

int Ducker::Update(){
	if(nullptr != CObjectManager::GetInstance()->GetPlayer()){
		if(m_bIsDead)
			return m_bIsDead;

		CalculatePosition();

		if(CObjectManager::GetInstance()->GetPlayer()->GetInfo().fX >= m_tInfo.fX){
			m_bMoveEnd = false;
		}

		PawnMoving();

		--m_Cooltime;
		if(m_bMoveEnd){
			Attack();
			--m_iCount;
		}

		return m_bIsDead;
	}
}

void Ducker::Render(HDC hDC){
	CGameObject::UpdateRect();
	if(CKeyManager::GetInstance()->IsKeyPressing(KEY_CHAR_A))
		Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	GdiTransparentBlt(hDC, m_tRect.left, m_tRect.top, (int)m_tInfo.fCX, (int)m_tInfo.fCY,
					  CTextureManager::GetInstance()->GetTextureDC(IMG_DUCKER), (int)MONSTER_DUCKER_CX * (m_Timer/IMAGE_SET_TIMING), (int)(MONSTER_DUCKER_CY * m_position), (int)MONSTER_DUCKER_CX, (int)MONSTER_DUCKER_CY, RGB(255, 0, 255));
}

bool Ducker::Attack(){
	if(m_Cooltime <= 0){
		if(m_tInfo.fY < CObjectManager::GetInstance()->GetPlayer()->GetInfo().fY)
			m_radian = Radian::GetRadian(m_tInfo.fX, m_tInfo.fY, CObjectManager::GetInstance()->GetPlayer()->GetInfo().fX, CObjectManager::GetInstance()->GetPlayer()->GetInfo().fY) * -1.f;
		else if(m_tInfo.fY > CObjectManager::GetInstance()->GetPlayer()->GetInfo().fY)
			m_radian = Radian::GetRadian(m_tInfo.fX, m_tInfo.fY, CObjectManager::GetInstance()->GetPlayer()->GetInfo().fX, CObjectManager::GetInstance()->GetPlayer()->GetInfo().fY);

		CObjectManager::GetInstance()->AddObject(OBJ_ENEMYBULLET, CAbstractFactory<EnemyBullet>::CreateObject(m_tInfo.fX, m_tInfo.fY, m_radian));
		m_Cooltime = 100.f;
		
		return true;
	}
	return false;
}


void Ducker::Release(){
}

