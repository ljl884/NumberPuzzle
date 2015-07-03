/*Written by Wentao Li*/
#ifndef _STATIC_NUMBER_
#define _STATIC_NUMBER_
#include "cocos2d.h"
#include "Number.h"
USING_NS_CC;
class StaticNumber :public Number{
public:
	StaticNumber(int value,int level);
	void decreaseLevel();
	virtual bool coverable();
	virtual void update();
private:
	void setContainer(int level);
};
#endif