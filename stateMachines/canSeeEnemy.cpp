#include <stdafx.h>
#include "canSeeEnemy.h"
#include "character.h"
#include "enemy.h"

CanSeeEnemy::CanSeeEnemy(const StateMachine& stateMachine) :
	Condition(stateMachine),
	distance (0)  {}

bool CanSeeEnemy::check() const {
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