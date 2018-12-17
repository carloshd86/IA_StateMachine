#ifndef __REACHED_TARGET_POINT_H__
#define __REACHED_TARGET_POINT_H__

#include "condition.h"
#include "stateMachine.h"

class ReachedTargetPoint : public Condition {
public:
	ReachedTargetPoint(const StateMachine& stateMachine);

	bool check() const;

	float distance;
};

#endif
