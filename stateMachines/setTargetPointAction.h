#ifndef __SET_TARGET_POINT_ACTION_H__
#define __SET_TARGET_POINT_ACTION_H__

#include "action.h"

class Character;

class SetTargetPointAction : public Action {
public:
	SetTargetPointAction(const StateMachine& stateMachine);

	void start();
	void update();
	void end();
};

#endif