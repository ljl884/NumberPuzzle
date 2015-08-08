/*Written by Wentao Li*/
#ifndef _NUMBER_
#define _NUMBER_
#include "cocos2d.h"
#include "Common.h"

#define MAX_LEVEL 4
#define SCALE 1

//
class Number : public Node {
public:
	Number();
	inline int getValue(){ return value; }
	inline int getLevel(){ return level; }
	inline void decreaseValueBy(int value){ this->value-= value; }
    inline cocos2d::Point getLogicPosition(){ return logicPosition; }
	inline void setLogicPosition(cocos2d::Point position){ this->logicPosition = position; }
	void playAppearAnimation(float Delay);
	cocos2d::Size getContainerSize();
	virtual bool coverable(); 
	virtual void update();
protected:
	Sprite * container;
	Label * numberLabel;
	int value;
	bool selected;
	int level;

	cocos2d::Point logicPosition;
    
    void numberFadeInCallback();

};
#endif