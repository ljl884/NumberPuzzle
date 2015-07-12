#ifndef _MOVE_
#define _MOVE_

#include "cocos2d.h"
#include "MoveableNumber.h"
#include "StaticNumber.h"
USING_NS_CC;
enum Direction{
	LEFT, RIGHT, UP, DOWN
};
class Move{
public:
	Move(MoveableNumber* moveableNumber, StaticNumber* staticNumber, Direction direction, Point fromLogicPosition);
	void undo();
	void doMove();
private:
	MoveableNumber* moveableNumber;
	StaticNumber* staticNumber;
	Direction direction;
	Point fromLogicPosition;
};
#endif