#include <stdafx.h>
#include "changeImageAction.h"

ChangeImageAction::ChangeImageAction(const StateMachine& stateMachine) :
	Action     (stateMachine),
	imageIndex (0) {}

void ChangeImageAction::start() {
	mStateMachine.getCharacter().SetImage(imageIndex);
}