#if !defined APPLICATION_USING_OGRE3D_HEADER
#define APPLICATION_USING_OGRE3D_HEADER

#include "Application.h"

namespace MyCodes
{
	class ApplicationUsingOgre3d : public Application
	{
	public:
		ApplicationUsingOgre3d();
		virtual ~ApplicationUsingOgre3d();

		bool initialize() override;
		void finalize() override;
		int operate() override;

	protected:
		Ogre::Root* mRoot;
		Ogre::SceneManager* mSceneManager;
		OIS::InputManager* mInputManager;
		OIS::Keyboard* mKeyboard;

	private:
		void _drawGridPlane();
	};
}

#endif