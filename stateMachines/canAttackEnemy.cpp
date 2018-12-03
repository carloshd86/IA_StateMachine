#include <stdafx.h>
#include "canAttackEnemy.h"
#include "enemy.h"

CanAttackEnemy::CanAttackEnemy(const StateMachine& stateMachine) :
	Condition(stateMachine) {}

bool CanAttackEnemy::check() const {
	bool result = false;

	Character& character = mStateMachine.getCharacter();
	Enemy* enemy = character.GetEnemy();
	if (enemy) {
		result = (enemy->GetLoc() - character.GetLoc()).Length() <= distance;
	}

	return result;
}