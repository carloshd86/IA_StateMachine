#ifndef __ACTION_H__
#define __ACTION_H__

#include "stateMachine.h"

class Action {
public:
	Action(const StateMachine& stateMachine);

	virtual void start();
	virtual void update();
	virtual void end();

protected:
	const StateMachine& mStateMachine;
};

#endif