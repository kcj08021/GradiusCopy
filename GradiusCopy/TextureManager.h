#ifndef __TEXTURE_MANAGER_H__
#define __TEXTURE_MANAGER_H__
#include "Texture.h"

class CTextureManager{
//멤버 변수
private:
	CTexture* m_pTextureArray[IMG_END];
	HDC m_memDC;
	HBITMAP m_Bitmap;
	HBITMAP m_OldBitmap;
	static CTextureManager* m_pInstance;

//생성자 및 소멸자
private:
	explicit CTextureManager();
	virtual ~CTextureManager();

//멤버 함수
public:
	CTexture* GetTexture(IMG_ENUM _enum);
	void AddTexture(const TCHAR* _string, IMG_ENUM _enum);
	HDC SetDC(HDC _hdc);
	HDC GetTextureDC(IMG_ENUM _enum);
private:
	void Initialize();
	void Release();

//싱글톤 패턴을 위한 함수
public:
	static CTextureManager* GetInstance(){
		if(nullptr == m_pInstance)
			m_pInstance = new CTextureManager;

		return m_pInstance;
	
	}
	static void DestroyInstance(){
		if(m_pInstance){
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}
};

#endif // !__TEXTURE_MANAGER_H__
