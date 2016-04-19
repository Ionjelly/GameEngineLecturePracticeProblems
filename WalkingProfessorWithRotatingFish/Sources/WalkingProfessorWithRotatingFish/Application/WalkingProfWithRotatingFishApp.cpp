#include "Precompiled.h"
#include "WalkingProfWithRotatingFishApp.h"
#include "../Listener/ExitListener.h"
#include "../Listener/WalkingProfWithRotatingFishDirector.h"

MyCodes::WalkingProfWithRotatingFishApp::WalkingProfWithRotatingFishApp()
{
}

MyCodes::WalkingProfWithRotatingFishApp::~WalkingProfWithRotatingFishApp()
{
}

bool MyCodes::WalkingProfWithRotatingFishApp::initialize()
{
	ApplicationUsingOgre3d::initialize();

	loadResources();

	buildScene();

	return true;
}

void MyCodes::WalkingProfWithRotatingFishApp::finalize()
{
	ApplicationUsingOgre3d::finalize();
}

void MyCodes::WalkingProfWithRotatingFishApp::loadResources()
{
	Ogre::ResourceGroupManager::getSingleton().addResourceLocation("resource.zip", "Zip");
	Ogre::ResourceGroupManager::getSingleton().addResourceLocation("fish.zip", "Zip");
	Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();
}

void MyCodes::WalkingProfWithRotatingFishApp::buildScene()
{
	Ogre::Entity* mAxesEntity = mSceneManager->createEntity("Axes", "axes.mesh");
	mSceneManager->getRootSceneNode()->createChildSceneNode("AxesNode", Ogre::Vector3(0, 0, 0))->attachObject(mAxesEntity);

	mSceneManager->getSceneNode("AxesNode")->setScale(5, 5, 5);
	Ogre::Camera* camera = mSceneManager->getCamera("main");
	camera->setPosition(0.0f, 1000.0f, 1000.0f);
	camera->lookAt(0.0f, 0.0f, -10.0f);

	Ogre::Entity* professorEntity = mSceneManager->createEntity("Professor", "DustinBody.mesh");
	Ogre::SceneNode* professorNode = mSceneManager->getRootSceneNode()->createChildSceneNode("Professor");
	professorNode->attachObject(professorEntity);

	Ogre::Entity* fishEntity = mSceneManager->createEntity("Fish", "fish.mesh");
	Ogre::SceneNode* fishNode = professorNode->createChildSceneNode("Fish", Ogre::Vector3(0.0, 0.0f, 0.0f));
	fishNode->attachObject(fishEntity);
	fishNode->setScale(Ogre::Vector3(4.0f, 4.0f, 4.0f));
	fishNode->setInheritOrientation(false);

	mRoot->addFrameListener(new ExitListener(mKeyboard));
	mRoot->addFrameListener(new WalkingProfWithRotatingFishDirector(professorNode, fishNode));
}