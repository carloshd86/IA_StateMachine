#ifndef __GLOBALS_H__
#define __GLOBALS_H__

enum eStates {
	S_Idle    = 1,
	S_Pursue  = 2,
	S_Attack  = 3,
	S_Runaway = 4,
	S_Dead    = 5
};

enum eActions {
	A_ChangeImage    = 1,
	A_PursueEnemy    = 2,
	A_AttackEnemy    = 3,
	A_SetTargetPoint = 4,
	A_RestoreHit     = 5
};

enum eConditions {
	C_CanSeeEnemy        = 1,
	C_CanAttackEnemy     = 2,
	C_CannotAttackEnemy  = 3,
	C_IsDead             = 4,
	C_IsHit              = 5,
	C_ReachedTargetPoint = 6
};

#endif