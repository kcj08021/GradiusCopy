#include "pch.h"
#include "Big_Core.h"
#include "EnemyBullet.h"

Big_Core::Big_Core(): m_Cooltime(0){
}

Big_Core::~Big_Core(){
	Release();
}

void Big_Core::Initialize(){
	m_tInfo.fX = 650.f;
	m_tInfo.fY = 300.f;
	m_tInfo.fCX = 162.f;
	m_tInfo.fCY = 162.f;

	m_Cooltime = 20;
	m_fSpeed = 3.f;
	m_iDamage = 100;
	m_iHP = 150;
	CTextureManager::GetInstance()->AddTexture(STRING_IMG_MONSTER_BIGCORE, IMG_BIGCORE);

}

int Big_Core::Update(){
	if(m_bIsDead)
		return m_bIsDead;

	if(nullptr != CObjectManager::GetInstance()->GetPlayer()){
		m_Cooltime--;
		BossMoving();
		if(m_Cooltime <= 0){
			if(BulletFire());
				m_Cooltime = 100;
		}
	}
	return m_bIsDead;
}

void Big_Core::Render(HDC hDC){
	CGameObject::UpdateRect();
	if(CKeyManager::GetInstance()->IsKeyPressing(KEY_CHAR_A))
		Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	GdiTransparentBlt(hDC, m_tRect.left, m_tRect.top, m_tInfo.fCX, m_tInfo.fCY, CTextureManager::GetInstance()->GetTextureDC(IMG_BIGCORE), 0, 0, 162, 162, RGB(255, 0, 255));
}

void Big_Core::Release(){
	if(m_bIsDead){
		CEffectManager::GetInstance()->ObjectDead(OBJ_BOSS, m_tInfo);
		PatternMgr::GetInstance()->SetBossDie(true);
	}
}


void Big_Core::BossMoving(){
	if(m_tInfo.fY < CObjectManager::GetInstance()->GetPlayer()->GetInfo().fY)
		m_tInfo.fY += m_fSpeed;
	else if(m_tInfo.fY > CObjectManager::GetInstance()->GetPlayer()->GetInfo().fY) 
		m_tInfo.fY -= m_fSpeed;
}


bool Big_Core::BulletFire(){
	if(m_tInfo.fY == CObjectManager::GetInstance()->GetPlayer()->GetInfo().fY){
		CObjectManager::GetInstance()->AddObject(OBJ_ENEMYBULLET, CAbstractFactory<EnemyBullet>::CreateObject(m_tInfo.fX - 100, m_tInfo.fY - 75, PI, BOSS));
		CObjectManager::GetInstance()->AddObject(OBJ_ENEMYBULLET, CAbstractFactory<EnemyBullet>::CreateObject(m_tInfo.fX - 150, m_tInfo.fY - 40, PI, BOSS));
		CObjectManager::GetInstance()->AddObject(OBJ_ENEMYBULLET, CAbstractFactory<EnemyBullet>::CreateObject(m_tInfo.fX - 150, m_tInfo.fY + 40, PI, BOSS));
		CObjectManager::GetInstance()->AddObject(OBJ_ENEMYBULLET, CAbstractFactory<EnemyBullet>::CreateObject(m_tInfo.fX - 100, m_tInfo.fY + 75, PI, BOSS));
		
		return true;
	}

	return false;
}
