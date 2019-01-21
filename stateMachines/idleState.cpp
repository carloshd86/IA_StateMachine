#include <stdafx.h>
#include "idleState.h"
#include "gameEntity.h"

IdleState::IdleState(const StateMachine& stateMachine) :
	State(stateMachine) {}

void IdleState::onEnter() {
	State::onEnter();
	GameEntity* entity = mStateMachine.getEntity();
	if (entity) {
		entity->SetLinearVelocity(0.f, 0.f);
		entity->SetAngularVelocity(0.f);
	}
}

void IdleState::update() {
	State::update();
}

void IdleState::onExit() {
	State::onExit();
}