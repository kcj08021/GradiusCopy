#include "pch.h"
#include "GameObject.h"


CGameObject::CGameObject()
	: m_fSpeed(0.f), m_fAngle(0.f),m_bIsDead(false), m_iHP(1), m_iDamage(1){
	INIT_STRUCT(m_tInfo);
	INIT_STRUCT(m_tRect);
}


CGameObject::~CGameObject() {}

const INFO & CGameObject::GetInfo() const {
	return m_tInfo;
}

const RECT & CGameObject::GetRect() const {
	return m_tRect;
}

const int CGameObject::GetDamage() const{
	return m_iDamage;
}

void CGameObject::SetPos(float _x, float _y) {
	m_tInfo.fX = _x;
	m_tInfo.fY = _y;
	
	UpdateRect();
}

void CGameObject::SetDead(bool _bIsDead) {
	m_bIsDead = _bIsDead;
}

void CGameObject::SetAngle(float _fAngle){
	m_fAngle = _fAngle;
}

void CGameObject::SetDamage(int i){
	m_iHP -= i;

	if(0 >= m_iHP)
		m_bIsDead = true;
}

void CGameObject::UpdateRect() {
	m_tRect.left = static_cast<LONG>(m_tInfo.fX - m_tInfo.fCX * 0.5f);
	m_tRect.top = static_cast<LONG>(m_tInfo.fY - m_tInfo.fCY * 0.5f);
	m_tRect.right = static_cast<LONG>(m_tInfo.fX + m_tInfo.fCX * 0.5f);
	m_tRect.bottom = static_cast<LONG>(m_tInfo.fY + m_tInfo.fCY * 0.5f);
}
