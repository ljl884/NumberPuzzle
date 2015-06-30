/*Written by Wentao Li*/
#ifndef _TABLE_
#define _TABLE_
#include "cocos2d.h"
#define TABLE_WIDTH 13
#define TABLE_HIGHT 9
#define X_ALIGN 100
#define Y_ALIGN 100
USING_NS_CC;
class StaticNumber;
class MoveableNumber;

//Maintains a set of numbers, handles touch events
class Table :public Layer{
public:
	Table(Node* parent);
	void addMoveableNumber(int value, Point position);
	void addStaticNumber(int value, int level, Point position);
private:
	Node* parent;
	Point logicPositionToRealPosition(Point logicPosition);
	void initListener();	
	int MoveableNumberCount;
	int StaticNumberCount;
	std::vector<StaticNumber*> staticNumbers;
	std::vector<MoveableNumber*> moveableNumbers;
	MoveableNumber* currentNumber;//currently selected number. equals nullptr when nothing is selected

	virtual bool onTouchBegan(Touch* touch, Event* event);
	virtual void onTouchMoved(Touch* touch, Event* event);
	virtual void onTouchEnded(Touch* touch, Event* event);
};
#endif