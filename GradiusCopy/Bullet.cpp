#include "pch.h"
#include "Bullet.h"

CBullet::CBullet(){}

CBullet::~CBullet(){
	Release();
}

void CBullet::Release(){}

void CBullet::Initialize() {
	m_tInfo.fCX = BULLET_CX;
	m_tInfo.fCY = BULLET_CY;

	m_fSpeed = BULLET_SPPED;

	CGameObject::UpdateRect();
	CTextureManager::GetInstance()->AddTexture(STRING_IMG_BULLET, IMG_BULLET);
}

int CBullet::Update() {
	if(m_bIsDead)
		return m_bIsDead;

	m_tInfo.fX += m_fSpeed;

	CGameObject::UpdateRect();
	return m_bIsDead;
}

void CBullet::Render(HDC _hdc) {
	if(CKeyManager::GetInstance()->IsKeyPressing(KEY_CHAR_A))
		Rectangle(_hdc,m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	TransparentBlt(_hdc, m_tRect.left, m_tRect.top, (int)BULLET_CX, (int)BULLET_CY, CTextureManager::GetInstance()->GetTextureDC(IMG_BULLET), 0, 0, (int)BULLET_CX, (int)BULLET_CY, RGB(255, 0, 255));
}


