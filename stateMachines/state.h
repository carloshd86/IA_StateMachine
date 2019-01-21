#ifndef __STATE_H__
#define __STATE_H__

#include "transition.h"
#include "stateMachine.h"
#include <vector>

class Action;

typedef std::vector<Transition*> Transitions;

class State {
public:
	State(const StateMachine& stateMachine);
	~State();

	virtual void onEnter();
	virtual void update();
	virtual void onExit();

	void               addTransition  (Transition* transition);
	const Transitions& getTransitions ();
	
	void setEnterAction (Action* enterAction);
	void setExitAction  (Action* exitAction);
	void setStateAction (Action* stateAction);

protected:
	Action*     mEnterAction;
	Action*     mExitAction;
	Action*     mStateAction;
	Transitions mTransitions;
	
	const StateMachine& mStateMachine;
};

#endif
