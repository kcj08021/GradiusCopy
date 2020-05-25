#ifndef __OBJECT_MANAGER_H__
#define __OBJECT_MANAGER_H__

class CGameObject;
class CObjectManager{
//��� ����
private:
	static CObjectManager* m_pInstance;
	list<CGameObject*> m_ObjectList[OBJ_END];
	bool m_bIsCheat;
//������ �� �Ҹ���
private:
	explicit CObjectManager();
	virtual ~CObjectManager();

//��� �Լ�
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

//�̱��� ������ ���� static ��� �Լ�
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
