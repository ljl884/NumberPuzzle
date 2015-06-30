/*Written by Wentao Li*/
#include "Number.h"
#define APPEAR_ANIMATION_TIME 0.3


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
