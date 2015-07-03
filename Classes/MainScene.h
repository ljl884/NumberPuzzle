#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "LevelManager.h"

class MainScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
	CREATE_FUNC(MainScene);

	void resetLevelCallback(Ref* sender);
	void nextLevelCallback(Ref* sender);
	void backLevelCallback(Ref* sender);
	void onLevelComplete();
	void setLevelNumber(int levelNumber);
private:
	LevelManager* levelManager;
	Label* levelNumberLabel;
};

#endif // __HELLOWORLD_SCENE_H__
