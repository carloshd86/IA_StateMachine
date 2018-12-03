#include <stdafx.h>
#include "state.h"
#include "action.h"

State::State(const StateMachine& stateMachine) :
	mStateMachine (stateMachine),
	mEnterAction  (nullptr),
	mStateAction  (nullptr),
	mExitAction   (nullptr) {}

State::~State() {
	delete mEnterAction;
	delete mStateAction;
	delete mExitAction;

	for (Transition* transition : mTransitions) {
		delete transition;
	}
}

void State::onEnter() {
	if (mEnterAction) {
		mEnterAction->start();
	}
	if (mStateAction) {
		mStateAction->start();
	}
}

void State::update() {
	if (mStateAction) {
		mStateAction->update();
	}
}

void State::onExit() {
	if (mStateAction) {
		mStateAction->end();
	}
	if (mExitAction) {
		mExitAction->start();
	}
}

void State::addTransition(Transition* transition) {
	if (transition) {
		mTransitions.push_back(transition);
	}
}

const Transitions& State::getTransitions() {
	return mTransitions;
}

void State::setEnterAction(Action* enterAction) {
	mEnterAction = enterAction;
}

void State::setExitAction  (Action* exitAction) {
	mExitAction = exitAction;
}

void State::setStateAction (Action* stateAction) {
	mStateAction = stateAction;
}