/*Written by Wentao Li*/
#include "StaticNumber.h"
#include "Helper.h"

StaticNumber::StaticNumber(int value, int level)
{
	if (value < 0 || level == 0 || level>MAX_LEVEL)
		return;


	//Init Container
	switch (level)
	{
	case 1:
		this->container = Sprite::create("frame_1@2x.png");
		break;
	case 2:
		this->container = Sprite::create("frame_2@2x.png");
		break;
	case 3:
		this->container = Sprite::create("frame_3@2x.png");
		break;
	default:
		break;
	}
	this->addChild(container);

	//Init number label
	this->numberLabel = Label::create(Helper::int2str(value), "Marker Felt.ttf", 35);
	numberLabel->setPosition(0, 0);
	this->addChild(numberLabel);


}