#include <stdafx.h>
#include "restoreHitAction.h"
#include "enemy.h"

RestoreHitAction::RestoreHitAction(const StateMachine& stateMachine) :
	Action(stateMachine) {}

void RestoreHitAction::start() {
	Enemy* enemy = static_cast<Enemy*>(mStateMachine.getEntity());
	if (enemy) {
		enemy->SetHit(false);
	}
}

void RestoreHitAction::update() {
}

void RestoreHitAction::end() {
}