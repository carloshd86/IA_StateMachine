#ifndef __CONDITION_H__
#define __CONDITION_H__

class StateMachine;

class Condition {
public:
	Condition(const StateMachine& stateMachine);

	virtual bool check() const =0;

protected:
	const StateMachine& mStateMachine;
};

#endif
