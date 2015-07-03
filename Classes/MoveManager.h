#ifndef _MOVE_MANAGER_
#define _MOVE_MANAGER_
#include "cocos2d.h"
USING_NS_CC;
class Table;
class MoveableNumber;
class StaticNumber;
enum Direction{
	LEFT, RIGHT, UP, DOWN
};
class MoveManager
{
public:
	MoveManager(Table* table);
	bool attemptMove(Direction direction, MoveableNumber* moveableNumber);
private:
	void doMove(Direction direction, MoveableNumber* moveableNumber, StaticNumber* staticNumber);
	Table* table;
};
#endif