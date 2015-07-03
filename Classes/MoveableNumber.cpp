/*Written by Wentao Li*/
#include "MoveableNumber.h"
#include "Helper.h"

MoveableNumber::MoveableNumber(int value)
{
	
	this->value = value;
	

	//Init Container
	
	this->container = Sprite::create("level_incomplete_default@2x.png");
	this->addChild(container);
	this->highlightedContainer = Sprite::create("level_complete_default@2x.png");
	this->addChild(highlightedContainer);
	this->highlightedContainer->setVisible(false);
	this->highlighted = false;

	//Init number label
	this->numberLabel = Label::create(Helper::int2str(value), "Marker Felt.ttf", 35);
	numberLabel->setPosition(0,0);
	this->addChild(numberLabel);

	this->finished = false;
	

}
void MoveableNumber::setHighlight(bool highlight){
	this->highlightedContainer->setVisible(highlight);
	this->highlighted = highlight;
}

bool MoveableNumber::coverable()
{
	return false;
}
void MoveableNumber::update()
{
	Number::update();
	if (this->value < 0)
	{
		//this->addChild(Sprite::create("frame_0_wrong@2x.png"));
		container->setTexture("frame_0_wrong@2x.png");
	}
	if (this->value > 0)
	{
		container->setTexture("level_incomplete_default@2x.png");
	}
	if (this->value == 0)
	{
		finished = true;
		this->addChild(Sprite::create("frame_0_completed@2x.png"));
	}
}