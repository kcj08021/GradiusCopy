#include "pch.h"
#include "EnemyBullet.h"


EnemyBullet::EnemyBullet(): m_eType(PAWN){

}


EnemyBullet::~EnemyBullet(){
	Release();
}

void EnemyBullet::SetType(BULLIT_TYPE eTyp){
	m_eType = eTyp;
}

void EnemyBullet::Initialize(){

	m_fSpeed = 5.f;

	CTextureManager::GetInstance()->AddTexture(STRING_IMG_ENEMY_BULLET, IMG_ENEMY_BULLET);
	CTextureManager::GetInstance()->AddTexture(STRING_IMG_BIGCORE_MISSILE, IMG_BIGCORE_MISSILE);
}

int EnemyBullet::Update(){
	if(m_bIsDead)
		return m_bIsDead;

	if(m_eType == PAWN){
		m_tInfo.fCX = 18.f;
		m_tInfo.fCY = 18.f;
	} else if(m_eType == BOSS){
		m_tInfo.fCX = 48.f;
		m_tInfo.fCY = 12.f;
	}

	IsMoving();

	CGameObject::UpdateRect();

	return m_bIsDead;
}

void EnemyBullet::Render(HDC hDC){
	if(CKeyManager::GetInstance()->IsKeyPressing(KEY_CHAR_A))
		Ellipse(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	if(m_eType == PAWN)
		GdiTransparentBlt(hDC, m_tRect.left, m_tRect.top, m_tInfo.fCX, m_tInfo.fCY, CTextureManager::GetInstance()->GetTextureDC(IMG_ENEMY_BULLET), 0, 0, 18, 18, RGB(255, 0, 255));
	if(m_eType == BOSS)
		GdiTransparentBlt(hDC, m_tRect.left, m_tRect.top, m_tInfo.fCX, m_tInfo.fCY, CTextureManager::GetInstance()->GetTextureDC(IMG_BIGCORE_MISSILE), 0, 0, 48, 12, RGB(255, 0, 255));
}

void EnemyBullet::Release(){
}

void EnemyBullet::IsMoving(){
	if(m_eType != BOSS){
		m_tInfo.fX += cosf(m_fAngle) * m_fSpeed;
		m_tInfo.fY -= sinf(m_fAngle) * m_fSpeed;
	} else{
		m_tInfo.fX -= m_fSpeed;
	}
}
