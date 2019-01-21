#ifndef __RESTORE_HIT_ACTION_H__
#define __RESTORE_HIT_ACTION_H__

#include "action.h"

class RestoreHitAction : public Action {
public:
	RestoreHitAction(const StateMachine& stateMachine);

	void start();
	void update();
	void end();
};

#endif