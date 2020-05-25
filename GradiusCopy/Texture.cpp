#include "pch.h"
#include "Texture.h"

CTexture::CTexture(){
	INIT_STRUCT(m_TextureDC);
	INIT_STRUCT(m_Bitmap);
	INIT_STRUCT(m_OldBitmap);
}

CTexture::~CTexture(){
	Release();
}

HDC CTexture::GetTextureDC(){
	return m_TextureDC;
}

void CTexture::AddTextureDC(HDC _hdc, const TCHAR* _FileName){
	m_TextureDC = CreateCompatibleDC(_hdc);

	m_Bitmap = static_cast<HBITMAP>(LoadImage(NULL, _FileName, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE));

	m_OldBitmap = static_cast<HBITMAP>(SelectObject(m_TextureDC, m_Bitmap));
}

void CTexture::Initialize(){

}

void CTexture::Release(){
	SelectObject(m_TextureDC, m_OldBitmap);
	DeleteDC(m_TextureDC);
	DeleteObject(m_Bitmap);
	DeleteObject(m_OldBitmap);
}
