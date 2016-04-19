#if !defined WALKING_TO_DESTINATION_ACTOR_HEADER
#define WALKING_TO_DESTINATION_ACTOR_HEADER

#include "Actor.h"

namespace MyCodes
{
	class WalkingToDestinationActor : public Actor
	{
	public:
		WalkingToDestinationActor(Ogre::SceneNode* sceneNode, const Ogre::Vector3& destination, const float walkingSpeedMeterPerSec);
		~WalkingToDestinationActor();

		bool initialize() override;
		void finalize() override;
		void act(const float elapsedTimeSinceLastFrame) override;
		ActorState getState() const override;

		void setDestination(const Ogre::Vector3& destination);

	private:
		Ogre::SceneNode* mSceneNode;
		Ogre::Vector3 mDestination;
		float mWalkingSpeedMeterPerSecond;
		ActorState mState;
	};
}

#endif