#include "pch.h"
#include "Item.h"
#include "UI.h"

CItem::CItem(): m_iImageState(0){
}

CItem::~CItem(){
	Release();
}

void CItem::Release(){
	if(0 != CObjectManager::GetInstance()->GetObjectList(OBJ_UI).size())
		dynamic_cast<CUI*>(CObjectManager::GetInstance()->GetObjectList(OBJ_UI).front())->MoveCursor();
}

void CItem::Initialize(){
	m_tInfo.fCX = ITEM_CX;
	m_tInfo.fCY = ITEM_CY;

	m_fSpeed = ITEM_SPEED;

	m_iDamage = 0;
	m_iHP = 0;

	CTextureManager::GetInstance()->AddTexture(STRING_IMG_ITEM, IMG_ITEM);

	CGameObject::UpdateRect();
}

int CItem::Update(){
	if(m_bIsDead)
		return m_bIsDead;
	//아이템은 이미지 3장, 각 0.2초씩 출력(0.6초뒤 첫 이미지로)
	m_iImageState = m_iImageState < 59 ? m_iImageState + 1 : 0;
	m_tInfo.fX -= m_fSpeed;

	CGameObject::UpdateRect();
	return m_bIsDead;
}

void CItem::Render(HDC _hdc){
	if(CKeyManager::GetInstance()->IsKeyPressing(KEY_CHAR_A))
		Rectangle(_hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	TransparentBlt(_hdc, m_tRect.left, m_tRect.top, (int)ITEM_CX, (int)ITEM_CY, 
				   CTextureManager::GetInstance()->GetTextureDC(IMG_ITEM), ((int)ITEM_CX*(m_iImageState / 20)), 0, (int)ITEM_CX, (int)ITEM_CY, RGB(255, 0, 255));
}
