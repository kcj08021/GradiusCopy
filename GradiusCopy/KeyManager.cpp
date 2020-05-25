#include "pch.h"
#include "KeyManager.h"

CKeyManager::CKeyManager(): m_KeyFlag(KEY_NULL), m_KeyDownFlag(KEY_NULL), m_KeyUpFlag(KEY_NULL){

}

CKeyManager::~CKeyManager(){

}

void CKeyManager::Update(){
	m_KeyFlag = KEY_NULL;

	if(GetAsyncKeyState(VK_UP) & 0x8000)
		m_KeyFlag |= KEY_UP;
	if(GetAsyncKeyState(VK_DOWN) & 0x8000)
		m_KeyFlag |= KEY_DOWN;
	if(GetAsyncKeyState(VK_LEFT) & 0x8000)
		m_KeyFlag |= KEY_LEFT;
	if(GetAsyncKeyState(VK_RIGHT) & 0x8000)
		m_KeyFlag |= KEY_RIGHT;
	if(GetAsyncKeyState(CHAR_Z) & 0x8000)
		m_KeyFlag |= KEY_CHAR_Z;
	if(GetAsyncKeyState(CHAR_X) & 0x8000)
		m_KeyFlag |= KEY_CHAR_X;
	if(GetAsyncKeyState(CHAR_C) & 0x8000)
		m_KeyFlag |= KEY_CHAR_C;
	if(GetAsyncKeyState(CHAR_A) & 0x8000)
		m_KeyFlag |= KEY_CHAR_A;
	if(GetAsyncKeyState(CHAR_S) & 0x8000)
		m_KeyFlag |= KEY_CHAR_S;
}

bool CKeyManager::IsKeyPressing(KEYFLAG _key){
	if(m_KeyFlag & _key)
		return true;
		
	return false;
}

bool CKeyManager::IsKeyDown(KEYFLAG _key){
	if(!(m_KeyDownFlag & _key) && (m_KeyFlag & _key)){
		m_KeyDownFlag |= _key;
		return true;
	}

	if((m_KeyDownFlag & _key) && !(m_KeyFlag & _key)){
		m_KeyDownFlag ^= _key;
		return false;
	}

	return false;
}

bool CKeyManager::IsKeyUp(KEYFLAG _key){
	if((m_KeyUpFlag & _key) && !(m_KeyFlag & _key)){
		m_KeyUpFlag |= _key;
		return true;
	}

	if(!(m_KeyUpFlag & _key) && (m_KeyFlag & _key)){
		m_KeyUpFlag ^= _key;
		return false;
	}

	return false;
}

CKeyManager* CKeyManager::m_pInstance = nullptr;