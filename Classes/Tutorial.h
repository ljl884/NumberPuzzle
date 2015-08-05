#ifndef _TUTORIAL_
#define _TUTORIAL_

#include "cocos2d.h"

class Tutorial :public cocos2d::Layer {
public:
	//virtual bool init();	
	CREATE_FUNC(Tutorial);
	void TutorialOne();
	void TutorialTwo();
};

#endif