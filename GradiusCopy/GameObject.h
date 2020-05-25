#ifndef __GAMEOBJECT_H__
#define __GAMEOBJECT_H__

class CTexture;

class CGameObject {
//¸â¹ö º¯¼ö
protected:
	INFO	m_tInfo;
	RECT	m_tRect;
	float	m_fSpeed;
	float	m_fAngle;
	bool	m_bIsDead;
	int		m_iHP;
	int		m_iDamage;

//»ý¼ºÀÚ ¹× ¼Ò¸êÀÚ
public:
	explicit CGameObject();
	virtual ~CGameObject();

//¸â¹ö ÇÔ¼ö
public:
	const INFO& GetInfo() const;
	const RECT& GetRect() const;
	const int GetDamage() const;
	void SetPos(float _x, float _y);
	void SetDead(bool _bIsDead);
	void SetAngle(float _fAngle);
	void SetDamage(int i);

protected:
	void UpdateRect();

protected:
	virtual void Release() = 0;
public:
	virtual void Initialize() = 0;
	virtual int Update() = 0;
	virtual void Render(HDC _hdc) = 0;

};
#endif // !__GAMEOBJECT_H__


