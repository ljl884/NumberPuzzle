#ifndef _LEVEL_MANAGER_
#define _LEVEL_MANAGER_
#include "cocos2d.h"
#include "Table.h"
USING_NS_CC;
class MainScene;
class LevelManager{
public:
	LevelManager(MainScene * parent);
	void runLevel(int levelNumber);
	void resetLevel();
	void nextLevel();
	void lastLevel();
private:
	std::vector<std::string> levelInfo;
	MainScene* parent;
	Table* currentTable;
	int currentLevel;
	void initLevels();
	void createLevel(Table* table,std::string levelInfo);
};
#endif