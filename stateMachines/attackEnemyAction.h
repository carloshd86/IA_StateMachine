#ifndef __ATTACK_ENEMY_ACTION_H__
#define __ATTACK_ENEMY_ACTION_H__

#include "action.h"

class AttackEnemyAction : public Action {
public:
	AttackEnemyAction(const StateMachine& stateMachine);

	void start();
	void update();
	void end();

	int damagePoints;
};

#endif