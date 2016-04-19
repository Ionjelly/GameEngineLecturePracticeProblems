#if !defined TURNING_AROUND_ACTOR_HEADER
#define TURNING_AROUND_ACTOR_HEADER

#include "Actor.h"

namespace MyCodes
{
	class TurningAroundActor : public Actor
	{
	public:
		TurningAroundActor(Ogre::SceneNode* sceneNode, const float angleLimit, const float angularSpeedDegreePerSec);
		~TurningAroundActor();

		bool initialize() override;
		void finalize() override;
		void act(const float elapsedTimeSinceLastFrame) override;
		ActorState getState() const override;

	private:
		Ogre::SceneNode* mSceneNode;
		float mAccumulatedAngle;
		float mAngularSpeedDegreePerSecond;
		float mAngleLimitation;
		ActorState mState;
	};
}

#endif