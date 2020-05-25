#include "pch.h"
#include "DBullet.h"

CDBullet::CDBullet(){}

CDBullet::~CDBullet(){
	Release();
}

void CDBullet::Release(){}

void CDBullet::Initialize(){
	m_tInfo.fCX = DBULLET_CX;
	m_tInfo.fCY = DBULLET_CY;

	m_fSpeed = DBULLET_SPPED;

	CTextureManager::GetInstance()->AddTexture(STRING_IMG_DBULLET, IMG_DBULLET);
}

int CDBullet::Update(){
	if(m_bIsDead)
		return m_bIsDead;
	//더블샷은 45도 각도로 발사됨
	m_tInfo.fX += m_fSpeed / sqrtf(2.f);
	m_tInfo.fY -= m_fSpeed / sqrtf(2.f);

	CGameObject::UpdateRect();
	return m_bIsDead;
}

void CDBullet::Render(HDC _hdc){
	if(CKeyManager::GetInstance()->IsKeyPressing(KEY_CHAR_A))
		Rectangle(_hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	TransparentBlt(_hdc, m_tRect.left, m_tRect.top, (int)DBULLET_CX, (int)DBULLET_CY, CTextureManager::GetInstance()->GetTextureDC(IMG_DBULLET), 0, 0, (int)DBULLET_CX, (int)DBULLET_CY, RGB(255, 0, 255));
}
