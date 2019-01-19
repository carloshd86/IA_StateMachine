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
			float dist = (enemy->GetLoc() - character->GetLoc()).Length();
			result = !enemy->IsDead() && !enemy->GetHit() && dist <= distance;
		}
	}
	return result;
}