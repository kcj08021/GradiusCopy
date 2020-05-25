#include "pch.h"
#include "ObjectManager.h"
#include "Player.h"
#include "UI.h"

CObjectManager::CObjectManager(): m_bIsCheat(false){

}

CObjectManager::~CObjectManager(){
	Release();
}

void CObjectManager::OutOfRange(OBJ_ENUM _enum){
	RECT rc = {0,0,PLAYREGION_X,PLAYREGION_Y};
	RECT rc2;

	for(list<CGameObject*>::iterator elem = m_ObjectList[_enum].begin(); elem != m_ObjectList[_enum].end(); ++elem){
		if(!IntersectRect(&rc2, &rc, &(*elem)->GetRect())){
			SafeDelete(*elem);
			elem = m_ObjectList[_enum].erase(elem);
		}
		if(elem == m_ObjectList[_enum].end())
			break;
	}

}

CGameObject* CObjectManager::GetPlayer(){
	if(m_ObjectList[OBJ_PLAYER].empty())
		return nullptr;

	return m_ObjectList[OBJ_PLAYER].front();
}

void CObjectManager::AddObject(OBJ_ENUM _enum, CGameObject* _obj){
	if(_obj){
		m_ObjectList[_enum].push_back(_obj);
	}
}

list<CGameObject*>& CObjectManager::GetObjectList(OBJ_ENUM _enum){
	return m_ObjectList[_enum];
}

void CObjectManager::LoadCheckPoint(){
	//if(nullptr != m_ObjectList[OBJ_PLAYER].front())
	//	SafeDelete(m_ObjectList[OBJ_PLAYER].front());
	//m_ObjectList[OBJ_PLAYER].clear();

	//UI 초기화
	SafeDelete(m_ObjectList[OBJ_UI].front());
	m_ObjectList[OBJ_UI].clear();


	for(CGameObject* elem : m_ObjectList[OBJ_BULLET])
		SafeDelete(elem);
	m_ObjectList[OBJ_BULLET].clear();

	for(CGameObject* elem : m_ObjectList[OBJ_MISSILE])
		SafeDelete(elem);
	m_ObjectList[OBJ_MISSILE].clear();

	for(CGameObject* elem : m_ObjectList[OBJ_ADDON])
		SafeDelete(elem);
	m_ObjectList[OBJ_ADDON].clear();

	for(CGameObject* elem : m_ObjectList[OBJ_SHIELD])
		SafeDelete(elem);
	m_ObjectList[OBJ_SHIELD].clear();


	//몬스터 초기화
	for(CGameObject* elem : m_ObjectList[OBJ_MONSTER])
		SafeDelete(elem);
	m_ObjectList[OBJ_MONSTER].clear();
	
	if(m_ObjectList[OBJ_BOSS].size()){
		SafeDelete(m_ObjectList[OBJ_BOSS].front());
		m_ObjectList[OBJ_BOSS].clear();
	}

			//아이템
	for(CGameObject* elem : m_ObjectList[OBJ_ITEM])
		SafeDelete(elem);
	m_ObjectList[OBJ_ITEM].clear();

	for(CGameObject* elem : m_ObjectList[OBJ_BOOM])
		SafeDelete(elem);
	m_ObjectList[OBJ_BOOM].clear();


	for(CGameObject* elem : m_ObjectList[OBJ_ENEMYBULLET])
		SafeDelete(elem);
	m_ObjectList[OBJ_ENEMYBULLET].clear();

	if(m_ObjectList[OBJ_MAPOBJECT].size()){
		OBJLIST::iterator elem = m_ObjectList[OBJ_MAPOBJECT].begin();
		++elem;
		++elem;
		while(true){
			SafeDelete(*elem);
			elem = m_ObjectList[OBJ_MAPOBJECT].erase(elem);

			if(elem == m_ObjectList[OBJ_MAPOBJECT].end())
				break;
		}
	}

	CGameObject* pObj = CAbstractFactory<CPlayer>::CreateObject();
	AddObject(OBJ_PLAYER, pObj);

	pObj = CAbstractFactory<CUI>::CreateObject();
	AddObject(OBJ_UI, pObj);

	PatternMgr::GetInstance()->LoadCheckPoint();
}

