/*Written by Wentao Li*/
#include "Table.h"
#include "MoveManager.h"
#include "Number.h"
#include "MoveableNumber.h"
#include "StaticNumber.h"
#include "MainScene.h"

Table::Table(MainScene* parent)
{
	this->parent = parent;
	this->setAnchorPoint(cocos2d::Vec2::ANCHOR_MIDDLE);
	initListener();
	MoveableNumberCount = 0;
	StaticNumberCount = 0;
	currentNumber = nullptr;
	this->moveManager = new MoveManager(this);
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
bool Table::checkFinish()
{
	for (MoveableNumber* number : moveableNumbers){
		if (!number->isFinished())
			return false;
	}

	parent->onLevelComplete();
	return true;
}
Number* Table::getNumberByLogicPosition(Point logicPosition){
	for (MoveableNumber *number : moveableNumbers){
		if (logicPosition.equals(number->getLogicPosition()))
			return number;
	}
	for (StaticNumber *number : staticNumbers){
		if (logicPosition.equals(number->getLogicPosition()))
			return number;
	}
	
	return nullptr;
}

//Receives logic position and returns the world position
Point Table::logicPositionToRealPosition(Point logicPosition)
{
	int lx = logicPosition.x;
	int ly = logicPosition.y;
	if (abs(lx) > ((TABLE_WIDTH - 1) / 2) ||
		abs(ly) > ((TABLE_HIGHT - 1) / 2))
	{
		return Point(0,0);
	}


	int rx = Constant::X_ALIGN*lx;
	int ry = Constant::Y_ALIGN*ly;

	
	return Point(rx, ry);

}

void Table::addMoveableNumber(int value, Point position){

	Point p = logicPositionToRealPosition(position);
	
	Sprite* bg = Sprite::create("frame_0_empty.png");
    Helper::scaleSprite(bg);
	this->addChild(bg);
	bg->setPosition(p);

	MoveableNumber* number = new MoveableNumber(value);
	this->addChild(number);
	number->setZOrder(3);
	MoveableNumberCount++;
	number->setPosition(p);
	number->setLogicPosition(position);
	number->playAppearAnimation(0.5 + 0.05 * MoveableNumberCount);
    
	this->moveableNumbers.push_back(number);
	
}
void Table::addStaticNumber(int value, int level, Point position){
	Point p = logicPositionToRealPosition(position);
	
	Sprite* bg = Sprite::create("frame_1_4_empty.png");
	this->addChild(bg);
    Helper::scaleSprite(bg);
	bg->setPosition(p);

	StaticNumber* number = new StaticNumber(value, level);
	this->addChild(number);
	number->setZOrder(2);
	StaticNumberCount++;
	number->setPosition(p);
	number->setLogicPosition(position);
	number->playAppearAnimation(0.7 + 0.05 * StaticNumberCount);
    
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
			if (number->isFinished())
				return false;
			number->setHighlight(true);
			currentNumber = number;
			orignTouchLocation = position;
		}
	}
	return true;
}
void Table::onTouchMoved(Touch* touch, Event* event){
	if (currentNumber == nullptr)
		return;
	Point position = this->convertToNodeSpace(touch->getLocation());
	Point currentNumberPosition = logicPositionToRealPosition(currentNumber->getLogicPosition());
	if ((position.x - currentNumberPosition.x) >  Constant::X_ALIGN / 2)
	{
		moveManager->attemptMove(RIGHT, currentNumber);
		return;
	}
	if ((position.x - currentNumberPosition.x) < ((0 - Constant::X_ALIGN) / 2))
	{
		moveManager->attemptMove(LEFT, currentNumber);
		return;
	}
	if ((position.y - currentNumberPosition.y) > (Constant::Y_ALIGN / 2))
	{
		moveManager->attemptMove(UP, currentNumber);
		return;
	}
	if ((position.y - currentNumberPosition.y) < ((0 - Constant::Y_ALIGN) / 2))
	{
		moveManager->attemptMove(DOWN, currentNumber);
		return;
	}
	
}
void Table::onTouchEnded(Touch* touch, Event* event){
	if (currentNumber == nullptr)
		return;
	currentNumber->setHighlight(false);
	currentNumber = nullptr;
	
}
void Table::undo(){
	this->moveManager->undoMove();
}