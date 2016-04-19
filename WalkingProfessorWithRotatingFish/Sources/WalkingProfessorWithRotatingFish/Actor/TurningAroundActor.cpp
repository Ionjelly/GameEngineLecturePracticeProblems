#include "Precompiled.h"
#include "TurningAroundActor.h"

MyCodes::TurningAroundActor::TurningAroundActor(Ogre::SceneNode* sceneNode, const float angleLimit, const float angularSpeedDegreePerSec) :
mSceneNode(sceneNode), mAccumulatedAngle(0), mAngularSpeedDegreePerSecond(angularSpeedDegreePerSec), mAngleLimitation(angleLimit), mState(ActorState::StandBy)
{
}

MyCodes::TurningAroundActor::~TurningAroundActor()
{
}

bool MyCodes::TurningAroundActor::initialize()
{
	mState = ActorState::StandBy;
	mAccumulatedAngle = 0;
	return true;
}

void MyCodes::TurningAroundActor::finalize()
{
}

void MyCodes::TurningAroundActor::act(const float elapsedTimeSinceLastFrame)
{
	const float AngleHaveToRotateInThisFrame = mAngularSpeedDegreePerSecond * elapsedTimeSinceLastFrame;
	mAccumulatedAngle += AngleHaveToRotateInThisFrame;

	const bool isReachedAngleLimitation = mAccumulatedAngle >= mAngleLimitation;

	if (isReachedAngleLimitation)
	{
		const float exceededAngle = mAccumulatedAngle - mAngleLimitation;
		mSceneNode->yaw(Ogre::Degree(AngleHaveToRotateInThisFrame - exceededAngle));
		mState = ActorState::Done;
	}

	else
	{
		mSceneNode->yaw(Ogre::Degree(AngleHaveToRotateInThisFrame));
		mState = ActorState::InAction;
	}
}

MyCodes::ActorState MyCodes::TurningAroundActor::getState() const
{
	return mState;
}