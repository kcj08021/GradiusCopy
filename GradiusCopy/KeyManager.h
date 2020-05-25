#ifndef __KEY_MANAGER_H__
#define __KEY_MANAGER_H__

class CKeyManager{
//��� ����
private:
	static CKeyManager* m_pInstance;	//�̱��� ����
	KEYFLAG m_KeyFlag;
	KEYFLAG m_KeyDownFlag;
	KEYFLAG m_KeyUpFlag;

//������ �� �Ҹ���
private:
	explicit CKeyManager();
	virtual ~CKeyManager();
//��� �Լ�
public:
	void Update();
	bool IsKeyPressing(KEYFLAG _key);
	bool IsKeyDown(KEYFLAG _key);
	bool IsKeyUp(KEYFLAG _key);

//�̱��� ������ ���� static �Լ�
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
