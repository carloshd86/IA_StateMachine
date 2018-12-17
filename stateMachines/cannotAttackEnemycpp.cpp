#include <stdafx.h>
#include "cannotAttackEnemy.h"
#include "enemy.h"
#include "character.h"

CannotAttackEnemy::CannotAttackEnemy(const StateMachine& stateMachine) :
	Condition(stateMachine),
	distance (0)   {}

bool CannotAttackEnemy::check() const {
	bool result = false;

	Character* character = static_cast<Character*>(mStateMachine.getEntity());
	if (character) {
		Enemy* enemy = character->GetEnemy();
		if (enemy) {
			result = (enemy->GetLoc() - character->GetLoc()).Length() <= distance;
		}
	}
	return result;
}