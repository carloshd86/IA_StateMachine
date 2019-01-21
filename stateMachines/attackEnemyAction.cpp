#include <stdafx.h>
#include "attackEnemyAction.h"
#include "character.h"
#include "enemy.h"

AttackEnemyAction::AttackEnemyAction(const StateMachine& stateMachine) :
	Action(stateMachine),
    damagePoints(1) {}

void AttackEnemyAction::start() {
	Character* character = static_cast<Character*>(mStateMachine.getEntity());
	if (character) {
		Enemy* enemy = character->GetEnemy();
		if (enemy) {
			enemy->Damage(damagePoints);
		}
	}
}

void AttackEnemyAction::update() {
}

void AttackEnemyAction::end() {
}