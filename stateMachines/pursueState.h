#ifndef __PURSUE_STATE_H__
#define __PURSUE_STATE_H__

#include "state.h"

class PursueState : public State {
public:
	PursueState(const StateMachine& stateMachine);

	void onEnter();
	void update();
	void onExit();
};

#endif