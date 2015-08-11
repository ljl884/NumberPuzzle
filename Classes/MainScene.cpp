#include "MainScene.h"
#include "LevelSelectionScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "StaticNumber.h"
#include "MoveableNumber.h"
#include "Table.h"
#include "Common.h"
#include "LevelManager.h"
#include "LevelCompleteLayer.h"
#include "CoverLayer.h"
#include "Tutorial.h"

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
    
	this->setTouchEnabled(true);

    this->levelNumberLabel = Label::createWithTTF(FontManager::getInstance().levelTextLabelFontConfig(), Helper::int2str(1));
	levelNumberLabel->setPosition(480, 600);
    Helper::scaleSprite(levelNumberLabel);
	this->addChild(levelNumberLabel);

	this->levelManager = LevelManager::getInstance();
	levelManager->setParent(this);
	levelManager->runLevel(0);

    // The mask should behind the complete layer.
    levelCompleteMask = CoverLayer::create();
    this->addChild(levelCompleteMask, 4);
    
	levelCompleteLayer = new LevelCompleteLayer(this);
	levelCompleteLayer->setPosition(480, 320);
	this->addChild(levelCompleteLayer, 5);
    

	Menu * menu = Menu::create();
	MenuItemImage* restItem = MenuItemImage::create(
		"reset_level_default.png", "reset_level_selected.png",
		CC_CALLBACK_1(MainScene::resetLevelCallback,this));
	
	MenuItemImage* selectLevelItem = MenuItemImage::create(
		"select_level_default.png", "select_level_selected.png",
		CC_CALLBACK_1(MainScene::selectLevelCallback,this));
	MenuItemImage* undoItem = MenuItemImage::create("undo_default.png",
                                                    "undo_selected.png",
                                                    CC_CALLBACK_1(MainScene::undoCallback, this));
    MenuItemImage *musicEnabledItem = MenuItemImage::create("sound_default.png",
                                                            "sound_selected.png");
    
    MenuItemImage *musicDisabledItem = MenuItemImage::create("sound_disabled.png", "sound_selected.png");
    
    
    musicItem = MenuItemToggle::createWithCallback(CC_CALLBACK_1(MainScene::musicCallback, this),
                                                   musicEnabledItem,
                                                   musicDisabledItem,
                                                   NULL);
    

    int defaultIndex = MusicManager::getInstance().isMute() ? 1 : 0;
    
    musicItem->setSelectedIndex(defaultIndex);
    
	menu->addChild(restItem);
	menu->addChild(selectLevelItem);
	menu->addChild(undoItem);
    menu->addChild(musicItem);
    
	undoItem->setPosition(50, 50);
	restItem->setPosition(900, 50);	
	selectLevelItem->setPosition(50, 600);
    musicItem->setPosition(900, 600);
    
	if (DEBUG){
		MenuItemImage* nextLevelItem = MenuItemImage::create(
			"last_level.png", "next_level.png", CC_CALLBACK_1(MainScene::nextLevelCallback, this));
		MenuItemImage* backLevelItem = MenuItemImage::create(
			"back.png", "back1.png", CC_CALLBACK_1(MainScene::backLevelCallback, this));
		backLevelItem->setPosition(50, 600);
		nextLevelItem->setPosition(900, 600);
		menu->addChild(nextLevelItem);
		menu->addChild(backLevelItem);
	}

	this->addChild(menu);
	menu->setPosition(0, 0);
	
	 
    Helper::scaleSpriteAndChildren(menu);
    return true;
}
void MainScene::resetLevelCallback(Ref* sender)
{
	this->levelCompleteLayer->hide();
    this->levelCompleteMask->hide();
	this->levelManager->resetLevel();
}
void MainScene::nextLevelCallback(Ref* sender){
	this->levelCompleteLayer->hide();
    this->levelCompleteMask->hide();
	this->levelManager->nextLevel();
}
void MainScene::backLevelCallback(Ref* sender){
	this->levelManager->lastLevel();
}
void MainScene::selectLevelCallback(Ref* sender){
	Director::getInstance()->replaceScene(TransitionFade::create(0.5,LevelSelectionScene::createScene()));
    
    // Whoops, the user gave up the level.
    AnalyticsManager::getInstance().levelEnded(levelNumberLabel->getString(), false);
}
void MainScene::undoCallback(Ref* sender){
	this->levelManager->undo();
}

void MainScene::musicCallback(Ref* sender) {
    // Toggle the music.
    MusicManager::getInstance().toggleMute();
}

void MainScene::onLevelComplete()
{
	levelManager->completeCurrentLevel();
    levelCompleteMask->show();
	levelCompleteLayer->show();
    
    // Wow, the user completed the level successfully. We terminate the level time spent event.
    AnalyticsManager::getInstance().levelEnded(levelNumberLabel->getString(), true);
}
void MainScene::setLevelNumber(int levelNumber){
	levelNumberLabel->setString(Helper::int2str(levelNumber));
    
    // We will run the Tutorial if it's the first two levels
    
    if (tutorialLayer != nullptr) {
        this->removeChild(tutorialLayer);
        tutorialLayer = nullptr;
    }
    
    if (levelNumber <= 2) {
        
        tutorialLayer = Tutorial::create();
        tutorialLayer->setPosition(480, 320);
        
        this->addChild(tutorialLayer, 5);
        
        Helper::scaleSpriteAndChildren(tutorialLayer);
        
        if (levelNumber == 1) {
            tutorialLayer->TutorialOne();
        } else {
            tutorialLayer->TutorialTwo();
        }
    }
    
    // We log the level start event as a timed event, so that
    // we can estimate how long the user spend on the level.
    AnalyticsManager::getInstance().levelStarted(levelNumberLabel->getString());
}
void MainScene::playLevel(int levelNumber){
	this->levelManager->runLevel(levelNumber);
}
