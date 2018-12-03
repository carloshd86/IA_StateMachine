#include <stdafx.h>
#include "condition.h"
#include "stateMachine.h"

Condition::Condition(const StateMachine& stateMachine) :
	mStateMachine(stateMachine) {}