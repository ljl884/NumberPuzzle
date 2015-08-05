//
//  CoverLayer.cpp
//  NumberPuzzle
//
//  Created by Jin Wang on 5/08/2015.
//
//

#include "CoverLayer.h"
#include "cocos2d.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

bool CoverLayer::init() {
    if (!cocos2d::LayerColor::initWithColor(cocos2d::Color4B(0, 0, 0, 0)))
    {
        return false;
    }
    
    this->setPosition(cocos2d::Vec2(0, 0));
    auto director = cocos2d::Director::getInstance();
    cocos2d::Size Size = director->getWinSize();
    this->setContentSize(Size);
    // this->setColor(cocos2d::ColorB(255, 255, 255,255));
//    this->setOpacity(128); // Opacity 0 - 255
    
    auto touchListener = cocos2d::EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);
    touchListener->onTouchBegan = CC_CALLBACK_2(CoverLayer::onTouch, this);
    director->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
    
    this->setOpacity(0);
    
    return true;
}

void CoverLayer::show() {
    Action *action = Sequence::create(DelayTime::create(0.5), FadeTo::create(0.5, 0.5 * 255), NULL);
    this->runAction(action);
}

void CoverLayer::hide() {
    Action *action = Sequence::create(FadeTo::create(0.5, 0), NULL);
    this->runAction(action);
}

bool CoverLayer::onTouch(cocos2d::Touch* touch, cocos2d::Event* event)
{
    // cocos2d::log("touch swallowed");
    return this->getOpacity() != 0;
    // Swallow them touches whole!
}