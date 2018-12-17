#ifndef __DEAD_STATE_H__
#define __DEAD_STATE_H__

#include "state.h"

class DeadState : public State {
public:
	DeadState(const StateMachine& stateMachine);

	void onEnter();
	void update();
	void onExit();
};

#endif