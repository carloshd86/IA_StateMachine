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
			float distSqr = (USVec2D(enemy->GetLoc()) - USVec2D(character->GetLoc())).LengthSquared();
			result = !enemy->IsDead() && !enemy->GetHit() && distSqr <= distance * distance;
		}
	}
	return result;
}