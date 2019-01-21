#ifndef __TRANSITION_H__
#define __TRANSITION_H__

class Condition;
class State;
class Action;

class Transition {
public:
	Transition(Condition* condition = nullptr, State* targetState = nullptr, Action* triggerAction = nullptr);

	bool   canTrigger() const;
	State* trigger();

private:
	Condition* mCondition;
	State*     mTargetState;
	Action*    mTriggerAction;
};

#endif