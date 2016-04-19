#include "Precompiled.h"
#include "WalkingToDestinationActor.h"

MyCodes::WalkingToDestinationActor::WalkingToDestinationActor(Ogre::SceneNode* sceneNode, const Ogre::Vector3& destination, const float walkingSpeedMeterPerSec) :
mSceneNode(sceneNode), mDestination(destination), mWalkingSpeedMeterPerSecond(walkingSpeedMeterPerSec), mState(ActorState::StandBy)
{
}

MyCodes::WalkingToDestinationActor::~WalkingToDestinationActor()
{
}

bool MyCodes::WalkingToDestinationActor::initialize()
{
	mState = ActorState::StandBy;
	return true;
}

void MyCodes::WalkingToDestinationActor::finalize()
{
}

void MyCodes::WalkingToDestinationActor::act(const float elapsedTimeSinceLastFrame)
{
	const Ogre::Vector3 currentPosition = mSceneNode->getPosition();
	Ogre::Vector3 walkingDirection = (mDestination - currentPosition);
	walkingDirection.normalise();

	const Ogre::Vector3 vectorToMoveInThisFrame = walkingDirection * mWalkingSpeedMeterPerSecond * elapsedTimeSinceLastFrame;
	const float distanceToMoveInThisFrame = vectorToMoveInThisFrame.length();
	const float distanceToDestination = (mDestination - currentPosition).length();

	bool isArrived = distanceToMoveInThisFrame >= distanceToDestination;

	if (isArrived)
	{
		mSceneNode->translate(walkingDirection * distanceToDestination);
		mState = ActorState::Done;
	}

	else
	{
		mSceneNode->translate(vectorToMoveInThisFrame);
		mState = ActorState::InAction;
	}
}

MyCodes::ActorState MyCodes::WalkingToDestinationActor::getState() const
{
	return mState;
}

void MyCodes::WalkingToDestinationActor::setDestination(const Ogre::Vector3& destination)
{
	mDestination = destination;
}