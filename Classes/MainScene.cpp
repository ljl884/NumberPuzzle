#include "MainScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "StaticNumber.h"
#include "MoveableNumber.h"
#include "Table.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* MainScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = MainScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MainScene::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto rootNode = CSLoader::createNode("MainScene.csb");

    addChild(rootNode);
	this->setTouchEnabled(true);

	this->levelManager = new LevelManager(this);
	levelManager->runLevel(0);

	Menu * menu = Menu::create();
	MenuItemImage* restItem = MenuItemImage::create(
		"reset_level_default@2x.png", "reset_level_selected@2x.png",
		CC_CALLBACK_1(MainScene::resetLevelCallback,this));
	MenuItemImage* nextLevelItem = MenuItemImage::create(
		"next.png","next1.png", CC_CALLBACK_1(MainScene::nextLevelCallback, this));
	MenuItemImage* backLevelItem = MenuItemImage::create(
		"back.png", "back1.png", CC_CALLBACK_1(MainScene::backLevelCallback, this));

	menu->addChild(restItem);
	menu->addChild(nextLevelItem);
	menu->addChild(backLevelItem);
	restItem->setPosition(900, 50);
	backLevelItem->setPosition(50, 600);
	nextLevelItem->setPosition(900, 600);
	this->addChild(menu);
	menu->setPosition(0, 0);
	

    return true;
}
void MainScene::resetLevelCallback(Ref* sender)
{
	this->levelManager->resetLevel();
}
void MainScene::nextLevelCallback(Ref* sender){
	this->levelManager->nextLevel();
}
void MainScene::backLevelCallback(Ref* sender){
	this->levelManager->lastLevel();
}
void MainScene::onLevelComplete()
{
	//this->levelManager->nextLevel();
}