#include "LevelSelectionScene.h"
#include "MainScene.h"
#define LEVEL_PER_ROW 5
#define LEVEL_ROW_NUMBER 3

USING_NS_CC;
Scene* LevelSelectionScene::createScene(){
	return createScene(0);
}
Scene* LevelSelectionScene::createScene(int pageNumber)
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = LevelSelectionScene::create(pageNumber);
	layer->setPageNumber(pageNumber);
	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}
LevelSelectionScene* LevelSelectionScene::create(int pageNumber)
{
	LevelSelectionScene *pRet = new(std::nothrow) LevelSelectionScene();
	if (pRet && pRet->init(pageNumber))
	{
		pRet->autorelease();
		return pRet;
	}
	else
	{
		delete pRet;
		pRet = NULL;
		return NULL;
	}
}
bool LevelSelectionScene::init(int pageNumber)
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}
	LevelManager* levelManager = LevelManager::getInstance();
	Menu* menu = Menu::create();
	Label* resetProgressLabel = Label::create("Reset Progress", "Marker Felt.ttf", 35);
	
	MenuItemLabel* resetProgressItem = MenuItemLabel::create(resetProgressLabel, CC_CALLBACK_1(LevelSelectionScene::resetProgressCallback, this));
	resetProgressItem->setPosition(850, 50);
	menu->addChild(resetProgressItem);

	int startLevelNumber = pageNumber*(LEVEL_ROW_NUMBER*LEVEL_PER_ROW);

	for (int i = 0; i < LEVEL_ROW_NUMBER; i++)
	{
		for (int j = 0; j < LEVEL_PER_ROW; j++)
		{
			
			Sprite* number = Sprite::create();
            Sprite* numberSelected = Sprite::create();
            if (levelManager->isLevelCompleted(j + i*LEVEL_PER_ROW+startLevelNumber)) {
                number->setTexture("level_complete_default.png");
                numberSelected->setTexture("level_complete_selected.png");
            }
            else {
                number->setTexture("level_incomplete_default.png");
                numberSelected->setTexture("level_incomplete_selected.png");
            }
				
			Label* label = Label::create(Helper::int2str(i*LEVEL_PER_ROW + j + 1 + startLevelNumber), "Marker Felt.ttf", 40);
			number->addChild(label);
            numberSelected->addChild(label);
			label->setPosition(number->getContentSize().width / 2, number->getContentSize().height / 2);
			//LevelNumber* number = new LevelNumber(i*LEVEL_PER_ROW + j + 1, true);
			
			MenuItemSprite* numberItem = MenuItemSprite::create(number, numberSelected, CC_CALLBACK_1(LevelSelectionScene::onLevelNumberCallback, this, i*LEVEL_PER_ROW + j + startLevelNumber));
			numberItem->setPosition(180 + j * 140, 500 - i * 140);
			menu->addChild(numberItem);
			
            Helper::scaleSpriteAndChildren(number);
		}
	}

	MenuItemImage* nextPageItem = MenuItemImage::create("next_page_default.png", "next_page_selected.png", CC_CALLBACK_1(LevelSelectionScene::onNextPageCallback, this));
	menu->addChild(nextPageItem);
    nextPageItem->setPosition(600, 50);
    
    MenuItemImage* lastPageItem = MenuItemImage::create("last_page_default.png", "last_page_selected.png", CC_CALLBACK_1(LevelSelectionScene::onLastPageCallback, this));
    menu->addChild(lastPageItem);
    lastPageItem->setPosition(400, 50);
    
    this->addChild(menu);
	menu->setPosition(0, 0);
	return true;
}
void LevelSelectionScene::onLevelNumberCallback(Ref* sender, int levelNumber){
	auto scene = MainScene::createScene(levelNumber);
	Director::sharedDirector()->replaceScene(TransitionFade::create(0.5, scene));

}
void LevelSelectionScene::resetProgressCallback(Ref* sender){
	LevelManager::getInstance()->resetUserData();
	Director::sharedDirector()->replaceScene(LevelSelectionScene::createScene());
}
void LevelSelectionScene::setPageNumber(int pageNumber){
	this->pageNumber = pageNumber;
}

void LevelSelectionScene::onNextPageCallback(Ref* sender){
	Director::sharedDirector()->replaceScene(TransitionFade::create(0.5, LevelSelectionScene::createScene(this->pageNumber + 1)));
}
void LevelSelectionScene::onLastPageCallback(Ref* sender){
	if (this->pageNumber == 0)
		return;
    Director::sharedDirector()->replaceScene(TransitionFade::create(0.5, LevelSelectionScene::createScene(this->pageNumber - 1)));
}