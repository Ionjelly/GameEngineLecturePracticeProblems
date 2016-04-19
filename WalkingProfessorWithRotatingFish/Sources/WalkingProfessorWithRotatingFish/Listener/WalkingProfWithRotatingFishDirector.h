#if !defined WALKING_PROFESSOR_WITH_ROTATING_FISH_DIRECTOR_HEADER
#define WALKING_PROFESSOR_WITH_ROTATING_FISH_DIRECTOR_HEADER

namespace MyCodes
{
	class WalkingToDestinationActor;
	class TurningAroundActor;
	class RevolvingActor;

	class WalkingProfWithRotatingFishDirector : public Ogre::FrameListener
	{
	public:
		WalkingProfWithRotatingFishDirector(Ogre::SceneNode* professor, Ogre::SceneNode* fish);
		~WalkingProfWithRotatingFishDirector();

		bool frameStarted(const Ogre::FrameEvent& evt) override;

	private:
		Ogre::SceneNode* mProfessorNode;
		Ogre::SceneNode* mFishNode;
		WalkingToDestinationActor* mWalkingActor;
		TurningAroundActor* mTurningAroundActor;
		RevolvingActor* mRevolvingActor;
		Ogre::Vector3 mDestination;
	};
}

#endif