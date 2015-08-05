#ifndef _MOVE_MANAGER_
#define _MOVE_MANAGER_
#include "cocos2d.h"
#include "Move.h"

class Table;
class MoveableNumber;
class StaticNumber;

class MoveManager
{
public:
	MoveManager(Table* table);
	~MoveManager();
	bool attemptMove(Direction direction, MoveableNumber* moveableNumber);
	bool undoMove();
private:
	Table* table;
	std::stack<Move*> *moveHistory;
};
#endif