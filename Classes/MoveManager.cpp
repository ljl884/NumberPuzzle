#include "MoveManager.h"
#include "Table.h"
#include "MoveableNumber.h"
#include "StaticNumber.h"
#define MOVE_DURATION 0.5
MoveManager::MoveManager(Table * table)
{
	this->table = table;
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
		destinationPosition = ccp(logicPosition.x, logicPosition.y + 1);
		break;
	case DOWN:
		destinationPosition = ccp(logicPosition.x, logicPosition.y - 1);
		break;
	case LEFT:
		destinationPosition = ccp(logicPosition.x-1, logicPosition.y);
		break;
	case RIGHT:
		destinationPosition = ccp(logicPosition.x+1, logicPosition.y);
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
		doMove(direction, moveableNumber, (StaticNumber*)destination);
		moveableNumber->setLogicPosition(destinationPosition);
		return true;
	}
	

}
void MoveManager::doMove(Direction direction, MoveableNumber* moveableNumber, StaticNumber* staticNumber)
{
	moveableNumber->decreaseValueBy(staticNumber->getValue());
	moveableNumber->update();
	staticNumber->decreaseLevel();
	staticNumber->update();
	switch (direction)
	{
	case UP:
		moveableNumber->runAction(MoveBy::create(MOVE_DURATION, ccp(0, Y_ALIGN)));
		break;
	case DOWN:
		moveableNumber->runAction(MoveBy::create(MOVE_DURATION, ccp(0, 0-Y_ALIGN)));
		break;
	case LEFT:
		moveableNumber->runAction(MoveBy::create(MOVE_DURATION, ccp(0-X_ALIGN, 0)));
		break;
	case RIGHT:
		moveableNumber->runAction(MoveBy::create(MOVE_DURATION, ccp(X_ALIGN, 0)));
		break;
	default:
		return;
	}
	table->checkFinish();

}