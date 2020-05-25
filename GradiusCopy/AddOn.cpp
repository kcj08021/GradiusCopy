#include "pch.h"
#include "Player.h"
#include "AddOn.h"
#include "Bullet.h"
#include "DBullet.h"
#include "Missile.h"
#include "Laser.h"

CAddOn::CAddOn(): m_pPlayerInfo(nullptr), m_iImageState(0){}

CAddOn::~CAddOn(){
	Release();
}

void CAddOn::SetInfo(const INFO& _info){
	m_pPlayerInfo = &_info;

	CGameObject::SetPos(_info.fX, _info.fY + ADDON_DIST);

	InitList();
}

void CAddOn::InitList(){
	for(float i = PLAYER_SPEED; i <= ADDON_DIST; i += PLAYER_SPEED){
		fPOINT* fPT = new fPOINT;
		fPT->x = m_tInfo.fX;
		fPT->y = m_tInfo.fY - i;

		m_PlayerXY.push_back(fPT);		//리스트에 초기 이동경로에 대한 좌표를 넣어둠
	}
}

void CAddOn::CreateBullet(){			//총알 생성 함수, 플래그값에 따라 발사할 총알 결정
	const PLAYERFLAG Pflag = dynamic_cast<CPlayer*>(CObjectManager::GetInstance()->GetPlayer())->GetFlag();

	if(!(PFLAG_LASR & Pflag)){
		CGameObject* newBullet = CAbstractFactory<CBullet>::CreateObject(m_tInfo.fX, m_tInfo.fY);

		CObjectManager::GetInstance()->AddObject(OBJ_BULLET, newBullet);

		if(PFLAG_DOBL & Pflag){
			CGameObject* newBullet = CAbstractFactory<CDBullet>::CreateObject(m_tInfo.fX, m_tInfo.fY);

			CObjectManager::GetInstance()->AddObject(OBJ_BULLET, newBullet);
		}
	} else{
		CGameObject* newBullet = CAbstractFactory<CLaser>::CreateObject(m_tInfo);

		CObjectManager::GetInstance()->AddObject(OBJ_BULLET, newBullet);
	}

	if(PFLAG_MISL & Pflag && Pflag & PFLAG_SHMS){
		CGameObject* newBullet = CAbstractFactory<CMissile>::CreateObject(m_tInfo.fX, m_tInfo.fY);

		CObjectManager::GetInstance()->AddObject(OBJ_MISSILE, newBullet);
	}

}

void CAddOn::Release(){
	for(auto& elem : m_PlayerXY){
		SafeDelete(elem);
		elem = nullptr;
	}

	m_pPlayerInfo = nullptr;
}

void CAddOn::Initialize(){
	m_tInfo.fCX = ADDON_CX;
	m_tInfo.fCY = ADDON_CY;

	CGameObject::UpdateRect();

	CTextureManager::GetInstance()->AddTexture(STRING_IMG_ADDON, IMG_ADDON);
}

int CAddOn::Update(){
	if(nullptr != CObjectManager::GetInstance()->GetPlayer()){
		const PLAYERFLAG Pflag = dynamic_cast<CPlayer*>(CObjectManager::GetInstance()->GetPlayer())->GetFlag();

		//0.2초마다 이미지 교환을 위한 계산(0.2초씩 각 이미지를 유지, 0.4초 이후 첫 이미지로)
			m_iImageState = m_iImageState < IMAGE_SET_TIMING * 2 - 1 ? m_iImageState + 1 : 0;

			if(PFLAG_MOVE & Pflag){		//플레이어가 움직일 경우
				fPOINT* fPT = m_PlayerXY.front();	//리스트를 이용한 큐(선입선출)로 작동

					m_tInfo.fX = fPT->x;
					m_tInfo.fY = fPT->y;

					SafeDelete(fPT);
				m_PlayerXY.pop_front();

				//움직인 뒤의 플레이어 좌표를 큐에 넣음
				fPT = new fPOINT;

				fPT->x = m_pPlayerInfo->fX;
				fPT->y = m_pPlayerInfo->fY;

				m_PlayerXY.push_back(fPT);
			}
		if(PFLAG_SHOT & Pflag){		//플레이어가 발사 할 경우
			CreateBullet();
		}

		CGameObject::UpdateRect();
	}
	return 0;
}

void CAddOn::Render(HDC _hdc){
	if(CKeyManager::GetInstance()->IsKeyPressing(KEY_CHAR_A))
		Rectangle(_hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	TransparentBlt(_hdc, m_tRect.left, m_tRect.top, (int)ADDON_CX, (int)ADDON_CY, CTextureManager::GetInstance()->GetTextureDC(IMG_ADDON), int(ADDON_CX * (m_iImageState / IMAGE_SET_TIMING)), 0, (int)ADDON_CX, (int)ADDON_CY, RGB(255, 0, 255));
}