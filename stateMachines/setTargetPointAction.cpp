#include <stdafx.h>
#include "setTargetPointAction.h"
#include "enemy.h"
#include "steering/arriveSteering.h"

SetTargetPointAction::SetTargetPointAction(const StateMachine& stateMachine) :
	Action(stateMachine) {}

void SetTargetPointAction::start() {
	Enemy* enemy = static_cast<Enemy*>(mStateMachine.getEntity());
	if (enemy) {
		// TODO poner targetpoint random
		enemy->SetTargetPoint(enemy->GetLoc().mX + 100, enemy->GetLoc().mY + 100);
		enemy->SetSteering(new ArriveSteering(*enemy, enemy->GetTargetPoint()));
	}
}

void SetTargetPointAction::update() {
}

void SetTargetPointAction::end() {
}