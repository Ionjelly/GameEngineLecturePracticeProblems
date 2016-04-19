#include "Precompiled.h"
#include "ProgramEntry.h"
#include "../Application/WalkingProfWithRotatingFishApp.h"

#if defined __cplusplus 
extern "C" {
#endif

#if OGRE_PLATFORM == OGRE_PLATFORM_WIN32
int _stdcall WinMain(HINSTANCE programInstance, HINSTANCE prevProgramInstance, char* commandLine, int commandShow)
#else
int main(int numberOfCommand, char* commands[])
#endif
{
	MyCodes::Application* application = new MyCodes::WalkingProfWithRotatingFishApp;

	application->initialize();

	application->operate();

	application->finalize();

	delete application;
}
#if defined __cplusplus
}
#endif