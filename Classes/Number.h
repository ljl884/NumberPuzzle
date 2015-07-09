/*Written by Wentao Li*/
#ifndef _NUMBER_
#define _NUMBER_
#include "cocos2d.h"
#include "Helper.h"

#define MAX_LEVEL 4
#define SCALE 1

USING_NS_CC;

class Number : public Node{
public:
	Number();
	inline int getValue(){ return value; }
	inline int getLevel(){ return level; }
	inline void decreaseValueBy(int value){ this->value-= value; }
	inline Point getLogicPosition(){ return logicPosition; }
	inline void setLogicPosition(Point position){ this->logicPosition = position; }
	void playAppearAnimation(float Delay);
	Size getContainerSize();
	virtual bool coverable(); 
	virtual void update();
protected:
	Sprite * container;
	Label * numberLabel;
	int value;
	bool selected;
	int level;

	Point logicPosition;

};
#endif