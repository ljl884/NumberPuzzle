#include "Tutorial.h"
#include "Table.h"
#include "Constant.h"
void Tutorial::TutorialOne(){
	Sprite* pointer = Sprite::create("pointer.png");
	pointer->setRotation(45);
	pointer->setOpacity(0);
	this->addChild(pointer);
	pointer->setPosition(0-2*Constant::X_ALIGN+30, -30);
	pointer->runAction(Sequence::create(
		DelayTime::create(1.2),
		FadeIn::create(0.5),
		MoveBy::create(0.5, Point(Constant::X_ALIGN, 0)),
		MoveBy::create(0.5, Point(0, 0-Constant::Y_ALIGN)),
		MoveBy::create(0.5, Point(0- Constant::X_ALIGN, 0)),
		FadeOut::create(0.5),
		NULL));

	Sprite* pointer2 = Sprite::create("pointer.png");
	pointer2->setRotation(45);
	pointer2->setOpacity(0);
	this->addChild(pointer2);
	pointer2->setPosition(30-Constant::X_ALIGN,Constant::Y_ALIGN-30);
	pointer2->runAction(Sequence::create(
		DelayTime::create(3.5),
		FadeIn::create(0.5),
		MoveBy::create(1, Point(2* Constant::X_ALIGN, 0)),
		MoveBy::create(0.5, Point(0, -2* Constant::Y_ALIGN)),
		FadeOut::create(0.5),
		NULL));
}
void Tutorial::TutorialTwo(){
	Sprite* pointer = Sprite::create("pointer.png");
	pointer->setRotation(45);
	pointer->setOpacity(0);
	this->addChild(pointer);
	pointer->setPosition(30-Constant::X_ALIGN, Constant::Y_ALIGN-30);
	pointer->runAction(Sequence::create(
		DelayTime::create(1.2),
		FadeIn::create(0.5),
		MoveBy::create(0.5, Point(2* Constant::X_ALIGN, 0)),
	
		FadeOut::create(0.5),
		NULL));

	Sprite* pointer2 = Sprite::create("pointer.png");
	pointer2->setRotation(45);
	pointer2->setOpacity(0);
	this->addChild(pointer2);
	pointer2->setPosition(30, 2* Constant::Y_ALIGN-30);
	pointer2->runAction(Sequence::create(
		DelayTime::create(2.5),
		FadeIn::create(0.5),
		MoveBy::create(0.5, Point(0, -3 * Constant::Y_ALIGN)),
		FadeOut::create(0.5),
		NULL));
}