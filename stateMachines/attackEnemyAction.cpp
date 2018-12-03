#include <stdafx.h>
#include "attackEnemyAction.h"
#include "character.h"
#include "enemy.h"

AttackEnemyAction::AttackEnemyAction(const StateMachine& stateMachine) :
	Action(stateMachine) {}

void AttackEnemyAction::start() {
	Character& character = mStateMachine.getCharacter();
	Enemy* enemy = character.GetEnemy();
	if (enemy) {
		// TODO
		//enemy.hit();
	}
}

void AttackEnemyAction::update() {
}

void AttackEnemyAction::end() {
}