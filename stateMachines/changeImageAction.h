#ifndef __CHANGE_IMAGE_ACTION_H__
#define __CHANGE_IMAGE_ACTION_H__

#include "action.h"

class ChangeImageAction : public Action {
public:
	ChangeImageAction(const StateMachine& stateMachine);

	void start();

	size_t imageIndex;
};

#endif