#include "pch.h"
#include "PatternManager.h"
//=====================================
// 잡몹 헤더

#include "DE.h"
#include "Ducker.h"
#include "Garun.h"
#include "Jumper.h"
#include "Minian.h"
#include "Pence.h"
#include "Rugal.h"

//====================================
// 보스 헤더

#include "Big_Core.h"

//====================================
#include "Map.h"
#include "MapGround.h"
#include "MapObject.h"

PatternMgr* PatternMgr::m_pInstance = nullptr;

PatternMgr::PatternMgr()
	:m_stop(false), m_Timer(0.f), m_RaidTime(0), m_bBoss(false), m_fCheckPoint(0.f){
}

PatternMgr::~PatternMgr(){
}

bool PatternMgr::IsVolcano(){
	if(m_Timer >= 6100.f){
		if(m_RaidTime <= 350 && m_stop == true){
			if(m_RaidTime % 14 == 0){
				float x = PLAYREGION_X * 0.5 - 125;
				float y = 450;
				CGameObject* pGameObject = CAbstractFactory<Minian>::CreateObject(x, y);
				CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
			}
			if(m_RaidTime % 18 == 0){
				float x = PLAYREGION_X * 0.5 + 255;
				float y = 450;
				CGameObject* pGameObject2 = CAbstractFactory<Minian>::CreateObject(x, y);
				CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject2);
			}
		} else{
			m_stop = false;
			dynamic_cast<CMap*>(CObjectManager::GetInstance()->GetObjectList(OBJ_MAP).front())->SetIsMapStop(m_stop);
			OBJLIST::iterator elem = CObjectManager::GetInstance()->GetObjectList(OBJ_MAPOBJECT).begin();
			++elem;
			++elem;
			for(; elem != CObjectManager::GetInstance()->GetObjectList(OBJ_MAPOBJECT).end(); ++elem){
				dynamic_cast<CMapObject*>(*elem)->SetIsMove(true);
			}
			m_RaidTime = 0;
		}
	}
	return m_stop;
}

bool PatternMgr::IsBoss(){
	if(m_Timer >= 6649.f){
		if(m_bBoss){
			m_stop = false;
		}
		if(m_stop && !CObjectManager::GetInstance()->GetObjectList(OBJ_BOSS).size()){
			CGameObject* pGameObject = CAbstractFactory<Big_Core>::CreateObject();
			CObjectManager::GetInstance()->AddObject(OBJ_BOSS, pGameObject);
		}

	}
	return m_stop;
}

void PatternMgr::LoadCheckPoint(){
	if(m_Timer == 6649.f){
		CGameObject* pGameObject = CAbstractFactory<CMapGround>::CreateObject(PLAYREGION_X / 2, MAPOBJ_GROUND_INIT_DOWNY);
		CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
		pGameObject = CAbstractFactory<CMapGround>::CreateObject(PLAYREGION_X / 2, MAPOBJ_GROUND_INIT_UPY);
		CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
	}
	m_Timer = m_fCheckPoint;
	if(m_Timer == 0){
		for(auto elem : CObjectManager::GetInstance()->GetObjectList(OBJ_MAPOBJECT))
			SafeDelete(elem);
		CObjectManager::GetInstance()->GetObjectList(OBJ_MAPOBJECT).clear();
	}

	dynamic_cast<CMap*>(CObjectManager::GetInstance()->GetObjectList(OBJ_MAP).front())->LoadCheckPoint();

	if(m_stop){
		m_stop = false;
		dynamic_cast<CMap*>(CObjectManager::GetInstance()->GetObjectList(OBJ_MAP).front())->SetIsMapStop(m_stop);
	}
}

void PatternMgr::SetBossDie(bool _bool){
	m_bBoss = _bool;
}


float PatternMgr::GetTimer(){
	return m_Timer;
}

float PatternMgr::GetRTime(){
	return m_RaidTime;
}

bool PatternMgr::GetIsStop(){
	return m_stop;
}


void PatternMgr::Update(){

	if(!m_stop){
		m_Timer++;
	} else
		m_RaidTime++;

	PawnSpawn();
}

PatternMgr* PatternMgr::GetInstance(){
	{
		if(nullptr == m_pInstance)
			m_pInstance = new PatternMgr;

		return m_pInstance;
	}
}


