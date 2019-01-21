#include <stdafx.h>
#include "isDead.h"
#include "enemy.h"

IsDead::IsDead(const StateMachine& stateMachine) :
	Condition(stateMachine) {}

bool IsDead::check() const {
	bool result = false;

	Enemy* enemy = static_cast<Enemy*>(mStateMachine.getEntity());
	if (enemy) {
		result = enemy->IsDead();
	}
	return result;
}