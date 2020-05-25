#pragma once
class PatternMgr
{
public:
	PatternMgr();
	~PatternMgr();

private:
	void PawnSpawn();
	void Initialize();

public:
	bool IsVolcano();

	float GetTimer();
	float GetRTime();
	bool GetIsStop();
	bool IsBoss();
	void LoadCheckPoint();
	void SetBossDie(bool _bool);

public:
	void Update();

public:
	static PatternMgr* GetInstance();
	void DestroyInstance()
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

private:
	float m_Timer;
	int m_RaidTime;
	bool m_stop;
	bool m_bBoss;
	float m_fCheckPoint;

private:
	static PatternMgr* m_pInstance;
};

