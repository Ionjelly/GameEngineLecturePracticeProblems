#include "Precompiled.h"
#include "RevolvingActor.h"

MyCodes::RevolvingActor::RevolvingActor(Ogre::SceneNode* sceneNode, const float angularSpeedDegreePerSec, const float radius) :
mSceneNode(sceneNode), mRadius(radius), mAngularSpeedDegreePerSecond(angularSpeedDegreePerSec), mAccumulatedAngle(0), mState(ActorState::StandBy)
{
}

MyCodes::RevolvingActor::~RevolvingActor()
{
}

bool MyCodes::RevolvingActor::initialize()
{
	return true;
}

void MyCodes::RevolvingActor::finalize()
{
}

void MyCodes::RevolvingActor::act(const float elapsedTimeSinceLastFrame) 
{
	const float degreeHaveToRevolveInThisFrame = mAngularSpeedDegreePerSecond * elapsedTimeSinceLastFrame;
	mAccumulatedAngle += degreeHaveToRevolveInThisFrame;

	if (mAccumulatedAngle >= 360.0f)
	{
		mAccumulatedAngle -= 360.0f;
	}

	const float PI = 3.141592f;
	const float degreeToRadian = PI / 180.0f;

	const float revolvedX = cos(mAccumulatedAngle * degreeToRadian) * mRadius;
	const float revolvedZ = sin(mAccumulatedAngle * degreeToRadian) * mRadius;
	const Ogre::Vector3 revolvedPosition(revolvedX, 0.0f, revolvedZ);

	mSceneNode->setPosition(revolvedPosition);

	mState = ActorState::InAction;
}

MyCodes::ActorState MyCodes::RevolvingActor::getState() const
{
	return mState;
}