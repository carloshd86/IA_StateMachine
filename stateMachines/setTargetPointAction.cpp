#include <stdafx.h>
#include "setTargetPointAction.h"
#include "enemy.h"

SetTargetPointAction::SetTargetPointAction(const StateMachine& stateMachine) :
	Action(stateMachine) {}

void SetTargetPointAction::start() {
	Enemy* enemy = static_cast<Enemy*>(mStateMachine.getEntity());
	if (enemy) {
		// TODO ponerle targetpoint y steering de arrive al enemigo.
	}
}

void SetTargetPointAction::update() {
}

void SetTargetPointAction::end() {
}