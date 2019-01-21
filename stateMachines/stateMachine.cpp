#include <stdafx.h>
#include <tinyxml.h>
#include "stateMachine.h"
#include "state.h"
#include "idleState.h"
#include "pursueState.h"
#include "attackState.h"
#include "deadState.h"
#include "runawayState.h"
#include "changeImageAction.h"
#include "pursueEnemyAction.h"
#include "attackEnemyAction.h"
#include "setTargetPointAction.h"
#include "restoreHitAction.h"
#include "circularMovementAction.h"
#include "setDeadAction.h"
#include "canAttackEnemy.h"
#include "cannotAttackEnemy.h"
#include "canSeeEnemy.h"
#include "isDead.h"
#include "isHit.h"
#include "reachedTargetPoint.h"
#include "globals.h"

StateMachine::StateMachine(GameEntity* entity, const char* filename) :
	mEntity       (entity),
    mFilename     (filename),
	mCurrentState (nullptr) {}

StateMachine::~StateMachine() {
	for (auto& state : mStates) {
		delete state.second;
	}
	mCurrentState = nullptr;
}

void StateMachine::load() {
	if (mFilename) {
		TiXmlDocument doc(mFilename);
		if (!doc.LoadFile()) {
			fprintf(stderr, "Couldn't read state machine config from %s", mFilename);
			return;
		}

		TiXmlHandle hDoc(&doc);

		TiXmlElement* pStateMachine;
		pStateMachine = hDoc.FirstChildElement().ToElement();
		if (!pStateMachine) {
			fprintf(stderr, "Invalid format for %s", mFilename);
			return;
		}


		int defaultStateIndex = 0;
		pStateMachine->Attribute(DEFAULT_STATE_INDEX_ATTR,&defaultStateIndex);
		TiXmlHandle hStateMachine(pStateMachine);
		TiXmlHandle hStates = hStateMachine.FirstChildElement(STATES_NODE_NAME);

		// States
		TiXmlElement* stateElem = hStates.FirstChild().ToElement();
		int stateIndex = 0;
		for (stateElem; stateElem; stateElem = stateElem->NextSiblingElement()) {
			int stateId = 0;
			stateElem->Attribute(ID_ATTR, &stateId);
			State* state = getStateInstance(stateId);
			if (state) {
				if (stateIndex == defaultStateIndex) {
					mCurrentState = state;
				}

				// Actions
				state->setEnterAction(getActionInstance(stateElem->FirstChildElement(ENTER_ACTION_NODE_NAME)));
				state->setExitAction(getActionInstance(stateElem->FirstChildElement(EXIT_ACTION_NODE_NAME)));
				state->setStateAction(getActionInstance(stateElem->FirstChildElement(STATE_ACTION_NODE_NAME)));

				// Transitions
				TiXmlHandle hTransitions = stateElem->FirstChildElement(TRANSITIONS_NODE_NAME);
				TiXmlElement* transitionElem = hTransitions.FirstChild().ToElement();
				for (transitionElem; transitionElem; transitionElem = transitionElem->NextSiblingElement()) {
					Condition* condition = getConditionInstance(transitionElem->FirstChildElement(CONDITION_NODE_NAME));
					
					TiXmlElement* targetStateElem = transitionElem->FirstChildElement(TARGET_STATE_NODE_NAME);
					int targetStateId = 0;
					targetStateElem->Attribute(ID_ATTR, &targetStateId);
					State* targetState = getStateInstance(targetStateId);

					Action* triggerAction = getActionInstance(transitionElem->FirstChildElement(TRIGGER_ACTION_NODE_NAME));

					state->addTransition(new Transition(condition, targetState, triggerAction));
				}
			}

			++stateIndex;
		}
	}
}

void StateMachine::start() {
	if (mCurrentState) mCurrentState->onEnter();
}

void StateMachine::update() {
	mCurrentState->update();
	const Transitions& transitions = mCurrentState->getTransitions();
	for (Transition* transition : transitions) {
		if (transition->canTrigger()) {
			mCurrentState->onExit();
			State* nextState = transition->trigger();
			nextState->onEnter();
			mCurrentState = nextState;
			return;
		}
	}
}

