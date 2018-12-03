#include <stdafx.h>
#include "cannotAttackEnemy.h"
#include "enemy.h"

CannotAttackEnemy::CannotAttackEnemy(const StateMachine& stateMachine) :
	Condition(stateMachine)  {}

bool CannotAttackEnemy::check() const {
	bool result = false;

	Character& character = mStateMachine.getCharacter();
	Enemy* enemy = character.GetEnemy();
	if (enemy) {
		result = (enemy->GetLoc() - character.GetLoc()).Length() <= distance;
	}

	return result;
}