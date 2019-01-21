#include <stdafx.h>
#include "setTargetPointAction.h"
#include "enemy.h"
#include "steering/arriveSteering.h"
#include "globals.h"

const float SetTargetPointAction::MIN_DISTANCE_NEXT_POINT = 100;

SetTargetPointAction::SetTargetPointAction(const StateMachine& stateMachine) :
	Action(stateMachine) {}

void SetTargetPointAction::start() {
	Enemy* enemy = static_cast<Enemy*>(mStateMachine.getEntity());
	if (enemy) {
		USVec2D currentLoc = enemy->GetLoc();
		USVec2D nextLoc;
		do {
			nextLoc = USVec2D(Rand(-MAX_VIEWPORT_WIDTH_HALF, MAX_VIEWPORT_WIDTH_HALF), Rand(-MAX_VIEWPORT_HEIGHT_HALF, MAX_VIEWPORT_HEIGHT_HALF));
		} while (currentLoc.DistSqrd(nextLoc) < MIN_DISTANCE_NEXT_POINT * MIN_DISTANCE_NEXT_POINT);
		enemy->SetTargetPoint(nextLoc.mX, nextLoc.mY);
		enemy->SetSteering(new ArriveSteering(*enemy, enemy->GetTargetPoint()));
	}
}

void SetTargetPointAction::update() {
}

void SetTargetPointAction::end() {
}