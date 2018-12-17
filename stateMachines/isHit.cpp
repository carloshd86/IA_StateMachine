#include <stdafx.h>
#include "isHit.h"
#include "enemy.h"

IsHit::IsHit(const StateMachine& stateMachine) :
	Condition(stateMachine) {}

bool IsHit::check() const {
	bool result = false;

	Enemy* enemy = static_cast<Enemy*>(mStateMachine.getEntity());
	if (enemy) {
		result = enemy->GetHit();
	}
	return result;
}