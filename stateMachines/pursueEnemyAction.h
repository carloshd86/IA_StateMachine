#ifndef __PURSUE_ENEMY_ACTION_H__
#define __PURSUE_ENEMY_ACTION_H__

#include "action.h"

class Character;

class PursueEnemyAction : public Action {
public:
	PursueEnemyAction(const StateMachine& stateMachine);
	
	void start();
	void update();
	void end();
};

#endif