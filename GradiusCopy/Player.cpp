#include "pch.h"
#include "Player.h"
#include "Bullet.h"
#include "DBullet.h"
#include "Missile.h"
#include "Laser.h"
#include "AddOn.h"
#include "Shield.h"

CPlayer::CPlayer(): m_Flag(0), m_fSpeedUp(0.f), m_iImageState(0){
	INIT_STRUCT(DisplayRect);
}

CPlayer::~CPlayer(){
	Release();
}

void CPlayer::KeyInput(){
	m_iImageState = 0;
	if(CKeyManager::GetInstance()->IsKeyPressing(KEY_UP)){
		m_iImageState = 2;
		m_Flag |= PFLAG_MOVE;
		m_tInfo.fY -= m_fSpeed + m_fSpeedUp;
		if(m_tInfo.fY - (PLAYER_CY * 0.5f) <= 0)
			m_tInfo.fY = PLAYER_CY * 0.5f;
	} if(CKeyManager::GetInstance()->IsKeyPressing(KEY_DOWN)){
		m_iImageState = 1;
		m_Flag |= PFLAG_MOVE;
		m_tInfo.fY += m_fSpeed + m_fSpeedUp;
		if(m_tInfo.fY + (PLAYER_CY * 0.5f) >= PLAYREGION_Y)
			m_tInfo.fY = 600 - (PLAYER_CY * 0.5f);
	} if(CKeyManager::GetInstance()->IsKeyPressing(KEY_LEFT)){
		m_Flag |= PFLAG_MOVE;
		m_tInfo.fX -= (m_fSpeed + m_fSpeedUp);
		if(m_tInfo.fX - (PLAYER_CX * 0.5f) <= 0)
			m_tInfo.fX = PLAYER_CX * 0.5f;
	} if(CKeyManager::GetInstance()->IsKeyPressing(KEY_RIGHT)){
		m_Flag |= PFLAG_MOVE;
		m_tInfo.fX += (m_fSpeed + m_fSpeedUp);
		if(m_tInfo.fX + (PLAYER_CX * 0.5f) >= PLAYREGION_X)
			m_tInfo.fX = WINCX - PLAYER_CX * 0.5f;
	}

	if(CKeyManager::GetInstance()->IsKeyDown(KEY_CHAR_Z)){
		m_Flag |= PFLAG_SHOT;
		CreateBullet();
	}
}

void CPlayer::CreateBullet(){
	if(!(PFLAG_LASR & m_Flag)){
		CGameObject* newBullet = CAbstractFactory<CBullet>::CreateObject(m_tInfo.fX, m_tInfo.fY);

		CObjectManager::GetInstance()->AddObject(OBJ_BULLET, newBullet);

		if(PFLAG_DOBL & m_Flag){
			CGameObject* newBullet = CAbstractFactory<CDBullet>::CreateObject(m_tInfo.fX, m_tInfo.fY);

			CObjectManager::GetInstance()->AddObject(OBJ_BULLET, newBullet);
		}
	} else{
		CGameObject* newBullet = CAbstractFactory<CLaser>::CreateObject(m_tInfo);

		CObjectManager::GetInstance()->AddObject(OBJ_BULLET, newBullet);
	}

	if(PFLAG_MISL & m_Flag){
		if(CObjectManager::GetInstance()->GetObjectList(OBJ_MISSILE).size() == 0){
			m_Flag |= PFLAG_SHMS;
			CGameObject* newBullet = CAbstractFactory<CMissile>::CreateObject(m_tInfo.fX, m_tInfo.fY);

			CObjectManager::GetInstance()->AddObject(OBJ_MISSILE, newBullet);
		}
	}
}

bool CPlayer::CreateAddOn(){
	CGameObject* obj = nullptr;

	if(2 > CObjectManager::GetInstance()->GetObjectList(OBJ_ADDON).size()){
		if(!CObjectManager::GetInstance()->GetObjectList(OBJ_ADDON).size()){
			obj = CAbstractFactory<CAddOn>::CreateObject(m_tInfo);
			CObjectManager::GetInstance()->AddObject(OBJ_ADDON, obj);
		} else{
			obj = CAbstractFactory<CAddOn>::CreateObject(CObjectManager::GetInstance()->GetObjectList(OBJ_ADDON).back()->GetInfo());
			CObjectManager::GetInstance()->AddObject(OBJ_ADDON, obj);
		}

		return true;
	} else
		return false;
}

bool CPlayer::CreateShield(){
	CGameObject* obj = nullptr;

	if(!CObjectManager::GetInstance()->GetObjectList(OBJ_SHIELD).size()){
		obj = CAbstractFactory<CShield>::CreateObject(m_tInfo);
		CObjectManager::GetInstance()->AddObject(OBJ_SHIELD, obj);

		return true;
	} else
		return false;
}


const PLAYERFLAG& CPlayer::GetFlag() const{
	return m_Flag;
}

bool CPlayer::SetFlag(PLAYERFLAG _flag){
	if(nullptr != CObjectManager::GetInstance()->GetPlayer()){
		if(PFLAG_LASR == _flag && PFLAG_DOBL & m_Flag){
			m_Flag ^= PFLAG_DOBL;
			m_Flag ^= _flag;

			return true;
		} else if(PFLAG_DOBL == _flag && PFLAG_LASR & m_Flag){
			m_Flag ^= PFLAG_LASR;
			m_Flag ^= _flag;

			return true;
		} else if(PFLAG_SPED == _flag){
			m_fSpeedUp += PLAYER_SPEEDUP;

			return true;
		} else if(PFLAG_ADON == _flag){
			return CreateAddOn();
		} else if(PFLAG_SHLD == _flag){
			m_Flag ^= _flag;
			if(!(m_Flag & _flag)){
				return false;
			}
			return CreateShield();
		} else{
			if(_flag & m_Flag)
				return false;
			m_Flag |= _flag;

			return true;
		}
	}
}


void CPlayer::Release(){

	CEffectManager::GetInstance()->ObjectDead(OBJ_PLAYER, m_tInfo);
}

void CPlayer::Initialize(){
	m_tInfo.fCX = PLAYER_CX;
	m_tInfo.fCY = PLAYER_CY;
	m_tInfo.fX = PLAYER_INIT_X;
	m_tInfo.fY = PLAYER_INIT_Y;

	m_fSpeed = PLAYER_SPEED;

	CTextureManager::GetInstance()->AddTexture(STRING_IMG_PLAYER, IMG_PLAYER);

	CGameObject::UpdateRect();
}

int CPlayer::Update(){
	if(m_bIsDead){
		m_Flag = PFLAG_DEAD;
		return m_bIsDead;
	} else{
		m_Flag &= ~(PFLAG_MOVE | PFLAG_SHOT | PFLAG_SHMS);
		KeyInput();
	}

	CGameObject::UpdateRect();

	return 0;
}

void CPlayer::Render(HDC _hdc){
	if(CKeyManager::GetInstance()->IsKeyPressing(KEY_CHAR_A))
		Rectangle(_hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	TransparentBlt(_hdc, m_tRect.left, m_tRect.top, (int)PLAYER_CX, (int)PLAYER_CY, CTextureManager::GetInstance()->GetTextureDC(IMG_PLAYER), int(PLAYER_CX * m_iImageState), 0, (int)PLAYER_CX, (int)PLAYER_CY, RGB(255, 0, 255));
}