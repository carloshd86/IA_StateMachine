#include <stdafx.h>
#include "transition.h"
#include "condition.h"
#include "state.h"
#include "action.h"

Transition::Transition(Condition* condition, State* targetState, Action* triggerAction) :
	mCondition     (condition),
	mTargetState   (targetState),
	mTriggerAction (triggerAction) {}

bool Transition::canTrigger() const {
	bool result = mCondition;

	if (mCondition) {
		result = mCondition->check();
	}

	return result;
}

State* Transition::trigger() {
	if (mTriggerAction) {
		mTriggerAction->start();
	}

	return mTargetState;
}