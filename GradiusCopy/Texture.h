#ifndef __TEXTURE_H__
#define __TEXTURE_H__

class CTexture{
private:
	HDC m_TextureDC;
	HBITMAP m_Bitmap;
	HBITMAP m_OldBitmap;

public:
	explicit CTexture();
	virtual ~CTexture();

public:
	HDC GetTextureDC();
	void AddTextureDC(HDC _hdc, const TCHAR* FileName);
	
public:
	void Initialize();
	void Release();
};
#endif // !__TEXTURE_H__
