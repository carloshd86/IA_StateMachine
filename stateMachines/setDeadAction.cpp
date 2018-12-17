#include <stdafx.h>
#include "setDeadAction.h"
#include "enemy.h"

SetDeadAction::SetDeadAction(const StateMachine& stateMachine) :
	Action(stateMachine) {}

void SetDeadAction::start() {
	Enemy* enemy = static_cast<Enemy*>(mStateMachine.getEntity());
	if (enemy) {
		enemy->SetLinearVelocity(0, 0);
		enemy->SetAngularVelocity(0);
	}
}

void SetDeadAction::update() {
}

void SetDeadAction::end() {
}