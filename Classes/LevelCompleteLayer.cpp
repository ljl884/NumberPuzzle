#include "LevelCompleteLayer.h"
#include "MainScene.h"
LevelCompleteLayer::LevelCompleteLayer(MainScene* parent){
	
	background = Sprite::create("level_complete_default@3x.png");
	background->setScaleX(4);
	background->setScaleY(3);
	label = Label::create("Level Complete", "Marker Felt.ttf", 50);
	label->setPosition(0, 100);
	
	MenuItemImage* levelSelection = MenuItemImage::create("select_level_default@3x.png", "select_level_selected@3x.png",
		CC_CALLBACK_1(MainScene::selectLevelCallback, parent));
	levelSelection->setPosition(-90, -100);
	MenuItemImage* resetLevel = MenuItemImage::create("reset_level_selected@3x.png", "reset_level_default@3x.png",
		CC_CALLBACK_1(MainScene::resetLevelCallback, parent));
	resetLevel->setPosition(0, -100);
	MenuItemImage* nextLevel = MenuItemImage::create("next3.png", "next33.png",
		CC_CALLBACK_1(MainScene::nextLevelCallback, parent));
	nextLevel->setPosition(90, -100);
	menu = Menu::create(levelSelection, resetLevel, nextLevel,NULL);
	menu->setPosition(0, 0);
	menu->setEnabled(false);
	this->setZOrder(5);
	this->addChild(background);
	this->addChild(label);
	this->addChild(menu);
	background->setOpacity(0);
	menu->setOpacity(0);
	label->setOpacity(0);
	this->parent = parent;
}

void LevelCompleteLayer::show(){
	menu->setEnabled(true);
	Action* action = Sequence::create(DelayTime::create(0.5), FadeIn::create(0.5), NULL);
	background->runAction(action);
	label->runAction(action->clone());
	menu->runAction(action->clone());
}
void LevelCompleteLayer::hide(){
	menu->setEnabled(false);
	Action* action = Sequence::create(FadeOut::create(0.5), NULL);
	background->runAction(action);
	label->runAction(action->clone());
	menu->runAction(action->clone());
}