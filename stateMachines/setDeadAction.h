#ifndef __SET_DEAD_ACTION_H__
#define __SET_DEAD_ACTION_H__

#include "action.h"

class SetDeadAction : public Action {
public:
	SetDeadAction(const StateMachine& stateMachine);

	void start();
	void update();
	void end();
};

#endif