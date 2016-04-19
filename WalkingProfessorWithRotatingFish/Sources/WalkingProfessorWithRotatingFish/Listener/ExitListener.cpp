#include "Precompiled.h"
#include "ExitListener.h"

MyCodes::ExitListener::ExitListener(OIS::Keyboard* keyboard) :
mKeyboard(keyboard)
{
}

MyCodes::ExitListener::~ExitListener()
{
}

bool MyCodes::ExitListener::frameStarted(const Ogre::FrameEvent& evt)
{
	mKeyboard->capture();

	return !mKeyboard->isKeyDown(OIS::KC_ESCAPE);
}