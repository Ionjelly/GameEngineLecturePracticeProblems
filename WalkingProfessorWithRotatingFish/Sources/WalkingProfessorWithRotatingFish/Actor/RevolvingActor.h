#if !defined REVOLVING_ACTOR_HEADER
#define REVOLVING_ACTOR_HEADER

#include "Actor.h"

namespace MyCodes
{
	class RevolvingActor : public Actor
	{
	public:
		RevolvingActor(Ogre::SceneNode* sceneNode, const float angularSpeedDegreePerSec, const float radius = 1.0f);
		~RevolvingActor();

		bool initialize() override;
		void finalize() override;
		void act(const float elapsedTimeSinceLastFrame) override;
		ActorState getState() const override;

	private:
		Ogre::SceneNode* mSceneNode;
		float mRadius;
		float mAngularSpeedDegreePerSecond;
		float mAccumulatedAngle;
		ActorState mState;
	};
}

#endif