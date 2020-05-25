#ifndef __EFFECT_MANAGER_H__
#define __EFFECT_MANAGER_H__

class CEffectManager{
private:
	static CEffectManager* m_pInstance;

private:
	explicit CEffectManager();
	virtual ~CEffectManager();

public:
	void ObjectDead(OBJ_ENUM _enum, const INFO& _info);

private:
	void Release();
public:
	void Initialize();
	void Update();

public:
	static CEffectManager* GetInstance(){
		if(nullptr == m_pInstance)
			m_pInstance = new CEffectManager;

		return m_pInstance;
	}

	static void DestroyInstance(){
		if(m_pInstance){
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}
};

#endif // !__EFFECT_MANAGER_H__

