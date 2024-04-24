#pragma once
#include "Enemy/Boss_Slime/State/FafroState.h"
#include "Enemy/Boss_Slime/Boss_Fafrotskies.h"

//状態遷移を管理する
class BossStateManager : public BossState
{
public:
	BossState* pBossState_;
	BossState* prevState_;

	BossSpawn* pSpawn_;
	BossMove* pMove_;
	BossWait* pWait_;
	BossDamaged* pDameged_;
	BossAttack* pAttack_;
	BossDeath* pDeath_;
	bool canChange_;

	BossStateManager();
	~BossStateManager();

	//更新
	virtual void Update()
};

