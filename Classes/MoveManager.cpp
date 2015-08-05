#include "MoveManager.h"
#include "Table.h"
#include "MoveableNumber.h"
#include "StaticNumber.h"

MoveManager::MoveManager(Table * table)
{
	this->table = table;
	this->moveHistory = new std::stack<Move*>();
}
MoveManager::~MoveManager(){
	delete moveHistory;
}
bool MoveManager::attemptMove(Direction direction, MoveableNumber* moveableNumber)
{
	if (moveableNumber == nullptr)
		return false;
	if (moveableNumber->isFinished())
		return false;
	Point logicPosition = moveableNumber->getLogicPosition();
	Point destinationPosition;
	switch (direction)
	{
	case UP:
		destinationPosition = Point(logicPosition.x, logicPosition.y + 1);
		break;
	case DOWN:
		destinationPosition = Point(logicPosition.x, logicPosition.y - 1);
		break;
	case LEFT:
		destinationPosition = Point(logicPosition.x-1, logicPosition.y);
		break;
	case RIGHT:
		destinationPosition = Point(logicPosition.x+1, logicPosition.y);
		break;
	default:
		return false;
	}
	Number* destination = table->getNumberByLogicPosition(destinationPosition);
	if (destination == nullptr)
		return false;
	else if (!destination->coverable())
		return false;
	else{
		
		Move * move = new Move(moveableNumber, (StaticNumber*)destination, direction, moveableNumber->getLogicPosition());
		moveHistory->push(move);
		move->doMove();
		moveableNumber->setLogicPosition(destinationPosition);
		table->checkFinish();
		return true;
	}
	

}
bool MoveManager::undoMove() {
	if (moveHistory->empty())
		return false;
	Move* move = moveHistory->top();
	moveHistory->pop();
	move->undo();
    
    return true;
}
