#include <stdafx.h>
#include "pursueEnemyAction.h"
#include "steering/pursueSteering.h"
#include "character.h"
#include "enemy.h"

PursueEnemyAction::PursueEnemyAction(const StateMachine& stateMachine) :
	Action(stateMachine) {}

void PursueEnemyAction::start() {
	Character* character = static_cast<Character*>(mStateMachine.getEntity());
	if (character) {
		Enemy* enemy = character->GetEnemy();
		if (enemy) {
			character->ClearSteeringWeights();
			character->AddSteeringWeight(Character::SteeringWeight(new PursueSteering(*character, *enemy), 1.f));
		}
	}
}

void PursueEnemyAction::update() {
}

void PursueEnemyAction::end() {
	Character* character = static_cast<Character*>(mStateMachine.getEntity());
	if (character) {
		Enemy* enemy = character->GetEnemy();
		if (enemy) {
			character->ClearSteeringWeights();
		}
	}
}