#include <stdafx.h>
#include "pursueState.h"

PursueState::PursueState(const StateMachine& stateMachine) :
	State(stateMachine) {}

void PursueState::onEnter() {
	State::onEnter();
}

void PursueState::update() {
	State::update();
}

void PursueState::onExit() {
	State::onExit();
}