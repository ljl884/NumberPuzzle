#ifndef _LEVEL_COMPLETE_LAYER_
#define _LEVEL_COMPLETE_LAYER_
#include "cocos2d.h"

USING_NS_CC;
class MainScene;
class LevelCompleteLayer :public Layer{
public:
	LevelCompleteLayer(MainScene* parent);
	void show();
	void hide();
private:
	MainScene* parent;
	Label* label;
	Sprite* background;
	Menu* menu;
	
};

#endif