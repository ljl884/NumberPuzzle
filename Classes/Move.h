#ifndef _MOVE_
#define _MOVE_

#include "cocos2d.h"

class MoveableNumber;
class StaticNumber;

enum Direction{
	LEFT, RIGHT, UP, DOWN
};
class Move{
public:
	Move(MoveableNumber* moveableNumber, StaticNumber* staticNumber, Direction direction, cocos2d::Point fromLogicPosition);
	void undo();
	void doMove();
private:
	MoveableNumber* moveableNumber;
	StaticNumber* staticNumber;
	Direction direction;
	cocos2d::Point fromLogicPosition;
};
#endif