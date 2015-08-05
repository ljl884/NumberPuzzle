/*Written by Wentao Li*/
#include "Number.h"

#define APPEAR_ANIMATION_TIME 0.3

USING_NS_CC;

Number::Number()
{
	this->setScale(SCALE);
	
}

void Number::playAppearAnimation(float Delay)
{
	this->setScale(0.01);
	this->runAction(Sequence::create(DelayTime::create(Delay), ScaleTo::create(APPEAR_ANIMATION_TIME, SCALE), NULL));
	
}
Size Number::getContainerSize(){
	return this->container->getContentSize();
}

bool Number::coverable()
{
	return false;
}
void Number::update()
{
	numberLabel->setString(Helper::int2str(this->value));
	numberLabel->runAction(Sequence::create(
		ScaleTo::create(0.1, 3), ScaleTo::create(0.1, 1), NULL));
}
