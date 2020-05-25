#ifndef __OBJECT_MANAGER_H__
#define __OBJECT_MANAGER_H__

class CGameObject;
class CObjectManager{
//¸â¹ö º¯¼ö
private:
	static CObjectManager* m_pInstance;
	list<CGameObject*> m_ObjectList[OBJ_END];
	bool m_bIsCheat;
//»ý¼ºÀÚ ¹× ¼Ò¸êÀÚ
private:
	explicit CObjectManager();
	virtual ~CObjectManager();

//¸â¹ö ÇÔ¼ö
private:
	void OutOfRange(OBJ_ENUM _enum);
public:
	CGameObject* GetPlayer();
	void AddObject(OBJ_ENUM _enum, CGameObject* _obj);
	list<CGameObject*>& GetObjectList(OBJ_ENUM _enum);
	void LoadCheckPoint();

private:
	void Release();

public:
	int Update();
	void Render(HDC _hdc);

//½Ì±ÛÅæ ÆÐÅÏÀ» À§ÇÑ static ¸â¹ö ÇÔ¼ö
public:
	static CObjectManager* GetInstance(){
		if(nullptr == m_pInstance)
			m_pInstance = new CObjectManager;

		return m_pInstance;
	}

	static void DestroyInstance(){
		if(m_pInstance){
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}
};
#endif // !__OBJECT_MANAGER_H__
