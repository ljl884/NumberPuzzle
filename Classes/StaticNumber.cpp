/*Written by Wentao Li*/
#include "StaticNumber.h"


StaticNumber::StaticNumber(int value, int level)
{
	if ( level == 0 || level>MAX_LEVEL)
		return;
	this->level = level;
	this->value = value;

	//Init Container
	container = Sprite::create();
	setContainer(this->level);
	this->addChild(container);

	//Init number label
	this->numberLabel = Label::create(Helper::int2str(value), "Marker Felt.ttf", 35);
	numberLabel->setPosition(0, 0);
	this->addChild(numberLabel);


}
void StaticNumber::setContainer(int level)
{
	switch (level)
	{
	case 1:
		this->container->setTexture("frame_1@2x.png");
		break;
	case 2:
		this->container->setTexture("frame_2@2x.png");
		break;
	case 3:
		this->container->setTexture("frame_3@2x.png");
		break;
	case 4:
		this->container->setTexture("frame_4@2x.png");
	default:
		break;
	}
}
void StaticNumber::decreaseLevel()
{
	if (level == 0)
		return;
	else
		level--;
}
void StaticNumber::increaseLevel()
{
	level++;
}
bool StaticNumber::coverable()
{
	if (level == 0)
		return false;
	else
		return true;
}
void StaticNumber::update()
{
	setContainer(this->level);
	if (level == 0)
	{
		container->runAction(FadeOut::create(0.7));
		numberLabel->runAction(FadeOut::create(0.7));
	}
	else{
		container->runAction(FadeIn::create(0.7));
		numberLabel->runAction(FadeIn::create(0.7));
	}
		
}