void CObjectManager::Release(){
	for(int i = 0; i < OBJ_END; ++i){
		for(CGameObject* obj : m_ObjectList[i]){
			SafeDelete(obj);
		}
		m_ObjectList[i].clear();
	}
}

int CObjectManager::Update(){
	if(CKeyManager::GetInstance()->IsKeyDown(KEY_CHAR_S))
		m_bIsCheat = !m_bIsCheat;
	
	for(int i = 0; i < OBJ_END; ++i){
		for(list<CGameObject*>::iterator elem = m_ObjectList[i].begin(); elem != m_ObjectList[i].end(); ++elem){
			if((*elem)->Update()){
				SafeDelete(*elem);
				elem = m_ObjectList[i].erase(elem);
			}
			if(elem == m_ObjectList[i].end())
				break;
		}
	}

	CCollsionMgr::CollisionSphere(m_ObjectList[OBJ_BULLET], m_ObjectList[OBJ_MONSTER]);
	CCollsionMgr::CollisionSphere(m_ObjectList[OBJ_MISSILE], m_ObjectList[OBJ_MONSTER]);
	CCollsionMgr::CollisionSphere(m_ObjectList[OBJ_BULLET], m_ObjectList[OBJ_BOSS]);
	CCollsionMgr::CollisionSphere(m_ObjectList[OBJ_MISSILE], m_ObjectList[OBJ_BOSS]);
	if(!m_bIsCheat){
		if(m_ObjectList[OBJ_PLAYER].size()){
			CCollsionMgr::CollisionSphere(m_ObjectList[OBJ_PLAYER], m_ObjectList[OBJ_MONSTER]);
			CCollsionMgr::CollisionSphere(m_ObjectList[OBJ_PLAYER], m_ObjectList[OBJ_ENEMYBULLET]);
			if(m_ObjectList[OBJ_MAPOBJECT].size() >= 2){
				OBJLIST::iterator iter = m_ObjectList[OBJ_MAPOBJECT].begin();
				CCollsionMgr::CollisionRect(m_ObjectList[OBJ_PLAYER].front(), m_ObjectList[OBJ_MAPOBJECT].front());
				CCollsionMgr::CollisionRectEX(m_ObjectList[OBJ_PLAYER].front(), *(++iter));

				if(m_ObjectList[OBJ_MAPOBJECT].size() > 2){
					++iter;
					while(true){
						if(iter == m_ObjectList[OBJ_MAPOBJECT].end())
							break;
						CCollsionMgr::CollisionRect(m_ObjectList[OBJ_PLAYER].front(), *iter);
						++iter;

						if(iter == m_ObjectList[OBJ_MAPOBJECT].end())
							break;
					}
				}
			}
		}
	}
	CCollsionMgr::CollisionSphere(m_ObjectList[OBJ_PLAYER], m_ObjectList[OBJ_ITEM]);
	CCollsionMgr::CollisionSphere(m_ObjectList[OBJ_PLAYER], m_ObjectList[OBJ_BOOM]);

	CCollsionMgr::CollisionSphere(m_ObjectList[OBJ_SHIELD], m_ObjectList[OBJ_ENEMYBULLET]);
	CCollsionMgr::CollisionSphere(m_ObjectList[OBJ_SHIELD], m_ObjectList[OBJ_MONSTER]);


	OutOfRange(OBJ_BULLET);
	OutOfRange(OBJ_MISSILE);
	OutOfRange(OBJ_MONSTER);
	OutOfRange(OBJ_ENEMYBULLET);
	OutOfRange(OBJ_ITEM);
	OutOfRange(OBJ_BOOM);
	OutOfRange(OBJ_MAPOBJECT);


	return 0;
}

void CObjectManager::Render(HDC _hdc){
	for(int i = 0; i < OBJ_END; ++i){
		for(CGameObject* obj : m_ObjectList[i]){
			obj->Render(_hdc);
		}
	}
}

CObjectManager* CObjectManager::m_pInstance = nullptr;