#ifndef __CAN_SEE_ENEMY_H__
#define __CAN_SEE_ENEMY_H__

#include "condition.h"
#include "stateMachine.h"

class CanSeeEnemy : public Condition {
public:
	CanSeeEnemy(const StateMachine& stateMachine);

	bool check() const;

	float distance;
};

#endif
