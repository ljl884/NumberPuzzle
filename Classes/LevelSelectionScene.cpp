#include "LevelSelectionScene.h"
#include "MainScene.h"
#include "LevelManager.h"
#include "Common.h"

#define LEVEL_PER_ROW 5
#define LEVEL_ROW_NUMBER 3

int LevelSelectionScene::currentPageNumber = 0;

Scene* LevelSelectionScene::createScene(){
    return createScene(currentPageNumber);
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
    
    // Remember to convert the integer to double first, otherwise the division will be automatically converted to
    // integer.
    this->maximumPageNumber = ceil(double(levelManager->levelCount()) / double(LEVEL_PER_ROW * LEVEL_ROW_NUMBER));
    
    Menu* menu = Menu::create();
    Label* resetProgressLabel = Label::createWithTTF(FontManager::getInstance().levelSelectionTextLabelFontConfig(), "Reset Progress");
    
    MenuItemLabel* resetProgressItem = MenuItemLabel::create(resetProgressLabel, CC_CALLBACK_1(LevelSelectionScene::resetProgressCallback, this));
    resetProgressItem->setPosition(800, 50);
    menu->addChild(resetProgressItem);
    
    int startLevelNumber = pageNumber * (LEVEL_ROW_NUMBER * LEVEL_PER_ROW);
    
    for (int i = 0; i < LEVEL_ROW_NUMBER; i++)
    {
        for (int j = 0; j < LEVEL_PER_ROW; j++)
        {
            int currentLevelNumber = j + i * LEVEL_PER_ROW + startLevelNumber;
            
            // If it's no more level available, we should just break.
            if (currentLevelNumber >= levelManager->levelCount()) {
                break;
            }
            
            Sprite* number = Sprite::create();
            Sprite* numberSelected = Sprite::create();
            if (levelManager->isLevelCompleted(currentLevelNumber)) {
                number->setTexture("level_complete_default.png");
                numberSelected->setTexture("level_complete_selected.png");
            }
            else {
                number->setTexture("level_incomplete_default.png");
                numberSelected->setTexture("level_incomplete_selected.png");
            }
            
            Label* label = Label::createWithTTF(FontManager::getInstance().levelSelectionNumberLabelFontConfig(), Helper::int2str(currentLevelNumber + 1));
            
            number->addChild(label);
            numberSelected->addChild(label);
            
            label->setPosition(number->getContentSize().width / 2, number->getContentSize().height / 2);
            //LevelNumber* number = new LevelNumber(i*LEVEL_PER_ROW + j + 1, true);
            
            MenuItemSprite* numberItem = MenuItemSprite::create(number, numberSelected, CC_CALLBACK_1(LevelSelectionScene::onLevelNumberCallback, this, currentLevelNumber));
            
            numberItem->setPosition(180 + j * 140, 500 - i * 140);
            menu->addChild(numberItem);
        }
    }
    
    MenuItemImage* nextPageItem = MenuItemImage::create("next_page_default.png", "next_page_selected.png", CC_CALLBACK_1(LevelSelectionScene::onNextPageCallback, this));
    menu->addChild(nextPageItem);
    nextPageItem->setPosition(530, 50);
    
    // If this page is the last page, we certainly not want to enable this button;)
    if (pageNumber >= maximumPageNumber - 1) {
        nextPageItem->setVisible(false);
    }
    
    MenuItemImage* lastPageItem = MenuItemImage::create("last_page_default.png", "last_page_selected.png", CC_CALLBACK_1(LevelSelectionScene::onLastPageCallback, this));
    menu->addChild(lastPageItem);
    lastPageItem->setPosition(405, 50);
    
    // If this page is the first page, we certainly not want to enable this button;)
    if (pageNumber == 0) {
        lastPageItem->setVisible(false);
    }
    
    this->addChild(menu);
    menu->setPosition(0, 0);
    
    Helper::scaleSpriteAndChildren(menu);
    
    // CCLOG("Current page number: %d : %d", pageNumber, maximumPageNumber);
    
    return true;
}
void LevelSelectionScene::onLevelNumberCallback(Ref* sender, int levelNumber){
    auto scene = MainScene::createScene(levelNumber);
    Director::getInstance()->replaceScene(TransitionFade::create(0.5, scene));
    
}
void LevelSelectionScene::resetProgressCallback(Ref* sender){
    LevelManager::getInstance()->resetUserData();
    Director::getInstance()->replaceScene(LevelSelectionScene::createScene());
}
void LevelSelectionScene::setPageNumber(int pageNumber){
    this->pageNumber = pageNumber;
}

void LevelSelectionScene::onNextPageCallback(Ref* sender){
    if (currentPageNumber >= maximumPageNumber - 1) {
        return;
    }
    currentPageNumber += 1;
    Director::getInstance()->replaceScene(TransitionFade::create(0.5, LevelSelectionScene::createScene(currentPageNumber)));
}
void LevelSelectionScene::onLastPageCallback(Ref* sender){
    if (currentPageNumber == 0)
        return;
    currentPageNumber -= 1;
    Director::getInstance()->replaceScene(TransitionFade::create(0.5, LevelSelectionScene::createScene(currentPageNumber)));
}