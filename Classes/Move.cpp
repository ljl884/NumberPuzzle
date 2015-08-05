#include "Move.h"
#include "Table.h"
#define MOVE_DURATION 0.3
Move::Move(MoveableNumber* moveableNumber, StaticNumber* staticNumber, Direction direction, Point fromLogicPosition)
{
	this->moveableNumber = moveableNumber;
	this->staticNumber = staticNumber;
	this->direction = direction;
	this->fromLogicPosition = fromLogicPosition;
}
void Move::doMove()
{
	moveableNumber->decreaseValueBy(staticNumber->getValue());
	moveableNumber->update();
	staticNumber->decreaseLevel();
	staticNumber->update();
	switch (direction)
	{
	case UP:
		moveableNumber->runAction(MoveBy::create(MOVE_DURATION, Point(0, Y_ALIGN)));
		break;
	case DOWN:
		moveableNumber->runAction(MoveBy::create(MOVE_DURATION, Point(0, 0 - Y_ALIGN)));
		break;
	case LEFT:
		moveableNumber->runAction(MoveBy::create(MOVE_DURATION, Point(0 - X_ALIGN, 0)));
		break;
	case RIGHT:
		moveableNumber->runAction(MoveBy::create(MOVE_DURATION, Point(X_ALIGN, 0)));
		break;
	default:
		return;
	}
}
void Move::undo()
{
	moveableNumber->decreaseValueBy(0 - staticNumber->getValue());
	moveableNumber->setLogicPosition(fromLogicPosition);
	moveableNumber->update();
	staticNumber->increaseLevel();
	staticNumber->update();
	switch (direction)
	{
	case DOWN:
		moveableNumber->runAction(MoveBy::create(MOVE_DURATION, Point(0, Y_ALIGN)));
		break;
	case UP:
		moveableNumber->runAction(MoveBy::create(MOVE_DURATION, Point(0, 0 - Y_ALIGN)));
		break;
	case RIGHT:
		moveableNumber->runAction(MoveBy::create(MOVE_DURATION, Point(0 - X_ALIGN, 0)));
		break;
	case LEFT:
		moveableNumber->runAction(MoveBy::create(MOVE_DURATION, Point(X_ALIGN, 0)));
		break;
	default:
		return;
	}
}