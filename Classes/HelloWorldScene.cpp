#include "HelloWorldScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "StaticNumber.h"
#include "MoveableNumber.h"
#include "Table.h"
USING_NS_CC;

using namespace cocostudio::timeline;

Scene* HelloWorld::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = HelloWorld::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Layer::init() )
    {
        return false;
    }
    
    auto rootNode = CSLoader::createNode("MainScene.csb");

    addChild(rootNode);
	this->setTouchEnabled(true);

	Table* table = new Table(this);
	this->addChild(table);
	table->setPosition(400, 300);
	table->addStaticNumber(4, 2, ccp(0, 0));
	table->addStaticNumber(3, 1, ccp(-1, 0));
	table->addMoveableNumber(10, ccp(-2, 0));
	table->addStaticNumber(1, 1, ccp(-1, 1));
	table->addStaticNumber(5, 2, ccp(0, 1));
	table->addMoveableNumber(11, ccp(0, 2));
	table->addStaticNumber(2, 2, ccp(1, 0));
	table->addStaticNumber(3, 1, ccp(0, -1));
	table->addMoveableNumber(12, ccp(1, -1));


	//MoveableNumber * number_0 = new MoveableNumber(10);
	//this->addChild(number_0);
	//number_0->setPosition(300, 300);
	//number_0->playAppearAnimation(0.7);

	//StaticNumber * number_1 = new StaticNumber(3, 1);
	//this->addChild(number_1);
	//number_1->setPosition(400, 300);
	//number_1->playAppearAnimation(1);

	//StaticNumber * number_2 = new StaticNumber(4, 3);
	//this->addChild(number_2);
	//number_2->setPosition(500, 300);
	//number_2->playAppearAnimation(1.3);

	//StaticNumber * number_3 = new StaticNumber(2, 2);
	//this->addChild(number_3);
	//number_3->setPosition(600, 300);
	//number_3->playAppearAnimation(1.3);

	//StaticNumber * number_4 = new StaticNumber(3, 1);
	//this->addChild(number_4);
	//number_4->setPosition(500, 200);
	//number_4->playAppearAnimation(1.2);

	//MoveableNumber * number_5 = new MoveableNumber(12);
	//this->addChild(number_5);
	//number_5->setPosition(600, 200);
	//number_5->playAppearAnimation(0.6);

	//StaticNumber * number_6 = new StaticNumber(5, 2);
	//this->addChild(number_6);
	//number_6->setPosition(500, 400);
	//number_6->playAppearAnimation(1.29);

	//StaticNumber * number_7 = new StaticNumber(1,1);
	//this->addChild(number_7);
	//number_7->setPosition(400, 400);
	//number_7->playAppearAnimation(1.22);

	//MoveableNumber * number_8 = new MoveableNumber(11);
	//this->addChild(number_8);
	//number_8->setPosition(500, 500);
	//number_8->playAppearAnimation(0.75);
	

    return true;
}