GameEntity* StateMachine::getEntity() const {
	return mEntity;
}

State* StateMachine::getStateInstance(int stateId) {
	State* state = nullptr;

	if (mStates.find(stateId) != mStates.end()) {
		state = mStates[stateId];
	}
	else {
		switch (stateId) {
			case S_Idle:    { state = new IdleState(*this);    break; }
			case S_Pursue:  { state = new PursueState(*this);  break; }
			case S_Attack:  { state = new AttackState(*this);  break; }
			case S_Runaway: { state = new RunawayState(*this); break; }
			case S_Dead:    { state = new DeadState(*this);    break;     }
		}
		if (state) {
			mStates[stateId] = state;
		}
	}

	return state;
}

Action* StateMachine::getActionInstance(TiXmlElement* actionElem) {
	Action* action = nullptr;
	int actionId = 0;
	actionElem->Attribute(ID_ATTR, &actionId);
	switch (actionId) {
		case A_ChangeImage: {
			action = new ChangeImageAction(*this);
			int imageIndex = 0;
			actionElem->Attribute(IMAGE_INDEX_ATTR, &imageIndex);
			static_cast<ChangeImageAction*>(action)->imageIndex = imageIndex;
			break;
		}
		case A_PursueEnemy: {
			action = new PursueEnemyAction(*this);
			break;
		}
		case A_AttackEnemy: {
			action = new AttackEnemyAction(*this);
			int damagePoints = 0;
			actionElem->Attribute(DAMAGE_POINTS_ATTR, &damagePoints);
			static_cast<AttackEnemyAction*>(action)->damagePoints = damagePoints;
			break;
		}
		case A_SetTargetPoint: {
			action = new SetTargetPointAction(*this);
			break;
		}
		case A_RestoreHit: {
			action = new RestoreHitAction(*this);
			break;
		}
		case A_CircularMovement: {
			int radius = 0;
			actionElem->Attribute(RADIUS_ATTR, &radius);
			if (!&radius) radius = 0;

			int iReverse = 0;
			actionElem->Attribute(REVERSE_ATTR, &iReverse);
			bool reverse = false;
			if (!&iReverse) reverse = false;
			else reverse = iReverse;

			float speed = 0.f;
			actionElem->Attribute(SPEED_ATTR, &speed);
			if (!&speed) speed = 0.f;

			action = new CircularMovementAction(*this, radius, reverse, speed);
			break;
		}
		case A_SetDead: {
			action = new SetDeadAction(*this);
			break;
		}
	}

	return action;
}

Condition* StateMachine::getConditionInstance(TiXmlElement* conditionElem) {
	Condition* condition = nullptr;
	int conditionId = 0;
	conditionElem->Attribute(ID_ATTR, &conditionId);
	switch (conditionId) {
		case C_CanSeeEnemy: {
			condition = new CanSeeEnemy(*this);
			float distance = 0;
			conditionElem->Attribute(DISTANCE_ATTR, &distance);
			static_cast<CanSeeEnemy*>(condition)->distance = distance;
			break;
		}
		case C_CanAttackEnemy: {
			condition = new CanAttackEnemy(*this);
			float distance = 0;
			conditionElem->Attribute(DISTANCE_ATTR, &distance);
			static_cast<CanAttackEnemy*>(condition)->distance = distance;
			break;
		}
		case C_CannotAttackEnemy: {
			condition = new CannotAttackEnemy(*this);
			float distance = 0;
			conditionElem->Attribute(DISTANCE_ATTR, &distance);
			static_cast<CannotAttackEnemy*>(condition)->distance = distance;
			break;
		}
		case C_IsDead: {
			condition = new IsDead(*this);
			break;
		}
		case C_IsHit: {
			condition = new IsHit(*this);
			break;
		}
		case C_ReachedTargetPoint: {
			condition = new ReachedTargetPoint(*this);
			float distance = 0;
			conditionElem->Attribute(DISTANCE_ATTR, &distance);
			static_cast<ReachedTargetPoint*>(condition)->distance = distance;
			break;
		}
	}

	return condition;
}