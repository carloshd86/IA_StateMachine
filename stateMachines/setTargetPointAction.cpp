#include <stdafx.h>
#include "setTargetPointAction.h"
#include "steering/arriveSteering.h"
#include "globals.h"

const float SetTargetPointAction::MIN_DISTANCE_NEXT_POINT = 100;

SetTargetPointAction::SetTargetPointAction(const StateMachine& stateMachine) :
	Action(stateMachine) {}

void SetTargetPointAction::start() {
	GameEntity* entity = mStateMachine.getEntity();
	if (entity) {
		USVec2D currentLoc = entity->GetLoc();
		USVec2D nextLoc;
		int attempts = 100;
		do {
			--attempts;
			nextLoc = USVec2D(Rand(-MAX_VIEWPORT_WIDTH_HALF, MAX_VIEWPORT_WIDTH_HALF), Rand(-MAX_VIEWPORT_HEIGHT_HALF, MAX_VIEWPORT_HEIGHT_HALF));
		} while (attempts && currentLoc.DistSqrd(nextLoc) < MIN_DISTANCE_NEXT_POINT * MIN_DISTANCE_NEXT_POINT);
		entity->SetTargetPoint(nextLoc.mX, nextLoc.mY);
		entity->SetSteering(new ArriveSteering(*entity, entity->GetTargetPoint()));
	}
}