#ifndef __IDLE_STATE_H__
#define __IDLE_STATE_H__

#include "state.h"

class IdleState : public State {
public:
	IdleState(const StateMachine& stateMachine);

	void onEnter();
	void update();
	void onExit();
};

#endif
