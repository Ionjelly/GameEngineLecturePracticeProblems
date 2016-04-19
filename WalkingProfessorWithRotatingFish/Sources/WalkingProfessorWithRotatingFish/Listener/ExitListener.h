#if !defined EXIT_LISTENER_HEADER
#define EXIT_LISTENER_HEADER

namespace MyCodes
{
	class ExitListener : public Ogre::FrameListener
	{
	public:
		ExitListener(OIS::Keyboard* keyboard);
		~ExitListener();

		bool frameStarted(const Ogre::FrameEvent& evt) override;

	private:
		OIS::Keyboard* mKeyboard;
	};
}

#endif