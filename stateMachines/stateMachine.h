#ifndef __STATE_MACHINE_H__
#define __STATE_MACHINE_H__

#include <vector>
#include "character.h"

class State;
class Action;
class TiXmlElement;

class StateMachine {
public:
	StateMachine(Character& character, const char* filename);
	~StateMachine();

	void load   ();
	void start  ();
	void update ();

	Character& getCharacter() const;

private:
	State*  getStateInstance  (int stateId);
	Action* getActionInstance (TiXmlElement* actionElem);

	const char*           mFilename;
	std::map<int, State*> mStates;
	State*                mCurrentState;
	Character&            mCharacter;
};

#endif
