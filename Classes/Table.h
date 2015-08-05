/*Written by Wentao Li*/
#ifndef _TABLE_
#define _TABLE_
#include "cocos2d.h"

#define TABLE_WIDTH 13
#define TABLE_HIGHT 9
#define X_ALIGN 100
#define Y_ALIGN 100

using namespace cocos2d;

class StaticNumber;
class MoveableNumber;
class Number;
class MoveManager;
class MainScene;

//Maintains a set of numbers, handles touch events
class Table :public Layer{
public:
	Table(MainScene* parent);
	void addMoveableNumber(int value, Point position);
	void addStaticNumber(int value, int level, Point position);
	Number* getNumberByLogicPosition(Point logicPosition);
	bool checkFinish();
	void undo();
private:
	MoveManager* moveManager;
	MainScene* parent;
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
	Point orignTouchLocation;
};
#endif