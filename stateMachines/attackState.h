#ifndef __ATTACK_STATE_H__
#define __ATTACK_STATE_H__

#include "state.h"

class AttackState : public State {
public:
	AttackState(const StateMachine& stateMachine);

	void onEnter();
	void update();
	void onExit();
};

#endif