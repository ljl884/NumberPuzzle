#ifndef _LEVEL_SELECTION_SCENE_
#define _LEVEL_SELECTION_SCENE_

#include "cocos2d.h"
USING_NS_CC;

class LevelSelectionScene : public Layer
{
public:

	static Scene* createScene();

	virtual bool init();
	

	CREATE_FUNC(LevelSelectionScene);
	
	void onLevelNumberCallback(Ref* sender, int levelNumber);

};


#endif