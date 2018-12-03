#include <stdafx.h>
#include "idleState.h"

IdleState::IdleState(const StateMachine& stateMachine) :
	State(stateMachine) {}

void IdleState::onEnter() {
	State::onEnter();
	Character& character = mStateMachine.getCharacter();
	character.SetLinearVelocity(0.f, 0.f);
	character.SetAngularVelocity(0.f);
}

void IdleState::update() {
	State::update();
}

void IdleState::onExit() {
	State::onExit();
}