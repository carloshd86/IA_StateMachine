#ifndef __IS_DEAD_H__
#define __IS_DEAD_H__

#include "condition.h"
#include "stateMachine.h"

class IsDead : public Condition {
public:
	IsDead(const StateMachine& stateMachine);

	bool check() const;
};

#endif
