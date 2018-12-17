#include <stdafx.h>
#include "runawayState.h"

RunawayState::RunawayState(const StateMachine& stateMachine) :
	State(stateMachine) {}

void RunawayState::onEnter() {
	State::onEnter();
}

void RunawayState::update() {
	State::update();
}

void RunawayState::onExit() {
	State::onExit();
}