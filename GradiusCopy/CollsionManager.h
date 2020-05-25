#ifndef __COLLISION_MANAGER_H__
#define __COLLISION_MANAGER_H__

typedef list<CGameObject*> OBJLIST;

class CCollsionMgr{
public:
	CCollsionMgr();
	~CCollsionMgr();

public:
	static void CollisionRect( CGameObject* dstObj,  CGameObject* srcObj);
	static void CollisionRectEX( CGameObject* dstObj,  CGameObject* srcObj);
	static void CollisionSphere(const OBJLIST& dstLst, const OBJLIST& srcLst);

private:
	static bool CheckRect(const CGameObject* pDest, const CGameObject* pSource, float* pMoveX, float* pMoveY);
	static bool CheckSphere(const CGameObject* pDest, const CGameObject* pSource);
};

#endif // !__COLLISION_MANAGER_H__

