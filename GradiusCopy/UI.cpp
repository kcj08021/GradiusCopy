#include "pch.h"
#include "UI.h"
#include "Player.h"

CUI::CUI(): m_iSelect(0){
	INIT_ARRAY(m_bIsPossibleActive);
}

CUI::~CUI(){
	Release();
}
bool CUI::ActivateUI(UI_VALUE _val) const{
	//선택된 UI에 대한 플래그를 플레이어에 전달함
	switch(_val){
	case UI_SPEEDUP:
		return dynamic_cast<CPlayer*>(CObjectManager::GetInstance()->GetPlayer())->SetFlag(PFLAG_SPED);
		break;
	case UI_MISSILE:
		return dynamic_cast<CPlayer*>(CObjectManager::GetInstance()->GetPlayer())->SetFlag(PFLAG_MISL);
		break;
	case UI_DOUBLE:
		return dynamic_cast<CPlayer*>(CObjectManager::GetInstance()->GetPlayer())->SetFlag(PFLAG_DOBL);
		break;
	case UI_LASER:
		return dynamic_cast<CPlayer*>(CObjectManager::GetInstance()->GetPlayer())->SetFlag(PFLAG_LASR);
		break;
	case UI_OPTION:
		return dynamic_cast<CPlayer*>(CObjectManager::GetInstance()->GetPlayer())->SetFlag(PFLAG_ADON);
		break;
	case UI_SHIELD:
		return dynamic_cast<CPlayer*>(CObjectManager::GetInstance()->GetPlayer())->SetFlag(PFLAG_SHLD);
		break;
	default:
		return false;
	}
}

void CUI::UISetting(int _iVal){
	//사용가능 불가능 UI를 구분하기 위한 함수
	switch(_iVal){
	case UI_MISSILE:
		m_bIsPossibleActive[_iVal - 1] = false;
		break;
	case UI_DOUBLE:
		m_bIsPossibleActive[_iVal - 1] = false;
		if(false == m_bIsPossibleActive[_iVal])
			m_bIsPossibleActive[_iVal] = !m_bIsPossibleActive[_iVal];
		break;
	case UI_LASER:
		m_bIsPossibleActive[_iVal - 1] = false;
		if(false == m_bIsPossibleActive[_iVal - 2])
			m_bIsPossibleActive[_iVal - 2] = !m_bIsPossibleActive[_iVal - 2];
		break;
	case UI_OPTION:
		if(CObjectManager::GetInstance()->GetObjectList(OBJ_ADDON).size() >= 2)
			m_bIsPossibleActive[_iVal - 1] = false;
		break;
	case UI_SHIELD:
		m_bIsPossibleActive[_iVal - 1] = false;
	default:
		break;
	}
}

void CUI::MoveCursor(){
	++m_iSelect;
}

void CUI::Release(){

}

void CUI::Initialize(){
	m_tInfo.fCX = UI_CX;
	m_tInfo.fCY = UI_CY;
	m_tInfo.fX = UI_INIT_X;
	m_tInfo.fY = UI_INIT_Y;

	for(bool& elem : m_bIsPossibleActive)
		elem = true;

	CGameObject::UpdateRect();

	CTextureManager::GetInstance()->AddTexture(STRING_IMG_UI_BLUE, IMG_UI_BLUE);
	CTextureManager::GetInstance()->AddTexture(STRING_IMG_UI_BLUE_NO, IMG_UI_BLUE_NO);
	CTextureManager::GetInstance()->AddTexture(STRING_IMG_UI_ORANGE, IMG_UI_ORANGE);
	CTextureManager::GetInstance()->AddTexture(STRING_IMG_UI_ORANGE_NO, IMG_UI_ORNAGE_NO);
}

int CUI::Update(){
	if(nullptr != CObjectManager::GetInstance()->GetPlayer()){
		UI_VALUE Val = UI_NULL;
		m_iSelect = m_iSelect <= 6 ? m_iSelect : m_iSelect - 6;

		if(CKeyManager::GetInstance()->IsKeyDown(KEY_CHAR_C))
			++m_iSelect;		//치트

		if(!(dynamic_cast<CPlayer*>(CObjectManager::GetInstance()->GetPlayer())->GetFlag() & PFLAG_SHLD))
			m_bIsPossibleActive[UI_SHIELD - 1] = true;

		switch(m_iSelect){
		case UI_SPEEDUP:
			Val = UI_SPEEDUP;
			break;
		case UI_MISSILE:
			Val = UI_MISSILE;
			break;
		case UI_DOUBLE:
			Val = UI_DOUBLE;
			break;
		case UI_LASER:
			Val = UI_LASER;
			break;
		case UI_OPTION:
			Val = UI_OPTION;
			break;
		case UI_SHIELD:
			Val = UI_SHIELD;
			break;
		default:
			break;
		}

		if(CKeyManager::GetInstance()->IsKeyDown(KEY_CHAR_X)){
			if(ActivateUI(Val)){
				m_iSelect = 0;
				UISetting(int(Val));
			}
		}
	}
	return 0;
}

void CUI::Render(HDC _hdc){
	bool bIsUIActive = false;
	int ActivateUI = m_iSelect - 1 < 0 ? 0 : m_iSelect - 1;
	if(m_iSelect)
		bIsUIActive = true;

	Rectangle(_hdc, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
	//기본 출력 UI
	TransparentBlt(_hdc, m_tRect.left, m_tRect.top, (int)UI_CX, (int)UI_CY,
				   CTextureManager::GetInstance()->GetTextureDC(IMG_UI_BLUE), 0, 0, (int)UI_CX, (int)UI_CY, RGB(255, 0, 255));
	//선택 블가 UI
	for(int i = 0; i < sizeof(m_bIsPossibleActive) / sizeof(bool); ++i){
		TransparentBlt(_hdc, m_tRect.left + (UI_ITEM_SIZE_X * i), m_tRect.top, UI_ITEM_SIZE_X, (int)UI_CY,
					   CTextureManager::GetInstance()->GetTextureDC(IMG_UI_BLUE_NO), UI_ITEM_SIZE_X * i, 0, UI_ITEM_SIZE_X * !m_bIsPossibleActive[i], (int)UI_CY, RGB(255, 0, 255));
	}

	//선택되어 있는 UI
	if(m_bIsPossibleActive[ActivateUI])
		TransparentBlt(_hdc, m_tRect.left + (UI_ITEM_SIZE_X * ActivateUI), m_tRect.top, UI_ITEM_SIZE_X, (int)UI_CY,
					   CTextureManager::GetInstance()->GetTextureDC(IMG_UI_ORANGE), UI_ITEM_SIZE_X * ActivateUI, 0, UI_ITEM_SIZE_X * bIsUIActive, (int)UI_CY, RGB(255, 0, 255));
	else
	//선택되어있는 선택불가 UI
		TransparentBlt(_hdc, m_tRect.left + (UI_ITEM_SIZE_X * ActivateUI), m_tRect.top, UI_ITEM_SIZE_X, (int)UI_CY,
					   CTextureManager::GetInstance()->GetTextureDC(IMG_UI_ORNAGE_NO), UI_ITEM_SIZE_X * ActivateUI, 0, UI_ITEM_SIZE_X * bIsUIActive, (int)UI_CY, RGB(255, 0, 255));
}

