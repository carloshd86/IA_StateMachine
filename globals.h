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

constexpr const char* STATES_NODE_NAME         = "states";
constexpr const char* ENTER_ACTION_NODE_NAME   = "enter_action";
constexpr const char* STATE_ACTION_NODE_NAME   = "state_action";
constexpr const char* EXIT_ACTION_NODE_NAME    = "exit_action";
constexpr const char* TRIGGER_ACTION_NODE_NAME = "trigger_action";
constexpr const char* TRANSITIONS_NODE_NAME    = "transitions";
constexpr const char* TRANSITION_NODE_NAME     = "transition";
constexpr const char* CONDITION_NODE_NAME      = "condition";
constexpr const char* TARGET_STATE_NODE_NAME   = "target_state";

constexpr const char* ID_ATTR                  = "id";
constexpr const char* NAME_ATTR                = "name";
constexpr const char* IMAGE_INDEX_ATTR         = "image_index";
constexpr const char* RADIUS_ATTR              = "radius";
constexpr const char* REVERSE_ATTR             = "reverse";
constexpr const char* SPEED_ATTR               = "speed";
constexpr const char* DISTANCE_ATTR            = "distance";
constexpr const char* MIN_DISTANCE_ATTR        = "min_distance";
constexpr const char* DEFAULT_STATE_INDEX_ATTR = "default_state_index";
constexpr const char* DAMAGE_POINTS_ATTR       = "damage_points";

#endif