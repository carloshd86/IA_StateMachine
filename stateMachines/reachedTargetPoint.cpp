#include <stdafx.h>
#include "reachedTargetPoint.h"
#include "enemy.h"

ReachedTargetPoint::ReachedTargetPoint(const StateMachine& stateMachine) :
	Condition(stateMachine),
    distance (0) {}

bool ReachedTargetPoint::check() const {
	bool result = false;

	Enemy* enemy = static_cast<Enemy*>(mStateMachine.getEntity());
	if (enemy) {
		result = (enemy->GetLoc() - enemy->GetTargetPoint()).Length() <= distance;
	}
	return result;
}