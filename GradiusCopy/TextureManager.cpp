#include "pch.h"
#include "TextureManager.h"

CTextureManager::CTextureManager(){
	INIT_ARRAY(m_pTextureArray);
	INIT_STRUCT(m_memDC);
	INIT_STRUCT(m_Bitmap);
	INIT_STRUCT(m_OldBitmap);
}

CTextureManager::~CTextureManager(){
	Release();
}

CTexture* CTextureManager::GetTexture(IMG_ENUM _enum){
	return m_pTextureArray[_enum];
}

void CTextureManager::AddTexture(const TCHAR* _string, IMG_ENUM _enum){
	if(nullptr == m_pTextureArray[_enum]){
		CTexture* tempTexture = new CTexture;
		tempTexture->Initialize();
		tempTexture->AddTextureDC(m_memDC, _string);
		m_pTextureArray[_enum] = tempTexture;
	}
}

HDC CTextureManager::SetDC(HDC _hdc){
	m_memDC = CreateCompatibleDC(_hdc);
	m_Bitmap = CreateCompatibleBitmap(_hdc, WINCX, WINCY);
	m_OldBitmap = static_cast<HBITMAP>(SelectObject(m_memDC, m_Bitmap));

	return m_memDC;
}

HDC CTextureManager::GetTextureDC(IMG_ENUM _enum){
	if(m_pTextureArray[_enum])
		return m_pTextureArray[_enum]->GetTextureDC();
	else
		return nullptr;
}

void CTextureManager::Initialize(){}

void CTextureManager::Release(){
	for(int i = 0; i < IMG_END; ++i){
		if(nullptr != m_pTextureArray[i]){
			SafeDelete(m_pTextureArray[i]);
		}
	}
}

CTextureManager* CTextureManager::m_pInstance = nullptr;