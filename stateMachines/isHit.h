#ifndef __IS_HIT_H__
#define __IS_HIT_H__

#include "condition.h"
#include "stateMachine.h"

class IsHit : public Condition {
public:
	IsHit(const StateMachine& stateMachine);

	bool check() const;
};

#endif
