#ifndef _TUTORIAL_
#define _TUTORIAL_

#include "cocos2d.h"
USING_NS_CC;
class Tutorial :public Layer{
public:
	//virtual bool init();	
	CREATE_FUNC(Tutorial);
	void TutorialOne();
	void TutorialTwo();
};

#endif