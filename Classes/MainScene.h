#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"

class LevelManager;
class LevelCompleteLayer;
class CoverLayer;

#define DEBUG false

class MainScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene(int levelNumber);

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
	CREATE_FUNC(MainScene);
	void playLevel(int levelNumber);
	void resetLevelCallback(Ref* sender);
	void nextLevelCallback(Ref* sender);
	void backLevelCallback(Ref* sender);
	void selectLevelCallback(Ref* sender);
	void undoCallback(Ref* sender);
    void musicCallback(Ref* sender);
	void onLevelComplete();
	void setLevelNumber(int levelNumber);
private:
	LevelManager* levelManager;
	LevelCompleteLayer* levelCompleteLayer;
    CoverLayer* levelCompleteMask;
	cocos2d::Label* levelNumberLabel;
    cocos2d::MenuItemToggle *musicItem;
};

#endif // __HELLOWORLD_SCENE_H__
