#if !defined WALKING_PROFESSOR_WITH_ROTATING_FISH_APPLICATION_HEADER
#define WALKING_PROFESSOR_WITH_ROTATING_FISH_APPLICATION_HEADER

#include "ApplicationUsingOgre3d.h"

namespace MyCodes
{
	class WalkingProfWithRotatingFishApp : public ApplicationUsingOgre3d
	{
	public:
		WalkingProfWithRotatingFishApp();
		~WalkingProfWithRotatingFishApp();

		bool initialize() override;
		void finalize() override;

	private:
		void loadResources();
		void buildScene();
	};
}

#endif