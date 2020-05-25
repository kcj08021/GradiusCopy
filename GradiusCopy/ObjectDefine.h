#ifndef __OBJECT_DEFINE_H__
#define __OBJECT_DEFINE_H__


#define TITLE2_CX 201
#define TITLE2_CY 48

//오브젝트 관련 상수
//플레이어
#define PLAYER_CX 84.f
#define PLAYER_CY 42.f
#define PLAYER_INIT_X 100.f;
#define PLAYER_INIT_Y 300.f;
#define PLAYER_SPEED 3.f
#define PLAYER_SPEEDUP 1.f

//애드온
#define ADDON_CX 54.f
#define ADDON_CY 36.f
#define ADDON_DIST 40.f
#define ADDON_FULL 2

//탄환
#define BULLET_CX 30.f
#define BULLET_CY 27.f
#define BULLET_SPPED 10.f

#define DBULLET_CX 27.f
#define DBULLET_CY 27.f
#define DBULLET_SPPED BULLET_SPPED

//미사일
#define MISSILE_CX 30.f
#define MISSILE_CY 30.f
#define MISSILE_SPEED

//레이저
#define LASER_CX 48.f
#define LASER_CY 6.f
#define LASER_SPEED 30.f

//쉴드
#define SHIELD_CX 30.f
#define SHILED_CY 54.f
#define SHILED_DIST 65.f
#define SHIELD_FULL 1

//몬스터
#define MONSTER_PENCE_CX 39.f
#define MONSTER_PENCE_CY 39.f
#define MONSTER_PENCE_SPEED 5.f

#define MONSTER_RUGAL_CX 42.f
#define MONSTER_RUGAL_CY 48.f
#define MONSTER_RUGAL_SPEED 2.f

#define MONSTER_GARUN_CX 48.f
#define MONSTER_GARUN_CY 48.f
#define MONSTER_GARUN_SPEED 2.f
#define MONSTER_GARUN_RADIAN 0.15f

#define MONSTER_DE_CX 42.f
#define MONSTER_DE_CY 45.f
#define MONSTER_DE_SPEED MAP_SCROLL_SPEED * 3.f
#define MONSTER_DE_COOLTIME 100

#define MONSTER_JUMPER_CX 54.f
#define MONSTER_JUMPER_CY 54.f
#define MONSTER_JUMPER_SPEED 5.f
#define MONSTER_JUMPER_HIEGHT 200

#define MONSTER_DUCKER_CX 48.f
#define MONSTER_DUCKER_CY 48.f
#define MONSTER_DUCKER_SPEED 2.f
#define MONSTER_DUCKER_COOLTIME 30

//맵
#define MAPOBJ_GROUND_CX PLAYREGION_X.f
#define MAPOBJ_GROUND_CY 30.f
#define MAPOBJ_GROUND_INIT_X PLAYREGION_X.f + PLAYREGION_X.f/2 -1
#define MAPOBJ_GROUND_INIT_DOWNY 595.f
#define MAPOBJ_GROUND_INIT_UPY 15.f

#define MAPOBJ_OBJECT_CX 30.f
#define MAPOBJ_OBJECT_CY 30.f


//몬스터 탄환 속도
#define MONSTER_BLLT_CX
#define MONSTER_BLLT_CY

//아이템
#define ITEM_CX 54.f
#define ITEM_CY 48.f
#define ITEM_SPEED MAP_SCROLL_SPEED * 3.f

//폭탄
#define BOOM_CX ITEM_CX
#define BOOM_CY ITEM_CY
#define BOOM_SPEED ITEM_SPEED

//UI
#define UI_CX 576.f
#define UI_CY 27.f
#define UI_INIT_X WINCX / 2.f;
#define UI_INIT_Y 635
#define UI_ITEM_SIZE_X  96

//맵
#define MAP_SCROLL_SPEED 0.5f

//이펙트 사이즈
#define EFFECT_PLAYER_DEAD_CX 90.f
#define EFFECT_PLAYER_DEAD_CY 51.f
#define EFFECT_ENEMY_DEAD_CX 45.f
#define EFFECT_ENEMY_DEAD_CY 48.f
#define EFFECT_BOSS_DEAD_CX	135.F
#define EFFECT_BOSS_DEAD_CY 144.F



//이미지 변환 주기
#define IMAGE_SET_TIMING 10
#define EFFECT_SET_TIMING 7
#endif // !__OBJECT_DEFINE_H__
