#ifndef __CIRCULAR_MOVEMENT_ACTION_H__
#define __CIRCULAR_MOVEMENT_ACTION_H__

#include "action.h"

class CircularMovementAction : public Action {
public:
	CircularMovementAction(const StateMachine& stateMachine, int radius = 0, bool reverse = false, float speed = 0.f);

	void start();
	void update();
	void end();

private:
	USVec2D mCircleCenter;
	int   mRadius;
	bool  mReverse;
	float mSpeed;
	float mAngle;
};

#endif