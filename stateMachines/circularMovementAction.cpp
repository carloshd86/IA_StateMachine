#include <stdafx.h>
#include "circularMovementAction.h"
#include "globals.h"

CircularMovementAction::CircularMovementAction(const StateMachine& stateMachine, int radius, bool reverse, float speed) :
	Action   (stateMachine),
	mRadius  (radius),
    mReverse (reverse),
	mSpeed   (speed),
    mAngle   (0.f) {}

void CircularMovementAction::start() {
	if (mRadius < 0) mRadius = 0;

	if (mRadius) {
		const USVec2D& entityLoc = mStateMachine.getEntity()->GetLoc();
		USVec2D dir(1, 1);
		dir.NormSafe();
		dir *= mRadius;
		mCircleCenter.mX = entityLoc.mX + dir.mX;
		mCircleCenter.mY = entityLoc.mY + dir.mY;
		mAngle = acosf((entityLoc.mX - mCircleCenter.mX) / mRadius) * RAD2DEG;
	}
}

void CircularMovementAction::update() {
	if (mRadius && mSpeed) {
		GameEntity* entity = mStateMachine.getEntity();
		const USVec2D& entityLoc = mStateMachine.getEntity()->GetLoc();
		float velMultiplier = 1/60.f;
		if (mReverse) velMultiplier *= -1;
		if (mAngle > 360) mAngle -= 360;
		if (mAngle < 0)   mAngle += 360;
		float newX = mRadius * cosf(mAngle * DEG2RAD) + mCircleCenter.mX;
		float newY = mRadius * sinf(mAngle * DEG2RAD) + mCircleCenter.mY;
		entity->SetLoc(USVec3D(newX, newY, 0.f));
		mAngle += velMultiplier * mSpeed;
	}
}

void CircularMovementAction::end() {
}