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
#include "canAttackEnemy.h"
#include "cannotAttackEnemy.h"
#include "canSeeEnemy.h"
#include "isDead.h"
#include "isHit.h"
#include "reachedTargetPoint.h"

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
		pStateMachine = hDoc.FirstChildElement().Element();
		if (!pStateMachine) {
			fprintf(stderr, "Invalid format for %s", mFilename);
			return;
		}


		int defaultStateIndex = 0;
		pStateMachine->Attribute("default_state_index",&defaultStateIndex);
		TiXmlHandle hStateMachine(pStateMachine);
		TiXmlHandle hStates = hStateMachine.FirstChildElement("states");

		// States
		TiXmlElement* stateElem = hStates.FirstChild().Element();
		int stateIndex = 0;
		for (stateElem; stateElem; stateElem = stateElem->NextSiblingElement()) {
			int stateId = 0;
			stateElem->Attribute("id", &stateId);
			State* state = getStateInstance(stateId);
			if (state) {
				if (stateIndex == defaultStateIndex) {
					mCurrentState = state;
				}

				// Actions
				state->setEnterAction(getActionInstance(stateElem->FirstChildElement("enter_action")));
				state->setExitAction(getActionInstance(stateElem->FirstChildElement("exit_action")));
				state->setStateAction(getActionInstance(stateElem->FirstChildElement("state_action")));

				// Transitions
				TiXmlHandle hTransitions = stateElem->FirstChildElement("transitions");
				TiXmlElement* transitionElem = hTransitions.FirstChild().Element();
				for (transitionElem; transitionElem; transitionElem = transitionElem->NextSiblingElement()) {
					Condition* condition = nullptr;
					int conditionId = 0;
					TiXmlElement* conditionElem = transitionElem->FirstChildElement("condition");
					conditionElem->Attribute("id", &conditionId);
					switch (conditionId) {
						case 1: {
							condition = new CanSeeEnemy(*this);
							float distance = 0;
							conditionElem->Attribute("distance", &distance);
							static_cast<CanSeeEnemy*>(condition)->distance = distance;
							break;
						}
						case 2: {
							condition = new CanAttackEnemy(*this);
							float distance = 0;
							conditionElem->Attribute("distance", &distance);
							static_cast<CanAttackEnemy*>(condition)->distance = distance;
							break;
						}
						case 3: {
							condition = new CannotAttackEnemy(*this);
							float distance = 0;
							conditionElem->Attribute("distance", &distance);
							static_cast<CannotAttackEnemy*>(condition)->distance = distance;
							break;
						}
						case 4: {
							condition = new IsDead(*this);
							break;
						}
						case 5: {
							condition = new IsHit(*this);
							break;
						}
						case 6: {
							condition = new ReachedTargetPoint(*this);
							float distance = 0;
							conditionElem->Attribute("distance", &distance);
							static_cast<ReachedTargetPoint*>(condition)->distance = distance;
							break;
						}
					}
					
					TiXmlElement* targetStateElem = transitionElem->FirstChildElement("target_state");
					int targetStateId = 0;
					targetStateElem->Attribute("id", &targetStateId);
					State* targetState = getStateInstance(targetStateId);

					Action* triggerAction = getActionInstance(transitionElem->FirstChildElement("trigger_action"));

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
	for(Transition* transition : transitions) {
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
			case 1: {
				state = new IdleState(*this);
				break;
			}
			case 2: {
				state = new PursueState(*this);
				break;
			}
			case 3: {
				state = new AttackState(*this);
				break;
			}
			case 4: {
				state = new RunawayState(*this);
				break;
			}
			case 5: {
				state = new DeadState(*this);
				break;
			}
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
	actionElem->Attribute("id", &actionId);
	switch (actionId) {
		case 1: {
			action = new ChangeImageAction(*this);
			int imageIndex = 0;
			actionElem->Attribute("image_index", &imageIndex);
			static_cast<ChangeImageAction*>(action)->imageIndex = imageIndex;
			break;
		}
		case 2: {
			action = new PursueEnemyAction(*this);
			break;
		}
		case 3: {
			action = new AttackEnemyAction(*this);
			int damagePoints = 0;
			actionElem->Attribute("damage_points", &damagePoints);
			static_cast<AttackEnemyAction*>(action)->damagePoints = damagePoints;
			break;
		}
		case 4: {
			action = new SetTargetPointAction(*this);
			break;
		}
		case 5: {
			action = new RestoreHitAction(*this);
			break;
		}
	}

	return action;
}