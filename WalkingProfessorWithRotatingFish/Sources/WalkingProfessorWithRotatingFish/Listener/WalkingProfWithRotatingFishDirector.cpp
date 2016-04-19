#include "Precompiled.h"
#include "WalkingProfWithRotatingFishDirector.h"
#include "../Actor/WalkingToDestinationActor.h"
#include "../Actor/TurningAroundActor.h"
#include "../Actor/RevolvingActor.h"

MyCodes::WalkingProfWithRotatingFishDirector::WalkingProfWithRotatingFishDirector(Ogre::SceneNode* professor, Ogre::SceneNode* fish) :
mProfessorNode(professor), mFishNode(fish), mWalkingActor(nullptr), mTurningAroundActor(nullptr), mRevolvingActor(nullptr), mDestination(Ogre::Vector3(0.0f, 0.0f, 250.0f))
{
	mWalkingActor = new WalkingToDestinationActor(mProfessorNode, mDestination, 100.0f);
	mTurningAroundActor = new TurningAroundActor(mProfessorNode, 180.0f, 60.0f);
	mRevolvingActor = new RevolvingActor(mFishNode, 240.0f, 50.0f);
}

MyCodes::WalkingProfWithRotatingFishDirector::~WalkingProfWithRotatingFishDirector()
{
	if (mWalkingActor)
	{
		delete mWalkingActor;
	}

	if (mTurningAroundActor)
	{
		delete mTurningAroundActor;
	}

	if (mRevolvingActor)
	{
		delete mRevolvingActor;
	}
}

bool MyCodes::WalkingProfWithRotatingFishDirector::frameStarted(const Ogre::FrameEvent& evt)
{
	if (ActorState::Done == mWalkingActor->getState())
	{
		if (ActorState::Done == mTurningAroundActor->getState())
		{
			mWalkingActor->initialize();
			mDestination *= -1;
			mWalkingActor->setDestination(mDestination);

			mTurningAroundActor->initialize();
		}

		else
		{
			mTurningAroundActor->act(evt.timeSinceLastFrame);
		}
	}

	else
	{
		mWalkingActor->act(evt.timeSinceLastFrame);
	}

	mRevolvingActor->act(evt.timeSinceLastFrame);

	return true;
}