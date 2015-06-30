/*Written by Wentao Li*/
#ifndef _NUMBER_
#define _NUMBER_
#include "cocos2d.h"
USING_NS_CC;
#define MAX_LEVEL 3
#define SCALE 1

class Number : public Node{
public:
	Number();
	inline int getValue(){ return value; }
	inline int getLevel(){ return level; }
	inline Point getLogicPosition(){ return logicPosition; }
	inline void setLogicPosition(Point position){ this->logicPosition = position; }
	void playAppearAnimation(float Delay);
	Size getContainerSize();
protected:
	Sprite * container;
	Label * numberLabel;
	int value;
	bool selected;
	int level;

	Point logicPosition;

};
#endif