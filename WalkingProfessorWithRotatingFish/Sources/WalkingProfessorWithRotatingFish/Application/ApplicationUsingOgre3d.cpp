#include "Precompiled.h"
#include "ApplicationUsingOgre3d.h"


MyCodes::ApplicationUsingOgre3d::ApplicationUsingOgre3d() :
mRoot(nullptr), mSceneManager(nullptr)
{
}

MyCodes::ApplicationUsingOgre3d::~ApplicationUsingOgre3d()
{
}

bool MyCodes::ApplicationUsingOgre3d::initialize()
{
#if defined _DEBUG
	mRoot = new Ogre::Root("plugins_d.cfg", "ogre.cfg", "ogre.log");
#else
	mRoot = new Ogre::Root("plugins.cfg", "ogre.cfg", "ogre.log");
#endif

	if (false == mRoot->restoreConfig())
	{
		if (false == mRoot->showConfigDialog())
		{
			return false;
		}
	}

	Ogre::RenderWindow* window = mRoot->initialise(true, "Program using Ogre3d");

	size_t windowHandle = 0;
	std::ostringstream windowHandleString;
	OIS::ParamList paramList;
	
	window->getCustomAttribute("WINDOW", &windowHandle);
	windowHandleString << windowHandle;
	paramList.insert(std::make_pair(std::string("WINDOW"), windowHandleString.str()));

	mInputManager = OIS::InputManager::createInputSystem(paramList);
	mKeyboard = static_cast<OIS::Keyboard*>(mInputManager->createInputObject(OIS::OISKeyboard, false));

	mSceneManager = mRoot->createSceneManager(Ogre::ST_GENERIC, "main");
	Ogre::Camera* camera = mSceneManager->createCamera("main");
	camera->setPosition(0.0f, 0.0f, 500.0f);
	camera->lookAt(0.0f, 0.0f, 0.0f);
	camera->setNearClipDistance(5.0f);

	Ogre::Viewport* viewport = window->addViewport(camera);
	viewport->setBackgroundColour(Ogre::ColourValue(0.0f, 0.0f, 0.5f));
	camera->setAspectRatio(viewport->getActualWidth() / Ogre::Real(viewport->getActualHeight()));

	mSceneManager->setAmbientLight(Ogre::ColourValue(1.0f, 1.0f, 1.0f));

	_drawGridPlane();

	return true;
}

void MyCodes::ApplicationUsingOgre3d::finalize()
{
	mInputManager->destroyInputObject(mKeyboard);
	OIS::InputManager::destroyInputSystem(mInputManager);

	if (nullptr != mRoot)
		delete mRoot;
}

int MyCodes::ApplicationUsingOgre3d::operate()
{
	mRoot->startRendering();

	return 0;
}

void MyCodes::ApplicationUsingOgre3d::_drawGridPlane(void)
{
	Ogre::ManualObject* gridPlane = mSceneManager->createManualObject("GridPlane");
	Ogre::SceneNode* gridPlaneNode = mSceneManager->getRootSceneNode()->createChildSceneNode("GridPlaneNode");

	Ogre::MaterialPtr gridPlaneMaterial = Ogre::MaterialManager::getSingleton().create("GridPlanMaterial", "General");
	gridPlaneMaterial->setReceiveShadows(false);
	gridPlaneMaterial->getTechnique(0)->setLightingEnabled(true);
	gridPlaneMaterial->getTechnique(0)->getPass(0)->setDiffuse(1, 1, 1, 0);
	gridPlaneMaterial->getTechnique(0)->getPass(0)->setAmbient(1, 1, 1);
	gridPlaneMaterial->getTechnique(0)->getPass(0)->setSelfIllumination(1, 1, 1);

	gridPlane->begin("GridPlaneMaterial", Ogre::RenderOperation::OT_LINE_LIST);
	for (int i = 0; i<21; i++)
	{
		gridPlane->position(-500.0f, 0.0f, 500.0f - i * 50);
		gridPlane->position(500.0f, 0.0f, 500.0f - i * 50);

		gridPlane->position(-500.f + i * 50, 0.f, 500.0f);
		gridPlane->position(-500.f + i * 50, 0.f, -500.f);
	}

	gridPlane->end();

	gridPlaneNode->attachObject(gridPlane);
}