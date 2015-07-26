/*Written by Wentao Li*/
#include "LevelNumber.h"

LevelNumber::LevelNumber(int value, bool completed){
	this->completed = completed;
	this->value = value;
	if (completed){
		container = Sprite::create("level_complete_default.png");
		
	}
	else{
		container = Sprite::create("level_incomplete_default.png");
	}
	this->addChild(container);

	this->numberLabel = Label::create(Helper::int2str(value), "Marker Felt.ttf", 20);
	this->addChild(numberLabel);
}