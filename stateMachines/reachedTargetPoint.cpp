#include <stdafx.h>
#include "reachedTargetPoint.h"

ReachedTargetPoint::ReachedTargetPoint(const StateMachine& stateMachine) :
	Condition(stateMachine),
    distance (0) {}

bool ReachedTargetPoint::check() const {
	bool result = false;

	result = (mStateMachine.getEntity()->GetLoc() - mStateMachine.getEntity()->GetTargetPoint()).Length() <= distance;
	
	return result;
}