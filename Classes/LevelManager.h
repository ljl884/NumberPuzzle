#ifndef _LEVEL_MANAGER_
#define _LEVEL_MANAGER_
#include "cocos2d.h"
#include "Table.h"
USING_NS_CC;
class MainScene;
class LevelManager{
public:
	
	static LevelManager* getInstance(){
		if (instance == nullptr)
			instance = new LevelManager();
		return instance;
	}
    
    // The inline method provides a level count information.
	inline int levelCount() { return int(levelInfo.size()); }
    
	void undo();
	void setParent(MainScene * parent);
	void runLevel(int levelNumber);
	void completeCurrentLevel();
	void resetLevel();
	void nextLevel();
	void lastLevel();
	bool isLevelCompleted(int levelNumber);
	void resetUserData();
private:
	static LevelManager* instance;
	LevelManager();
	std::vector<std::string> levelInfo;
	std::map<int,bool> levelCompleted;
	MainScene* parent;
	Table* currentTable;
	int currentLevel;
	void initLevels();
	void initUserData(); //init levelCompleted vector
	void createLevel(Table* table,std::string levelInfo);
};
#endif