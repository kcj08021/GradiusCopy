#include "pch.h"
#include "Monster.h"
#include "Item.h"
#include "Boom.h"


CMonster::CMonster()
	: m_pTarget(nullptr)
{
}


CMonster::~CMonster()
{
	Release();
}

void CMonster::Initialize()
{
	/*m_tInfo.fX = 400.f;
	m_tInfo.fY = 200.f;*/
	m_tInfo.fCX = 100.f;
	m_tInfo.fCY = 100.f;

	m_fSpeed = 5.f;
}

int CMonster::Update()
{

	//IsMoving();
	//IsOutRange();

	return m_bIsDead;
}

void CMonster::Render(HDC hDC)
{
	CGameObject::UpdateRect();
	Rectangle(hDC, m_tRect.left, m_tRect.top, m_tRect.right, m_tRect.bottom);
}

void CMonster::Release()
{
	if(m_bIsDead){
		CEffectManager::GetInstance()->ObjectDead(OBJ_MONSTER, m_tInfo);

		int iRandom = rand() % 101;
		if(iRandom <= 20){
			if(iRandom & 1){
				CGameObject* obj = CAbstractFactory<CItem>::CreateObject(m_tInfo.fX, m_tInfo.fY);
				CObjectManager::GetInstance()->AddObject(OBJ_ITEM, obj);
			}
			else{
				CGameObject* obj = CAbstractFactory<CBoom>::CreateObject(m_tInfo.fX, m_tInfo.fY);
				CObjectManager::GetInstance()->AddObject(OBJ_BOOM, obj);
			}
		}
	}
}

void CMonster::IsMoving()
{

}

