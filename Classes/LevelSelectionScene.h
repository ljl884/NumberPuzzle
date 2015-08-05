#ifndef _LEVEL_SELECTION_SCENE_
#define _LEVEL_SELECTION_SCENE_

#include "cocos2d.h"

USING_NS_CC;

class LevelSelectionScene : public Layer
{
public:
    
    static Scene* createScene();
    static Scene* createScene(int pageNumber);
    static int currentPageNumber;
    
    virtual bool init(int pageNumber);
    
    static LevelSelectionScene* create(int pageNumber);
    
    void setPageNumber(int pageNumber);
    void onNextPageCallback(Ref* sender);
    void onLastPageCallback(Ref* sender);
    void onLevelNumberCallback(Ref* sender, int levelNumber);
    void resetProgressCallback(Ref* sender);
private:
    int pageNumber;
    int maximumPageNumber;
};


#endif