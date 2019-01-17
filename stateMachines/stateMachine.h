#ifndef __STATE_MACHINE_H__
#define __STATE_MACHINE_H__

#include <vector>
#include "gameEntity.h"

class State;
class Action;
class Condition;
class TiXmlElement;

class StateMachine {
public:
	StateMachine(GameEntity* entity, const char* filename);
	~StateMachine();

	void load   ();
	void start  ();
	void update ();

	GameEntity* getEntity() const;

private:
	State*     getStateInstance     (int stateId);
	Action*    getActionInstance    (TiXmlElement* actionElem);
	Condition* getConditionInstance (TiXmlElement* conditionElem);

	const char*           mFilename;
	std::map<int, State*> mStates;
	State*                mCurrentState;
	GameEntity*           mEntity;
};

#endif
