#ifndef __GLOBALS_H__
#define __GLOBALS_H__

#define RAD2DEG 57.2958f
#define DEG2RAD 0.0174533f

enum eStates {
	S_Idle    = 1,
	S_Pursue  = 2,
	S_Attack  = 3,
	S_Runaway = 4,
	S_Dead    = 5
};

enum eActions {
	A_ChangeImage      = 1,
	A_PursueEnemy      = 2,
	A_AttackEnemy      = 3,
	A_SetTargetPoint   = 4,
	A_RestoreHit       = 5,
	A_CircularMovement = 6,
	A_SetDead          = 7
};

enum eConditions {
	C_CanSeeEnemy        = 1,
	C_CanAttackEnemy     = 2,
	C_CannotAttackEnemy  = 3,
	C_IsDead             = 4,
	C_IsHit              = 5,
	C_ReachedTargetPoint = 6
};

const int MAX_VIEWPORT_WIDTH_HALF  = 512;
const int MAX_VIEWPORT_HEIGHT_HALF = 384;

#endif