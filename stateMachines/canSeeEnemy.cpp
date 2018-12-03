#include <stdafx.h>
#include "canSeeEnemy.h"
#include "enemy.h"

CanSeeEnemy::CanSeeEnemy(const StateMachine& stateMachine) :
	Condition(stateMachine) {}

bool CanSeeEnemy::check() const {
	bool result = false;

	Character& character = mStateMachine.getCharacter();
	Enemy* enemy = character.GetEnemy();
	if (enemy) {
		result = (enemy->GetLoc() - character.GetLoc()).Length() <= distance;
	}
	return result;
}