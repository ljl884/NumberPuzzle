/*Written by Wentao Li*/
#ifndef _LEVEL_NUMBER_
#define _LEVEL_NUMBER_

#include "cocos2d.h"
#include "Number.h"

USING_NS_CC;
class LevelNumber : public Number{
public:
	LevelNumber(int value,bool completed);
	inline bool isCompleted(){ return completed; }
	inline Sprite* getSprite(){ return container; }
private:
	bool completed;
};
#endif