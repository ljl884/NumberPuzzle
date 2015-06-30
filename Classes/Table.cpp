/*Written by Wentao Li*/
#include "Table.h"
#include "MoveableNumber.h"
#include "StaticNumber.h"

Table::Table(Node* parent)
{
	this->parent = parent;
	this->setAnchorPoint(cocos2d::Vec2::ANCHOR_MIDDLE);
	initListener();
	MoveableNumberCount = 0;
	StaticNumberCount = 0;
	currentNumber = nullptr;
}

//Attach touch listener to table layer, enable it to handle touch events
void Table::initListener()
{
	EventListenerTouchOneByOne* touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(Table::onTouchBegan, this);
	touchListener->onTouchMoved = CC_CALLBACK_2(Table::onTouchMoved, this);
	touchListener->onTouchEnded = CC_CALLBACK_2(Table::onTouchEnded, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, this);
}

//Receives logic position and returns the world position
Point Table::logicPositionToRealPosition(Point logicPosition)
{
	int lx = logicPosition.x;
	int ly = logicPosition.y;
	if (abs(lx) > ((TABLE_WIDTH - 1) / 2) ||
		abs(ly) > ((TABLE_HIGHT - 1) / 2))
	{
		return ccp(0,0);
	}
	int rx = X_ALIGN*lx;
	int ry = Y_ALIGN*ly;
	return ccp(rx, ry);

}

void Table::addMoveableNumber(int value, Point position){

	Point p = logicPositionToRealPosition(position);
	
	Sprite* bg = Sprite::create("frame_0_empty@2x.png");
	bg->setScale(0.3);
	this->addChild(bg);
	bg->setPosition(p);

	MoveableNumber* number = new MoveableNumber(value);
	this->addChild(number);
	number->setZOrder(3);
	MoveableNumberCount++;
	number->setPosition(p);
	number->setLogicPosition(position);
	number->playAppearAnimation(0.5 + 0.05*MoveableNumberCount);
	this->moveableNumbers.push_back(number);
}
void Table::addStaticNumber(int value, int level, Point position){
	Point p = logicPositionToRealPosition(position);
	
	Sprite* bg = Sprite::create("frame_1_4_empty@2x.png");
	this->addChild(bg);
	bg->setScale(0.3);
	bg->setPosition(p);

	StaticNumber* number = new StaticNumber(value, level);
	this->addChild(number);
	number->setZOrder(2);
	StaticNumberCount++;
	number->setPosition(p);
	number->setLogicPosition(position);
	number->playAppearAnimation(0.7 + 0.03*MoveableNumberCount);
	this->staticNumbers.push_back(number);
	
}
bool Table::onTouchBegan(Touch* touch, Event* event){
	Point position = this->convertToNodeSpace(touch->getLocation());
	for (int i = 0; i < moveableNumbers.size();i++){
		MoveableNumber *number = moveableNumbers.at(i);
		Rect *rect = new Rect(number->getPosition().x - number->getContainerSize().width*SCALE/2,
			number->getPosition().y - number->getContainerSize().height*SCALE/2,
			number->getContainerSize().width*SCALE, number->getContainerSize().height*SCALE);
		if (rect->containsPoint(position)){
			number->setHighlight(true);
			currentNumber = number;
		}
	}
	return true;
}
void Table::onTouchMoved(Touch* touch, Event* event){

}
void Table::onTouchEnded(Touch* touch, Event* event){
	if (currentNumber == nullptr)
		return;
	currentNumber->setHighlight(false);
	currentNumber = nullptr;
	
}