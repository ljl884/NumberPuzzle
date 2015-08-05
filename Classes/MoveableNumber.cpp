/*Written by Wentao Li*/
#include "MoveableNumber.h"
#include "Common.h"

MoveableNumber::MoveableNumber(int value)
{
	
	this->value = value;
    
	//Init Container
	
	this->container = Sprite::create("level_incomplete_default.png");
	this->addChild(container);
	this->highlightedContainer = Sprite::create("level_complete_default.png");
	this->addChild(highlightedContainer);
	this->highlightedContainer->setVisible(false);
	this->highlighted = false;

	this->finishContainer = Sprite::create("frame_0_completed.png");
	this->finishContainer->setZOrder(4);
	this->addChild(finishContainer);
	this->finishContainer->setVisible(false);
	this->finished = false;

	//Init number label
	this->numberLabel = Label::createWithTTF(FontManager::getInstance().levelNumberLabelFontConfig(), Helper::int2str(value));
	numberLabel->setPosition(0,0);
	this->addChild(numberLabel);

	
	
    Helper::scaleSpriteAndChildren(this);
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
		finished = false;
		finishContainer->setVisible(false);
		container->setTexture("frame_0_wrong.png");
	}
	if (this->value > 0)
	{
		finished = false;
		finishContainer->setVisible(false);
		container->setTexture("level_incomplete_default.png");
	}
	if (this->value == 0)
	{
		finished = true;
		finishContainer->setVisible(true);
	}
}