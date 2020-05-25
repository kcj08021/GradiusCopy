#ifndef __KEY_MANAGER_H__
#define __KEY_MANAGER_H__

class CKeyManager{
//¸â¹ö º¯¼ö
private:
	static CKeyManager* m_pInstance;	//½Ì±ÛÅæ ÆÐÅÏ
	KEYFLAG m_KeyFlag;
	KEYFLAG m_KeyDownFlag;
	KEYFLAG m_KeyUpFlag;

//»ý¼ºÀÚ ¹× ¼Ò¸êÀÚ
private:
	explicit CKeyManager();
	virtual ~CKeyManager();
//¸â¹ö ÇÔ¼ö
public:
	void Update();
	bool IsKeyPressing(KEYFLAG _key);
	bool IsKeyDown(KEYFLAG _key);
	bool IsKeyUp(KEYFLAG _key);

//½Ì±ÛÅæ ÆÐÅÏÀ» À§ÇÑ static ÇÔ¼ö
public:
	static CKeyManager* GetInstance(){
		if(nullptr == m_pInstance)
			m_pInstance = new CKeyManager;

		return m_pInstance;
	}

	static void DestroyInstance(){
		if(m_pInstance){
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}
};

#endif // !__KEY_MANAGER_H__
