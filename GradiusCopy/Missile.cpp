#include "pch.h"
#include "Missile.h"

CMissile::CMissile(): m_bIsGround(false), m_iImageState(0) {}

CMissile::~CMissile(){
	Release();
}

void CMissile::Release(){}

void CMissile::Initialize(){
	m_tInfo.fCX = BULLET_CX;
	m_tInfo.fCY = BULLET_CY;

	m_fSpeed = 5.f;

	CGameObject::UpdateRect();
	CTextureManager::GetInstance()->AddTexture(STRING_IMG_MISSILE, IMG_MISSILE);
}

int CMissile::Update(){
	if(m_bIsDead)
		return m_bIsDead;
	OBJLIST::iterator iter;
	RECT rc;
	if(CObjectManager::GetInstance()->GetObjectList(OBJ_MAPOBJECT).size() > 0){
		iter = CObjectManager::GetInstance()->GetObjectList(OBJ_MAPOBJECT).begin();
		if(IntersectRect(&rc, &m_tRect, &CObjectManager::GetInstance()->GetObjectList(OBJ_MAPOBJECT).front()->GetRect()))
			m_bIsGround = true;
		++iter;
		++iter;
	}

	if(!m_bIsGround){
		if(CObjectManager::GetInstance()->GetObjectList(OBJ_MAPOBJECT).size() > 0){
			while(iter != CObjectManager::GetInstance()->GetObjectList(OBJ_MAPOBJECT).end()){
					if(IntersectRect(&rc, &m_tRect, &(*iter)->GetRect())){
					m_tInfo.fX += m_fSpeed;
					m_iImageState = 1;

					CGameObject::UpdateRect();

					return 0;
					}
				++iter;
			}

			m_iImageState = 0;
			m_tInfo.fX += m_fSpeed * cosf(RADIAN(60));
			m_tInfo.fY += m_fSpeed * sinf(RADIAN(60));
		} else{
			m_tInfo.fX += m_fSpeed * cosf(RADIAN(60));
			m_tInfo.fY += m_fSpeed * sinf(RADIAN(60));
		}
	} else{
		if(CObjectManager::GetInstance()->GetObjectList(OBJ_MAPOBJECT).size() != 0)
			if(!IntersectRect(&rc, &m_tRect, &CObjectManager::GetInstance()->GetObjectList(OBJ_MAPOBJECT).front()->GetRect())){
				m_bIsGround = false;
				m_iImageState = 0;

				m_tInfo.fX += m_fSpeed * cosf(RADIAN(60));
				m_tInfo.fY += m_fSpeed * sinf(RADIAN(60));
			} else{
				m_iImageState = 1;
				m_tInfo.fX += m_fSpeed;
				CGameObject::UpdateRect();
				while(iter != CObjectManager::GetInstance()->GetObjectList(OBJ_MAPOBJECT).end()){
					if(IntersectRect(&rc, &m_tRect, &(*iter)->GetRect())){
						m_bIsDead = true;
					}
					++iter;
				}
			}
	}

	CGameObject::UpdateRect();

	return m_bIsDead;
}

void CMissile::Render(HDC _hdc){
	if(CKeyManager::GetInstance()->IsKeyPressing(KEY_CHAR_A))
		Rectangle(_hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	TransparentBlt(_hdc, m_tRect.left, m_tRect.top, (int)MISSILE_CX, (int)MISSILE_CY, 
				   CTextureManager::GetInstance()->GetTextureDC(IMG_MISSILE), (int)(MISSILE_CX*int(m_iImageState)), 0, (int)MISSILE_CX, (int)MISSILE_CY, RGB(255, 0, 255));

}