void PatternMgr::PawnSpawn(){
	CGameObject* pGameObject = nullptr;

	//// 첫 시작
	//본격적 맵 시작 시간 3475.f
	if(m_Timer == 120.f){
		for(int i = 0; i < 4; ++i){
			float x = 600 + (i * 50);
			float y = 100;

			pGameObject = CAbstractFactory<Pence>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}

	if(m_Timer == 180.f){
		for(int i = 0; i < 4; ++i){
			float x = 600 + (i * 50);
			float y = 500;

			pGameObject = CAbstractFactory<Pence>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}
	if(m_Timer == 270.f){
		for(int i = 0; i < 4; ++i){
			float x = 600 + (i * 50);
			float y = 100;

			pGameObject = CAbstractFactory<Pence>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}
	if(m_Timer == 360.f){
		for(int i = 0; i < 4; ++i){
			float x = 600 + (i * 50);
			float y = 500;

			pGameObject = CAbstractFactory<Pence>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}
	if(m_Timer == 450.f){
		for(int i = 0; i < 4; ++i){
			float x = 600 + (i * 50);
			float y = 100;

			pGameObject = CAbstractFactory<Pence>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}
	if(m_Timer == 540.f){
		for(int i = 0; i < 3; ++i){
			float x = 700;
			float y = 200 + (i * 110);

			pGameObject = CAbstractFactory<Rugal>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}
	if(m_Timer == 600.f){
		for(int i = 0; i < 3; ++i){
			float x = 700;
			float y = 230 + (i * 110);

			pGameObject = CAbstractFactory<Rugal>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}
	if(m_Timer == 670.f){
		for(int i = 0; i < 3; ++i){
			float x = 700;
			float y = 260 + (i * 110);

			pGameObject = CAbstractFactory<Rugal>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}
	if(m_Timer == 740.f){
		for(int i = 0; i < 3; ++i){
			float x = 700;
			float y = 230 + (i * 110);

			pGameObject = CAbstractFactory<Rugal>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}
	if(m_Timer == 810.f){
		for(int i = 0; i < 4; ++i){
			float x = 600 + (i * 50);
			float y = 200;

			pGameObject = CAbstractFactory<Pence>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}
	if(m_Timer == 900.f){
		for(int i = 0; i < 4; ++i){
			float x = 600 + (i * 50);
			float y = 500;

			pGameObject = CAbstractFactory<Pence>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}
	if(m_Timer == 990.f){
		for(int i = 0; i < 4; ++i){
			float x = 600 + (i * 50);
			float y = 100;

			pGameObject = CAbstractFactory<Pence>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}
	if(m_Timer == 1080.f){
		for(int i = 0; i < 3; ++i){
			float x = 700;
			float y = 200 + (i * 110);

			pGameObject = CAbstractFactory<Rugal>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}
	if(m_Timer == 1150.f){
		for(int i = 0; i < 3; ++i){
			float x = 700;
			float y = 230 + (i * 110);

			pGameObject = CAbstractFactory<Rugal>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}
	if(m_Timer == 1220.f){
		for(int i = 0; i < 3; ++i){
			float x = 700;
			float y = 260 + (i * 110);

			pGameObject = CAbstractFactory<Rugal>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}
	if(m_Timer == 1280.f){
		for(int i = 0; i < 2; ++i){
			float x = 700;
			float y = 300 + (i * 150);

			pGameObject = CAbstractFactory<Garun>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}
	if(m_Timer == 1390.f){
		for(int i = 0; i < 2; ++i){
			float x = 700;
			float y = 350 + (i * 150);

			pGameObject = CAbstractFactory<Garun>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}

	if(m_Timer == 1500.f){
		for(int i = 0; i < 2; ++i){
			float x = 700;
			float y = 300 + (i * 150);

			pGameObject = CAbstractFactory<Garun>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}

	//땅과 천장
	if(m_Timer == 1540.f){
		pGameObject = CAbstractFactory<CMapGround>::CreateObject();
		pGameObject->SetPos(MAPOBJ_GROUND_INIT_X, MAPOBJ_GROUND_INIT_DOWNY);
		CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);

		pGameObject = CAbstractFactory<CMapGround>::CreateObject();
		pGameObject->SetPos(MAPOBJ_GROUND_INIT_X, MAPOBJ_GROUND_INIT_UPY);
		CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
	}

	//필드 몹 시작
	if(m_Timer == 1550.f){
		for(int i = 0; i < 3; ++i){
			float x = 700;
			float y = 200 + (i * 90);

			pGameObject = CAbstractFactory<Rugal>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}

	}



	if(m_Timer == 1620.f){
		for(int i = 0; i < 3; ++i){
			float x = 700;
			float y = 250 + (i * 90);

			pGameObject = CAbstractFactory<Rugal>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}

	if(m_Timer == 1690.f){
		for(int i = 0; i < 3; ++i){
			float x = 700;
			float y = 300 + (i * 90);

			pGameObject = CAbstractFactory<Rugal>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}



	if(m_Timer == 1800.f){
		for(int i = 0; i < 2; ++i){
			float x = 700 + (i * 60);
			float y = 40;

			pGameObject = CAbstractFactory<DE>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}


	//산1
	{
		if(m_Timer == 1880.f){
			pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 565);
			CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
		}

		if(m_Timer == 1890.f){
			pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 535);
			CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
		}


		if(m_Timer == 1900.f){
			pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 505);
			CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
		}

		if(m_Timer == 1915.f){
			pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 475);
			CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
		}

		if(m_Timer == 1930.f){
			pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 505);
			CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
		}
		if(m_Timer == 1945.f){
			pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 535);
			CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
		}
		if(m_Timer == 1955.f){
			pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 565);
			CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
		}
	};


	if(m_Timer == 1855.f){
		for(int i = 0; i < 2; ++i){
			float x = 720 + (i * 60);
			float y = PLAYREGION_Y - 50;

			pGameObject = CAbstractFactory<Jumper>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}



	if(m_Timer == 1945.f){
		for(int i = 0; i < 2; ++i){
			float x = 700;
			float y = 250 + (i * 100);

			pGameObject = CAbstractFactory<Rugal>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}


	if(m_Timer == 2035.f){
		for(int i = 0; i < 3; ++i){
			float x = 700;
			float y = 200 + (i * 90);

			pGameObject = CAbstractFactory<Rugal>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}


	if(m_Timer == 2085.f){
		{
			float x = 0;
			float y = 40;
			pGameObject = CAbstractFactory<Ducker>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);

			x = 0;
			y = 560;
			pGameObject = CAbstractFactory<Ducker>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}




	if(m_Timer == 2140.f){
		for(int i = 0; i < 2; ++i){
			float x = 700;
			float y = 300 + (i * 100);

			pGameObject = CAbstractFactory<Garun>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}

	//천장 장애물
	if(m_Timer == 2090.f){
		pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 40);
		CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
	}
	if(m_Timer == 2110.f){
		pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 40);
		CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
	}
	if(m_Timer == 2130.f){
		pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 40);
		CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
	}
	if(m_Timer == 2150.f){
		pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 40);
		CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
	}

	if(m_Timer == 2250.f){
		for(int i = 0; i < 2; ++i){
			float x = 700;
			float y = 350 + (i * 100);

			pGameObject = CAbstractFactory<Garun>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}


	if(m_Timer == 2300.f){
		for(int i = 0; i < 2; ++i){
			float x = 700 + (i * 60);
			float y = 560;

			pGameObject = CAbstractFactory<DE>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}


	if(m_Timer == 2400.f){
		for(int i = 0; i < 2; ++i){
			float x = 700;
			float y = 300 + (i * 100);

			pGameObject = CAbstractFactory<Garun>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}


	if(m_Timer == 2460.f){
		for(int i = 0; i < 2; ++i){
			float x = 700 - (i * 60);
			float y = 540;

			pGameObject = CAbstractFactory<Jumper>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}




	if(m_Timer == 2520.f){
		{
			float x = 0;
			float y = 560;
			pGameObject = CAbstractFactory<Ducker>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);

			x = 0;
			y = 40;
			pGameObject = CAbstractFactory<Ducker>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}

	if(m_Timer == 2640.f){
		for(int i = 0; i < 2; ++i){
			float x = 700;
			float y = 300 + (i * 100);

			pGameObject = CAbstractFactory<Garun>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}

	if(m_Timer == 2750.f){
		for(int i = 0; i < 2; ++i){
			float x = 700;
			float y = 350 + (i * 110);

			pGameObject = CAbstractFactory<Garun>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}


	if(m_Timer == 2800.f){
		dynamic_cast<CMap*>(CObjectManager::GetInstance()->GetObjectList(OBJ_MAP).front())->SetCheckPoint();
		m_fCheckPoint = m_Timer;
	}


	if(m_Timer == 2860.f){
		for(int i = 0; i < 2; ++i){
			float x = 700;
			float y = 400 + (i * 110);

			pGameObject = CAbstractFactory<Garun>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}


	if(m_Timer == 2970.f){
		for(int i = 0; i < 2; ++i){
			float x = 700;
			float y = 350 + (i * 110);

			pGameObject = CAbstractFactory<Garun>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}

	//산2
	if(m_Timer == 2960.f){
		pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 565);
		CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
	}

	if(m_Timer == 2970.f){
		pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 550);
		CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
	}

	if(m_Timer == 2990.f){
		pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 550);
		CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
	}

	if(m_Timer == 3020.f){
		pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 435);
		CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
	}
	if(m_Timer == 3035){
		pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 405);
		CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
	}
	if(m_Timer == 3050.f){
		pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 435);
		CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
	}


	if(m_Timer == 3010.f){
		pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 550);
		CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
	}
	if(m_Timer == 3030.f){
		pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 550);
		CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
	}
	if(m_Timer == 3050.f){
		pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 550);
		CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
	}
	if(m_Timer == 3070.f){
		pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 550);
		CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
	}
	if(m_Timer == 3090.f){
		pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 550);
		CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
	}
	if(m_Timer == 3110.f){
		pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 565);
		CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
	}

	if(m_Timer == 3080.f){
		for(int i = 0; i < 2; ++i){
			float x = 700;
			float y = 300 + (i * 110);

			pGameObject = CAbstractFactory<Garun>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}


	if(m_Timer == 3130.f){
		float x = 0;
		float y = 560;
		pGameObject = CAbstractFactory<Ducker>::CreateObject(x, y);
		CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
	}

	if(m_Timer == 3170.f){
		float x = 0;
		float y = 40;
		pGameObject = CAbstractFactory<Ducker>::CreateObject(x, y);
		CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
	}


	if(m_Timer == 3270.f){
		{
			float x = 0;
			float y = 540;
			pGameObject = CAbstractFactory<Jumper>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}

	if(m_Timer == 3320.f){
		for(int i = 0; i < 2; ++i){
			float x = 700;
			float y = 200 + (i * 100);

			pGameObject = CAbstractFactory<Rugal>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}


	if(m_Timer == 3390.f){
		for(int i = 0; i < 3; ++i){
			float x = 700;
			float y = 250 + (i * 70);

			pGameObject = CAbstractFactory<Rugal>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}


	if(m_Timer == 3460.f){
		for(int i = 0; i < 2; ++i){
			float x = 700;
			float y = 300 + (i * 100);

			pGameObject = CAbstractFactory<Rugal>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}

	if(m_Timer == 3500.f){
		{
			float x = 0;
			float y = 540;
			pGameObject = CAbstractFactory<Jumper>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}


	if(m_Timer == 3540.f){
		for(int i = 0; i < 2; ++i){
			float x = 700;
			float y = 300 + (i * 100);

			pGameObject = CAbstractFactory<Garun>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}


	if(m_Timer == 3650.f){
		for(int i = 0; i < 2; ++i){
			float x = 700;
			float y = 350 + (i * 100);

			pGameObject = CAbstractFactory<Garun>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}
	if(m_Timer == 3645.f){
		pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 40);
		CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
	}

	if(m_Timer == 3665.f){
		pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 40);
		CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
	}
	if(m_Timer == 3685.f){
		pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 40);
		CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
	}
	if(m_Timer == 3705.f){
		pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 40);
		CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
	}


	if(m_Timer == 3725.f){
		for(int i = 0; i < 2; ++i){
			float x = 700 + (i * 60);
			float y = 560;

			pGameObject = CAbstractFactory<DE>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}



	if(m_Timer == 3875.f){
		for(int i = 0; i < 2; ++i){
			float x = 700;
			float y = 200 + (i * 100);

			pGameObject = CAbstractFactory<Rugal>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}

	//산3
	{
		if(m_Timer == 3920.f){
			pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 565);
			CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
		}
		if(m_Timer == 3930.f){
			pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 535);
			CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
		}if(m_Timer == 3950.f){
			pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 505);
			CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
		}if(m_Timer == 3960.f){
			pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 475);
			CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
		}if(m_Timer == 3980.f){
			pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 445);
			CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
		}if(m_Timer == 3990.f){
			pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 415);
			CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
		}
		if(m_Timer == 3995.f){
			pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 405);
			CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
		}
		if(m_Timer == 4000.f){
			pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 415);
			CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
		}if(m_Timer == 4010.f){
			pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 445);
			CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
		}if(m_Timer == 4020.f){
			pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 475);
			CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
		}
		if(m_Timer == 4030.f){
			pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 505);
			CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
		}
		if(m_Timer == 4050.f){
			pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 535);
			CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
		}
		if(m_Timer == 4060.f){
			pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 555);
			CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
		}
		if(m_Timer == 4070.f){
			pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 565);
			CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
		}
	};

	if(m_Timer == 3945.f){
		for(int i = 0; i < 2; ++i){
			float x = 700;
			float y = 300 + (i * 100);

			pGameObject = CAbstractFactory<Garun>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}


	if(m_Timer == 4055.f){
		for(int i = 0; i < 2; ++i){
			float x = 700;
			float y = 350 + (i * 100);

			pGameObject = CAbstractFactory<Garun>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}

	if(m_Timer == 4100.f){
		{
			float x = 0;
			float y = 540;
			pGameObject = CAbstractFactory<Jumper>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}

	if(m_Timer == 4190.f){
		for(int i = 0; i < 2; ++i){
			float x = 700;
			float y = 200 + (i * 100);

			pGameObject = CAbstractFactory<Rugal>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}


	if(m_Timer == 4250.f){
		for(int i = 0; i < 2; ++i){
			float x = 700;
			float y = 300 + (i * 100);

			pGameObject = CAbstractFactory<Garun>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}


	if(m_Timer == 4360.f){
		for(int i = 0; i < 2; ++i){
			float x = 700;
			float y = 350 + (i * 100);

			pGameObject = CAbstractFactory<Garun>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}

	if(m_Timer == 4400.f){
		{
			float x = 0;
			float y = 40;
			pGameObject = CAbstractFactory<Ducker>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}

	if(m_Timer == 4420.f){
		{
			float x = 0;
			float y = 40;
			pGameObject = CAbstractFactory<Ducker>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}

	if(m_Timer == 4490.f){
		for(int i = 0; i < 2; ++i){
			float x = 700;
			float y = 200 + (i * 100);

			pGameObject = CAbstractFactory<Rugal>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}


	if(m_Timer == 4510.f){
		{
			float x = 0;
			float y = 560;
			pGameObject = CAbstractFactory<Ducker>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}


	if(m_Timer == 4550.f){
		for(int i = 0; i < 2; ++i){
			float x = 700 + (i * 60);
			float y = 40;

			pGameObject = CAbstractFactory<DE>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}



	if(m_Timer == 4590.f){
		for(int i = 0; i < 2; ++i){
			float x = 700;
			float y = 300 + (i * 100);

			pGameObject = CAbstractFactory<Garun>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}

	if(m_Timer == 4700.f){

		for(int i = 0; i < 2; ++i){
			float x = 700;
			float y = 350 + (i * 100);

			pGameObject = CAbstractFactory<Garun>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}

	//천장 장애물
	if(m_Timer == 4670.f){
		pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 40);
		CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
	}
	if(m_Timer == 4690.f){
		pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 40);
		CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
	}
	if(m_Timer == 4710.f){
		pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 40);
		CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
	}
	if(m_Timer == 4730.f){
		pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 40);
		CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
	}

	if(m_Timer == 4810.f){
		for(int i = 0; i < 2; ++i){
			float x = 700;
			float y = 200 + (i * 100);

			pGameObject = CAbstractFactory<Rugal>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}

	if(m_Timer == 4600){
		dynamic_cast<CMap*>(CObjectManager::GetInstance()->GetObjectList(OBJ_MAP).front())->SetCheckPoint();
		m_fCheckPoint = m_Timer;
	}

	if(m_Timer == 4880.f){
		for(int i = 0; i < 2; ++i){
			float x = 700;
			float y = 250 + (i * 100);

			pGameObject = CAbstractFactory<Rugal>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}

	if(m_Timer == 4930.f){
		for(int i = 0; i < 2; ++i){
			float x = 700 + (i * 60);
			float y = 40;

			pGameObject = CAbstractFactory<DE>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}




	if(m_Timer == 5000.f){
		for(int i = 0; i < 2; i++){
			float x = 0 - (i * 50);
			float y = 560;
			pGameObject = CAbstractFactory<Ducker>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);

			x = 0 - (i * 50);
			y = 40;
			pGameObject = CAbstractFactory<Ducker>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}




	if(m_Timer == 5110.f){
		for(int i = 0; i < 5; i++){
			float x = 0 - (i * 50);
			float y = 540;
			pGameObject = CAbstractFactory<Jumper>::CreateObject(x, y);
			CObjectManager::GetInstance()->AddObject(OBJ_MONSTER, pGameObject);
		}
	}
	//장애물
	{
		if(m_Timer == 5205.f){
			pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 280);
			CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
		}
		if(m_Timer == 5215.f){
			pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 250);
			CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
		}

		if(m_Timer == 5225){
			pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 220);
			CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
		}

		if(m_Timer == 5240.f){
			pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 190);
			CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
		}

		if(m_Timer == 5255.f){
			pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 220);
			CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
		}
		if(m_Timer == 5265.f){
			pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 250);
			CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
		}
		if(m_Timer == 5275.f){
			pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 280);
			CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
		}

		if(m_Timer == 5215.f){
			pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 310);
			CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
		}

		if(m_Timer == 5225){
			pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 340);
			CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
		}

		if(m_Timer == 5240.f){
			pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 370);
			CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
		}

		if(m_Timer == 5255.f){
			pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 340);
			CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
		}
		if(m_Timer == 5265.f){
			pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 310);
			CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
		}


	};

	//화산1
	{
		if(m_Timer == 5720.f){
			pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 565);
			CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
		}

		if(m_Timer == 5730.f){
			pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 535);
			CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
		}

		if(m_Timer == 5740.f){
			pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 505);
			CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
		}

		if(m_Timer == 5755.f){
			pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 475);
			CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
		}

		if(m_Timer == 5770.f){
			pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 505);
			CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
		}
		if(m_Timer == 5785.f){
			pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 535);
			CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
		}
		if(m_Timer == 5795.f){
			pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 565);
			CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
		}

	}
	//화산2
	{
		if(m_Timer == 5975.f){
			pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 565);
			CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
		}

		if(m_Timer == 5985.f){
			pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 535);
			CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
		}

		if(m_Timer == 5995.f){
			pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 505);
			CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
		}

		if(m_Timer == 6010.f){
			pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 475);
			CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
		}

		if(m_Timer == 6025.f){
			pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 505);
			CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
		}
		if(m_Timer == 6040.f){
			pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 535);
			CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
		}
		if(m_Timer == 6050.f){
			pGameObject = CAbstractFactory<CMapObject>::CreateObject(PLAYREGION_X + MAPOBJ_OBJECT_CX / 2 - 1, 565);
			CObjectManager::GetInstance()->AddObject(OBJ_MAPOBJECT, pGameObject);
		}

	};


	if(m_Timer == 6100.f){
		m_stop = true;
		dynamic_cast<CMap*>(CObjectManager::GetInstance()->GetObjectList(OBJ_MAP).front())->SetIsMapStop(m_stop);
		OBJLIST::iterator elem = CObjectManager::GetInstance()->GetObjectList(OBJ_MAPOBJECT).begin();
		++elem;
		++elem;
		for(; elem != CObjectManager::GetInstance()->GetObjectList(OBJ_MAPOBJECT).end(); ++elem){
			dynamic_cast<CMapObject*>(*elem)->SetIsMove(false);
		}
		IsVolcano();
	}

	//지상 구간 끝
	if(m_Timer == 6150.f){
		if(CObjectManager::GetInstance()->GetObjectList(OBJ_MAPOBJECT).size()){
			dynamic_cast<CMapGround*>(*CObjectManager::GetInstance()->GetObjectList(OBJ_MAPOBJECT).begin())->SetIsMove(true);
			dynamic_cast<CMapGround*>(*++CObjectManager::GetInstance()->GetObjectList(OBJ_MAPOBJECT).begin())->SetIsMove(true);
		}
	}

	if(m_Timer == 6649.f){
		//보스 몬스터
		m_stop = true;
		IsBoss();
		dynamic_cast<CMap*>(CObjectManager::GetInstance()->GetObjectList(OBJ_MAP).front())->SetIsMapStop(m_stop);

	}

	if(!m_stop && m_bBoss){
		Initialize();
	}
}

void PatternMgr::Initialize(){
	m_Timer = 0.f;
	m_fCheckPoint = 0.f;
	m_RaidTime = 0;
	m_bBoss = false;
	m_stop = false;
}
