#ifndef __ABSTRACT_FACTORY_H__
#define __ABSTRACT_FACTORY_H__
#include "GameObject.h"
#include "EnemyBullet.h"

template <typename T>
class CAbstractFactory{
public:
	static CGameObject* CreateObject(){
		CGameObject* obj = new T;
		obj->Initialize();

		return obj;
	}

	static CGameObject* CreateObject(float _x, float _y){
		CGameObject* obj = new T;
		obj->Initialize();
		obj->SetPos(_x, _y);

		return obj;
	}

	static CGameObject* CreateObject(const INFO& _info){
		CGameObject* obj = new T;
		obj->Initialize();
		dynamic_cast<T*>(obj)->SetInfo(_info);

		return obj;
	}

	static CGameObject* CreateObject(float x, float y, float angle){
		CGameObject* pInstance = new T;
		pInstance->Initialize();
		pInstance->SetPos(x, y);
		pInstance->SetAngle(angle);

		return pInstance;
	}


	static CGameObject* CreateObject(float x, float y, float angle, BULLIT_TYPE eTyp){
		CGameObject* pInstance = new T;
		pInstance->Initialize();
		pInstance->SetPos(x, y);
		pInstance->SetAngle(angle);
		dynamic_cast<EnemyBullet*>(pInstance)->SetType(eTyp);

		return pInstance;
	}
};


#endif // !__ABSTRACT_FACTORY_H__


