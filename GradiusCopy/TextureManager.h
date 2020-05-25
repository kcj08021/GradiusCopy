#ifndef __TEXTURE_MANAGER_H__
#define __TEXTURE_MANAGER_H__
#include "Texture.h"

class CTextureManager{
//��� ����
private:
	CTexture* m_pTextureArray[IMG_END];
	HDC m_memDC;
	HBITMAP m_Bitmap;
	HBITMAP m_OldBitmap;
	static CTextureManager* m_pInstance;

//������ �� �Ҹ���
private:
	explicit CTextureManager();
	virtual ~CTextureManager();

//��� �Լ�
public:
	CTexture* GetTexture(IMG_ENUM _enum);
	void AddTexture(const TCHAR* _string, IMG_ENUM _enum);
	HDC SetDC(HDC _hdc);
	HDC GetTextureDC(IMG_ENUM _enum);
private:
	void Initialize();
	void Release();

//�̱��� ������ ���� �Լ�
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
