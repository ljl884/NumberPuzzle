#include "LevelSelectionScene.h"
#include "LevelNumber.h"
#include "MainScene.h"
#define LEVEL_PER_ROW 9
#define LEVEL_ROW_NUMBER 5
USING_NS_CC;

Scene* LevelSelectionScene::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = LevelSelectionScene::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}
bool LevelSelectionScene::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}
	Menu* menu = Menu::create();
	

	Sprite* bg = Sprite::create("bg.png");
	bg->setAnchorPoint(Point::ANCHOR_BOTTOM_LEFT);
	this->addChild(bg);
	for (int i = 0; i < LEVEL_ROW_NUMBER; i++)
	{
		for (int j = 0; j < LEVEL_PER_ROW; j++)
		{
			Sprite* number = Sprite::create("level_complete_default.png");
			Label* label = Label::create(Helper::int2str(i*LEVEL_PER_ROW + j + 1), "Marker Felt.ttf", 20);
			number->addChild(label);
			label->setPosition(25, 25);
			//LevelNumber* number = new LevelNumber(i*LEVEL_PER_ROW + j + 1, true);
			
			MenuItemSprite* numberItem = MenuItemSprite::create(number, number, CC_CALLBACK_1(LevelSelectionScene::onLevelNumberCallback, this, i*LEVEL_PER_ROW + j));
			numberItem->setPosition(180 + j * 70, 500 - i * 70);
			menu->addChild(numberItem);
			
		}
	}
	this->addChild(menu);
	menu->setPosition(0, 0);
	return true;
}
void LevelSelectionScene::onLevelNumberCallback(Ref* sender, int levelNumber){
	auto scene = MainScene::createScene(levelNumber);
	Director::sharedDirector()->replaceScene(TransitionFade::create(0.5, scene));

}