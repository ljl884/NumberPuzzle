#include "MainScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "StaticNumber.h"
#include "MoveableNumber.h"
#include "Table.h"
#include "Helper.h"
#include "LevelSelectionScene.h"


USING_NS_CC;

using namespace cocostudio::timeline;

Scene* MainScene::createScene(int levelNumber)
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
	auto layer = MainScene::create();
	layer->playLevel(levelNumber);

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

	this->levelNumberLabel = Label::create(Helper::int2str(1), "Marker Felt.ttf", 35);
	levelNumberLabel->setPosition(480, 600);
	this->addChild(levelNumberLabel);

	this->levelManager = LevelManager::getInstance();
	levelManager->setParent(this);
	levelManager->runLevel(0);

	levelCompleteLayer = new LevelCompleteLayer(this);
	levelCompleteLayer->setPosition(480, 320);
	this->addChild(levelCompleteLayer);
	

	Menu * menu = Menu::create();
	MenuItemImage* restItem = MenuItemImage::create(
		"reset_level_default@3x.png", "reset_level_selected@3x.png",
		CC_CALLBACK_1(MainScene::resetLevelCallback,this));
	
	MenuItemImage* selectLevelItem = MenuItemImage::create(
		"select_level_selected@3x.png", "select_level_default@3x.png", 
		CC_CALLBACK_1(MainScene::selectLevelCallback,this));
	MenuItemImage* undoItem = MenuItemImage::create(
		"undo_default@3x.png", "undo_selected@3x.png",
		CC_CALLBACK_1(MainScene::undoCallback, this));

	menu->addChild(restItem);
	menu->addChild(selectLevelItem);
	menu->addChild(undoItem);
	undoItem->setPosition(50, 50);
	restItem->setPosition(900, 50);	
	selectLevelItem->setPosition(50, 600);
	if (DEBUG){
		MenuItemImage* nextLevelItem = MenuItemImage::create(
			"next.png", "next1.png", CC_CALLBACK_1(MainScene::nextLevelCallback, this));
		MenuItemImage* backLevelItem = MenuItemImage::create(
			"back.png", "back1.png", CC_CALLBACK_1(MainScene::backLevelCallback, this));
		backLevelItem->setPosition(50, 600);
		nextLevelItem->setPosition(900, 600);
		menu->addChild(nextLevelItem);
		menu->addChild(backLevelItem);
	}

	this->addChild(menu);
	menu->setPosition(0, 0);
	
	 

    return true;
}
void MainScene::resetLevelCallback(Ref* sender)
{
	this->levelCompleteLayer->hide();
	this->levelManager->resetLevel();
}
void MainScene::nextLevelCallback(Ref* sender){
	this->levelCompleteLayer->hide();
	this->levelManager->nextLevel();
}
void MainScene::backLevelCallback(Ref* sender){
	this->levelManager->lastLevel();
}
void MainScene::selectLevelCallback(Ref* sender){
	Director::sharedDirector()->replaceScene(TransitionFade::create(0.5,LevelSelectionScene::createScene()));
}
void MainScene::undoCallback(Ref* sender){
	this->levelManager->undo();
}
void MainScene::onLevelComplete()
{
	levelManager->completeCurrentLevel();
	levelCompleteLayer->show();
}
void MainScene::setLevelNumber(int levelNumber){
	levelNumberLabel->setString(Helper::int2str(levelNumber));
}
void MainScene::playLevel(int levelNumber){
	this->levelManager->runLevel(levelNumber);
}
