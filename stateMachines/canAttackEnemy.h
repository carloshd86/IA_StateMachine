#ifndef __CAN_ATTACK_ENEMY_H__
#define __CAN_ATTACK_ENEMY_H__

#include "condition.h"
#include "stateMachine.h"

class CanAttackEnemy : public Condition {
public:
	CanAttackEnemy(const StateMachine& stateMachine);

	bool check() const;

	float distance;
};

#endif
