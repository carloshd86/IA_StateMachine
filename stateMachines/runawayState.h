#ifndef __RUNAWAY_STATE_H__
#define __RUNAWAY_STATE_H__

#include "state.h"

class RunawayState : public State {
public:
	RunawayState(const StateMachine& stateMachine);

	void onEnter();
	void update();
	void onExit();
};

#endif