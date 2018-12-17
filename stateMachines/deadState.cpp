#include <stdafx.h>
#include "deadState.h"

DeadState::DeadState(const StateMachine& stateMachine) :
	State(stateMachine) {}

void DeadState::onEnter() {
	State::onEnter();
}

void DeadState::update() {
	State::update();
}

void DeadState::onExit() {
	State::onExit();
}