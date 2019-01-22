#ifndef __CHARACTER_H__
#define __CHARACTER_H__

#include <gameEntity.h>
#include "steering/iSteering.h"
#include "steering/iAlignSteering.h"
#include "pathPoints.h"
#include "obstacles.h"

class StateMachine;
class Enemy;

class Character: public GameEntity
{
public:
    DECL_LUA_FACTORY(Character)
protected:
	virtual void OnStart();
	virtual void OnStop();
	virtual void OnUpdate(float step);

public:
	struct SteeringWeight {
		SteeringWeight(ISteering* _steering, float _weight) : steering(_steering), weight(_weight) {};

		ISteering* steering;
		float      weight;
	};

	virtual void DrawDebug();

	Character();
	~Character();
	
	void SetLinearVelocity(float x, float y) { mLinearVelocity.mX = x; mLinearVelocity.mY = y;}
	void SetAngularVelocity(float angle) { mAngularVelocity = angle;}
	void SetEnemy(Enemy& enemy);
	Enemy* GetEnemy();
	
	USVec2D GetLinearVelocity() const { return mLinearVelocity;}
	float GetAngularVelocity() const { return mAngularVelocity;}

	const Params& GetParams() const { return mParams; }
	const PathPoints& GetPathPoints() const { return mPathPoints; }
	const Obstacles& GetObstacles() const { return mObstacles; }

	void ClearSteeringWeights();
	void AddSteeringWeight(SteeringWeight& steeringWeight);

	bool IsDead() const;

	USVec2D GetTargetPoint () const;
	void    SetTargetPoint (float x, float y);
	void    SetSteering    (ISteering* steering);

private:

	USVec2D mLinearVelocity;
	float mAngularVelocity;
	
	Params      mParams;
	PathPoints  mPathPoints;
	Obstacles   mObstacles;
	Enemy* mEnemy;

	std::vector<SteeringWeight> mSteeringWeights;
	IAlignSteering*             mAlignSteering;
	StateMachine*               mStateMachine;

	USVec2D mTargetPoint;

	void AdjustAccelerationModule(USVec2D& acceleration);

	
	// Lua configuration
public:
	virtual void RegisterLuaFuncs(MOAILuaState& state);
private:
	static int _setLinearVel(lua_State* L);
	static int _setAngularVel(lua_State* L);
	static int _setEnemy(lua_State* L);
};

#endif