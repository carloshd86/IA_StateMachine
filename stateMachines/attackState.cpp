#include <stdafx.h>
#include "attackState.h"

AttackState::AttackState(const StateMachine& stateMachine) :
	State(stateMachine) {}

void AttackState::onEnter() {
	State::onEnter();
}

void AttackState::update() {
	State::update();
}

void AttackState::onExit() {
	State::onExit();
}