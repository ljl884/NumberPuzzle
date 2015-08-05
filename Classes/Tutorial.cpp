#include "Tutorial.h"
#include "Table.h"
void Tutorial::TutorialOne(){
	Sprite* pointer = Sprite::create("pointer.png");
	pointer->setRotation(45);
	pointer->setOpacity(0);
	this->addChild(pointer);
	pointer->setPosition(-170, -30);
	pointer->runAction(Sequence::create(
		DelayTime::create(1.2),
		FadeIn::create(0.5),
		MoveBy::create(0.5, Point(X_ALIGN, 0)),
		MoveBy::create(0.5, Point(0, -Y_ALIGN)),
		MoveBy::create(0.5, Point(-X_ALIGN, 0)),
		FadeOut::create(0.5),
		NULL));

	Sprite* pointer2 = Sprite::create("pointer.png");
	pointer2->setRotation(45);
	pointer2->setOpacity(0);
	this->addChild(pointer2);
	pointer2->setPosition(-70, 70);
	pointer2->runAction(Sequence::create(
		DelayTime::create(3.5),
		FadeIn::create(0.5),
		MoveBy::create(1, Point(2*X_ALIGN, 0)),
		MoveBy::create(0.5, Point(0, -2*Y_ALIGN)),
		FadeOut::create(0.5),
		NULL));
}
void Tutorial::TutorialTwo(){
	Sprite* pointer = Sprite::create("pointer.png");
	pointer->setRotation(45);
	pointer->setOpacity(0);
	this->addChild(pointer);
	pointer->setPosition(-70, 70);
	pointer->runAction(Sequence::create(
		DelayTime::create(1.2),
		FadeIn::create(0.5),
		MoveBy::create(0.5, Point(2*X_ALIGN, 0)),
	
		FadeOut::create(0.5),
		NULL));

	Sprite* pointer2 = Sprite::create("pointer.png");
	pointer2->setRotation(45);
	pointer2->setOpacity(0);
	this->addChild(pointer2);
	pointer2->setPosition(30, 170);
	pointer2->runAction(Sequence::create(
		DelayTime::create(2.5),
		FadeIn::create(0.5),
		MoveBy::create(0.5, Point(0, -3 * Y_ALIGN)),
		FadeOut::create(0.5),
		NULL));
}