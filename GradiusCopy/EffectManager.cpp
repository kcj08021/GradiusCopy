#include "pch.h"
#include "EffectManager.h"
#include "Effect.h"

CEffectManager::CEffectManager(){

}

CEffectManager::~CEffectManager(){

}

void CEffectManager::ObjectDead(OBJ_ENUM _enum, const INFO& _info){
	CEffect* pObj = dynamic_cast<CEffect*>(CAbstractFactory<CEffect>::CreateObject(_info));
	pObj->SetEnum(_enum);

	CObjectManager::GetInstance()->AddObject(OBJ_EFFECT, pObj);
}

void CEffectManager::Release(){
}

void CEffectManager::Initialize(){
	CTextureManager::GetInstance()->AddTexture(STRING_IMG_PLAYER_DEAD, IMG_PLAYER_DEAD);
	CTextureManager::GetInstance()->AddTexture(STRING_IMG_ENEMY_DEAD, IMG_ENEMY_DEAD);
	CTextureManager::GetInstance()->AddTexture(STRING_IMG_PANCE_DEAD, IMG_PENCE_DEAD);
	CTextureManager::GetInstance()->AddTexture(STRING_IMG_BOSS_DEAD, IMG_BOSS_DEAD);
}

void CEffectManager::Update(){

}

CEffectManager* CEffectManager::m_pInstance = nullptr;