/*Written by Wentao Li*/
#include "MoveableNumber.h"
#include "Helper.h"

MoveableNumber::MoveableNumber(int value)
{
	if (value < 0)
		return;

	

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

