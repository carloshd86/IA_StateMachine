#ifndef __CANNOT_ATTACK_ENEMY_H__
#define __CANNOT_ATTACK_ENEMY_H__

#include "condition.h"
#include "stateMachine.h"

class CannotAttackEnemy : public Condition {
public:
	CannotAttackEnemy(const StateMachine& stateMachine);

	bool check() const;

	float distance;
};

#endif
