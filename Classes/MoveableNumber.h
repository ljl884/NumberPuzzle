/*Written by Wentao Li*/
#ifndef _MOVEABLE_NUMBER_
#define _MOVEABLE_NUMBER_
#include "cocos2d.h"
#include "Number.h"
USING_NS_CC;
class MoveableNumber :public Number{
public:
	MoveableNumber(int value);
	void setHighlight(bool highlight);
	virtual bool coverable();
	virtual void update();
	inline bool isFinished(){ return this->finished; }

private:
	bool finished;//This flag will be set to true only when the value is 0
	bool highlighted;//This flag will be set to true when the number is highlighted
	Sprite* highlightedContainer;
	Sprite* finishContainer;
};
#endif