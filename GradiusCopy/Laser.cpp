#include "pch.h"
#include "Laser.h"

CLaser::CLaser() : m_pPlayerInfo(nullptr) {}

CLaser::~CLaser(){
	Release();
}

void CLaser::SetInfo(const INFO& _info){
	m_pPlayerInfo = &_info;		//플레이어의 INFO를 포인터로 받아 멤버로 보관

	CGameObject::SetPos(_info.fX, _info.fY);
	CGameObject::UpdateRect();
}

void CLaser::Release(){}

void CLaser::Initialize(){
	m_tInfo.fCX = LASER_CX;
	m_tInfo.fCY = LASER_CY;

	m_fSpeed = LASER_SPEED;

	m_iHP = 100;

	CTextureManager::GetInstance()->AddTexture(STRING_IMG_LASER, IMG_LASER);

	CGameObject::UpdateRect();
}

int CLaser::Update(){
{
		if(m_bIsDead)
			return m_bIsDead;

		m_tInfo.fX += m_fSpeed;
		if(nullptr != CObjectManager::GetInstance()->GetPlayer())
			m_tInfo.fY = m_pPlayerInfo->fY;		//레이저는 플레이어의 Y좌표를 따라 움직임

		CGameObject::UpdateRect();

		return m_bIsDead;
	}
}

void CLaser::Render(HDC _hdc){
	if(CKeyManager::GetInstance()->IsKeyPressing(KEY_CHAR_A))
		Rectangle(_hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	TransparentBlt(_hdc, m_tRect.left, m_tRect.top, 48, 6, CTextureManager::GetInstance()->GetTextureDC(IMG_LASER), 0, 0, 48, 6, RGB(255, 0, 255));

}