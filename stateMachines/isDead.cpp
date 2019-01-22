#include <stdafx.h>
#include "isDead.h"

IsDead::IsDead(const StateMachine& stateMachine) :
	Condition(stateMachine) {}

bool IsDead::check() const {
	return mStateMachine.getEntity()->IsDead();
}