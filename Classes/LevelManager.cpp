#include "LevelManager.h"
#include "Helper.h"
#include "MainScene.h"
#include "Tutorial.h"
#include <iterator>

LevelManager* LevelManager::instance = nullptr;
LevelManager::LevelManager()
{
	parent = nullptr;
	currentTable = nullptr;
	currentLevel = 0;
	initLevels();
	initUserData();

		
}
void LevelManager::setParent(MainScene* parent){
	this->parent = parent;
}
void LevelManager::initLevels()
{
	levelInfo.push_back("9,-2,0#3,1,-1,0#3,1,-2,-1#3,1,-1,-1#8,-1,1#2,1,0,1#2,1,1,1#2,1,1,0#2,1,1,-1");
	levelInfo.push_back("2,-1,1#1,2,0,1#1,1,1,1#3,0,2#1,1,0,0#1,1,0,-1");
	levelInfo.push_back("2,-1,1#1,1,0,1#3,-1,0#1,3,0,0#2,2,1,0#3,1,2,0#7,-1,-1#1,1,0,-1");
	levelInfo.push_back("16,-2,2#3,1,-1,2#5,1,0,2#1,1,0,1#7,1,0,0#2,1,1,0#4,1,2,0#1,1,2,1#5,1,1,-1#12,3,1");
	levelInfo.push_back("1,1,0,2#11,-1,1#2,1,0,1#3,1,1,1#7,1,2,1#5,1,-1,0#3,1,0,0#4,1,1,0#20,2,0#6,1,1,-1");
	levelInfo.push_back("8,-2,0#1,1,-1,0#2,2,0,0#3,1,1,0#9,2,0#5,1,0,1#4,1,0,-1");
	levelInfo.push_back("1,1,1,2#4,1,-1,1#17,0,1#2,1,1,1#1,1,-1,0#5,1,0,0#4,1,1,0#9,1,2,0#15,-1,-1#2,1,0,-1#3,1,1,-1#1,1,2,-1");
	levelInfo.push_back("1,1,0,1#9,-1,0#2,2,0,0#3,1,1,0#5,-1,-1#2,1,0,-1#4,1,1,-1");
	levelInfo.push_back("1,1,0,2#1,1,1,2#1,1,2,2#1,1,-1,1#1,2,0,1#7,1,1#1,1,2,1#1,1,-1,0#7,0,0#1,2,1,0#1,1,2,0#1,1,-1,-1#1,1,0,-1#1,1,1,-1");
	levelInfo.push_back("13,0,2#2,1,-1,1#3,2,0,1#2,2,1,1#3,1,-1,0#10,0,0#3,1,1,0#2,1,-1,-1#1,1,0,-1#2,1,1,-1");
	levelInfo.push_back("10,0,1#3,1,1,1#30,-2,0#5,1,-1,0#7,1,0,0#4,2,1,0#5,1,2,0#3,1,-1,-1#1,2,0,-1#2,2,1,-1#3,1,2,-1");
	levelInfo.push_back("4,1,-1,1#2,1,0,1#1,1,1,1#8,1,-1,0#24,0,0#5,1,1,0#2,1,-1,-1#15,0,-1#3,1,1,-1#7,1,-1,-2#1,1,0,-2#6,1,1,-2");
	levelInfo.push_back("4, 3, 0, 0#3, 1, -1, 0#1, 1, -1, 1#5, 2, 0, 1#2, 2, 1, 0#3, 1, 0, -1#12, 1, -1#10, -2, 0#11, 0, 2");
	levelInfo.push_back("18,2,0#8,1,1,0#2,1,0,-1#5,3,0,0#16,0,1#1,3,-1,0#4,1,-1,1#3,2,-2,0#7,1,-2,1#11,-3,0");
	levelInfo.push_back("3,1,-1,1#11,0,1#15,1,1#2,1,2,1#4,1,-1,0#5,2,0,0#3,3,1,0#1,2,2,0#2,1,-1,-1#6,1,0,-1#3,1,1,-1#5,1,2,-1#1,1,-1,-2#27,0,-2#2,1,1,-2#4,1,2,-2");
	levelInfo.push_back("17,-2,1#4,1,-1,1#2,1,0,1#23,1,1#4,1,2,1#1,1,-2,0#2,2,-1,0#3,2,0,0#1,2,1,0#8,1,2,0#5,1,-2,-1#2,1,-1,-1#18,0,-1#4,1,1,-1#3,1,2,-1#3,1,-1,-2#7,1,0,-2#1,1,1,-2#2,1,2,-2");
	levelInfo.push_back("4,1,-1,0#5,2,0,0#8,2,1,0#28,2,0#26,-2,-1#2,2,-1,-1#3,2,0,-1#7,2,1,-1");
	levelInfo.push_back("4,1,-1,2#28,0,2#2,1,-1,1#3,1,0,1#1,1,1,1#7,2,-1,0#5,2,1,0#4,1,2,0#2,2,-1,-1#1,2,0,-1#3,3,1,-1#23,2,-1#22,-1,-2#6,2,0,-2#4,2,1,-2");
	levelInfo.push_back("2,1,-1,1#7,1,0,1#30,-2,0#1,2,-1,0#3,2,0,0#3,2,-2,-1#5,2,-1,-1#9,3,0,-1#21,1,-1#1,1,2,-1#4,1,-2,-2#23,-1,-2#2,2,0,-2#3,1,1,-2#2,1,2,-2");
	levelInfo.push_back("14,-2,0#4,2,-1,0#3,2,0,0#2,1,1,0#1,1,2,0#27,-2,-1#4,3,-1,-1#3,3,0,-1#2,1,1,-1#1,1,2,-1");
	levelInfo.push_back("2,1,0,2#17,-1,1#1,1,0,1#24,1,1#5,1,2,1#2,3,-1,0#7,3,0,0#2,2,1,0#1,1,2,0#1,3,-1,-1#4,3,0,-1#22,1,-1#3,1,0,-2#5,1,1,-2");
	levelInfo.push_back("5,1,-1,1#17,0,1#3,1,1,1#4,2,-1,0#-2,3,0,0#8,3,1,0#-4,1,2,0#18,-1,-1#7,2,0,-1#1,2,1,-1#11,2,-1");
	levelInfo.push_back("4,2,-2,1#9,2,-1,1#7,3,0,1#46,1,1#6,2,-2,0#40,-1,0#3,2,0,0#1,2,1,0#8,1,-2,-1#2,1,-1,-1#5,1,0,-1#4,1,1,-1");
	levelInfo.push_back("9,0,1#2,3,1,1#1,3,2,1#11,-1,0#1,3,0,0#-1,4,1,0#4,3,2,0#7,1,-1,-1#2,2,0,-1#5,1,1,-1#16,2,-1");
	levelInfo.push_back("4,2,-1,2#1,1,0,2#3,2,1,2#4,1,2,2#1,1,-1,1#16,0,1#3,2,1,1#2,2,2,1#3,2,-1,0#26,0,0#22,1,0#2,2,2,0#4,2,-1,-1#2,2,0,-1#2,2,1,-1#4,2,2,-1");
	levelInfo.push_back("3,1,-2,1#5,1,-1,1#1,2,0,1#2,2,1,1#8,1,2,1#1,1,-2,0#34,-1,0#4,3,0,0#3,2,1,0#7,2,2,0#2,1,-2,-1#5,2,-1,-1#3,3,0,-1#20,1,-1#22,2,-1");
	levelInfo.push_back("5,1,-3,2#42,-2,2#9,2,-1,2#3,2,0,2#4,1,1,2#7,1,2,2#3,1,-3,1#4,2,-2,1#7,2,-1,1#2,2,0,1#33,1,1#3,1,2,1#2,1,-2,0#25,-1,0#4,2,0,0#5,1,1,0#2,1,2,0#5,1,-2,-1#6,1,-1,-1#1,1,0,-1");
	levelInfo.push_back("4,2,-2,1#1,2,-1,1#9,2,0,1#1,2,1,1#7,2,2,1#3,2,-2,0#44,-1,0#35,0,0#25,1,0#2,2,2,0#8,2,-2,-1#2,2,-1,-1#5,2,0,-1#6,2,1,-1#4,2,2,-1");
	levelInfo.push_back("8,-1,1#1,2,0,1#2,2,1,1#9,-2,0#5,1,-1,0#3,3,0,0#1,3,1,0#4,2,-2,-1#2,3,-1,-1#-2,4,0,-1#12,1,-1#14,-1,-2#4,3,0,-2#1,2,1,-2");
	levelInfo.push_back("16,-2,2#2,2,-1,2#2,1,1,2#3,1,2,2#2,1,-2,1#4,3,-1,1#-3,2,0,1#1,2,1,1#5,1,2,1#5,1,-2,0#1,2,-1,0#-4,2,0,0#2,2,1,0#14,2,0#3,1,-2,-1#2,1,-1,-1#6,0,-1#1,1,1,-1#3,1,2,-1");
	levelInfo.push_back("4,1,-3,1#1,2,-2,1#2,2,-1,1#17,0,1#2,2,1,1#1,3,2,1#4,1,3,1#10,-3,0#1,2,-2,0#2,3,-1,0#3,2,0,0#2,3,1,0#1,2,2,0#16,3,0");
	levelInfo.push_back("6,0,2#1,1,1,2#1,2,-1,1#1,3,0,1#1,2,1,1#1,1,2,1#11,-2,0#1,2,-1,0#1,2,0,0#4,1,0#1,3,2,0#1,2,3,0#1,2,-1,-1#1,3,0,-1#1,3,1,-1#1,2,2,-1#8,0,-2#1,1,1,-2");
	levelInfo.push_back("1,1,-2,1#2,2,-1,1#11,0,1#1,1,1,1#1,1,2,1#1,1,-3,0#13,-2,0#2,2,-1,0#2,2,0,0#2,2,1,0#2,2,2,0#1,1,-3,-1#2,2,-2,-1#3,3,-1,-1#2,2,0,-1#19,1,-1#1,1,2,-1");
	levelInfo.push_back("12,1,1#4,1,2,1#8,1,3,1#25,-2,0#3,2,-1,0#4,2,0,0#-3,3,1,0#5,3,2,0#2,1,3,0#1,2,-2,-1#2,3,-1,-1#1,2,0,-1#2,3,1,-1#4,3,2,-1#15,3,-1#3,1,-1,-2#5,1,0,-2#18,1,-2");
	levelInfo.push_back("38,-1,1#31,0,1#5,2,1,1#28,2,1#9,2,-1,0#8,3,0,0#6,4,1,0#3,2,2,0#2,2,-1,-1#7,2,0,-1#4,3,1,-1#8,2,2,-1#43,-1,-2#3,2,0,-2#2,3,1,-2");
	levelInfo.push_back("25,-1,1#7,2,0,1#4,2,1,1#5,2,-1,0#3,4,0,0#2,3,1,0#17,-1,-1#1,2,0,-1#10,1,-1");
	levelInfo.push_back("3,1,0,1#28,-1,0#5,3,0,0#16,1,0#4,2,-1,-1#7,4,0,-1#3,3,1,-1#2,1,2,-1#1,1,-1,-2#8,2,0,-2#38,1,-2");
	levelInfo.push_back("22,-2,1#1,4,-1,1#2,4,0,1#3,2,1,1#18,2,1#15,-2,0#4,4,-1,0#5,4,0,0#6,2,1,0#11,2,0");
	levelInfo.push_back("5,1,-2,1#8,2,-1,1#20,0,1#3,3,1,1#4,2,2,1#48,-2,0#4,4,-1,0#1,3,0,0#7,4,1,0#16,2,0#1,2,-2,-1#3,3,-1,-1#17,0,-1#2,2,1,-1#1,1,2,-1");
	levelInfo.push_back("20,-3,2#2,2,-2,2#1,1,-1,2#8,1,1,2#27,2,2#1,1,-3,1#3,2,-2,1#4,4,-1,1#26,0,1#9,2,1,1,#3,3,2,1#4,2,3,1#5,4,-1,0#2,4,0,0#1,2,1,0#7,2,2,0#28,3,0#4,1,-2,-1#5,2,-1,-1#3,2,0,-1#34,-2,-2");
	levelInfo.push_back("2,3,-1,1#1,3,0,1#16,1,1#15,-2,0#3,3,-1,0#4,4,0,0#2,1,1,0#1,2,-1,-1#2,3,0,-1#13,0,-2");
	levelInfo.push_back("36,-1,1#7,2,0,1#1,4,-1,0#5,3,0,0#2,4,-1,-1#3,4,0,-1#1,4,1,-1#9,1,2,-1#25,-1,-2#4,2,0,-2#2,3,1,-2#19,2,-2");
	levelInfo.push_back("12,0,1#3,2,1,1#1,2,2,1#19,-1,0#-5,4,0,0#7,4,1,0#4,3,2,0#8,1,-1,-1#-3,4,0,-1#2,3,1,-1#3,2,2,-1#4,2,0,-2#13,1,-2");
	levelInfo.push_back("4,1,-1,1#1,2,0,1#20,1,1#4,1,2,1#5,1,-2,0#30,-1,0#2,3,0,0#3,4,1,0#1,2,2,0#5,1,-2,-1#1,2,-1,-1#2,3,0,-1#3,4,1,-1#4,1,-1,-2#16,0,-2#1,2,1,-2");
	levelInfo.push_back("1,1,-2,1#25,-1,1#1,2,0,1#14,1,1#1,1,2,1#3,2,-2,0#2,2,-1,0#1,4,0,0#2,3,1,0#3,3,2,0#3,2,-2,-1#2,3,-1,-1#1,4,0,-1#2,3,1,-1#3,3,2,-1#1,1,-2,-2#12,-1,-2#1,1,0,-2#16,1,-2#1,1,2,-2");
}
void LevelManager::initUserData(){
	levelCompleted.clear();
	UserDefault* userData = UserDefault::sharedUserDefault();
	for (int i = 0; i < levelInfo.size(); i++){
		bool Completed  = userData->getBoolForKey(Helper::int2str(i).c_str(), false);
		levelCompleted[i] = Completed;
	}
}
bool LevelManager::isLevelCompleted(int levelNumber)
{
	if (levelNumber < 0 || levelNumber >= levelCompleted.size())
		return false;
	else{
		
		return levelCompleted[levelNumber];
	}
		

}
void LevelManager::completeCurrentLevel(){
	bool currentLevelCompleted = isLevelCompleted(currentLevel);
	if (currentLevelCompleted == false)
	{
		levelCompleted[currentLevel] = true;
		UserDefault::sharedUserDefault()->setBoolForKey(Helper::int2str(currentLevel).c_str(), true);
	}
}
void LevelManager::resetUserData(){
	levelCompleted.clear();
	UserDefault* userData = UserDefault::sharedUserDefault();
	for (int i = 0; i < levelInfo.size(); i++){
		userData->setBoolForKey(Helper::int2str(i).c_str(), false);
		levelCompleted[i] = false;
	}
}
void LevelManager::runLevel(int levelNumber)
{
	if (parent == nullptr)
		return;
	if (levelNumber >= levelInfo.size() || levelNumber < 0)
		return; 

	else{
		if (currentTable != nullptr)
		{
			parent->removeChild(currentTable);
		}
		Table* table = new Table(parent);
		parent->addChild(table);
		table->setPosition(480, 320);
		createLevel(table, levelInfo.at(levelNumber));
		currentLevel = levelNumber;
		currentTable = table;
		parent->setLevelNumber(currentLevel + 1);
		if (levelNumber == 0)
		{
			Tutorial* tutorial = Tutorial::create();
			table->addChild(tutorial);
			tutorial->setZOrder(5);
			tutorial->TutorialOne();
		}
		else if (levelNumber == 1)
		{
			Tutorial* tutorial = Tutorial::create();
			table->addChild(tutorial);
			tutorial->setZOrder(5);
			tutorial->TutorialTwo();
		}
	}
	
}
void LevelManager::resetLevel()
{
	if (parent == nullptr)
		return;
	runLevel(currentLevel);
}
void LevelManager::nextLevel()
{	
	if (parent == nullptr)
		return;
	runLevel(currentLevel+1);
}
void LevelManager::lastLevel()
{
	if (parent == nullptr)
		return;
	runLevel(currentLevel -1);
}
void LevelManager::undo(){
	currentTable->undo();
}
void LevelManager::createLevel(Table* table,std::string levelInfo)
{
	std::vector<std::string> strings;
	std::list<std::string> splitedWords;
	Helper::split(levelInfo, "#", strings); //split text in script by "#"
	std::copy(strings.begin(), strings.end(), std::back_inserter(splitedWords)); //copy the vector to the list container
	for (std::string numberString : strings){
		std::vector<std::string> numbers;
		Helper::split(numberString, ",", numbers);
		if (numbers.size() == 3){
			table->addMoveableNumber(atoi(numbers.at(0).c_str()), 
				ccp(atoi(numbers.at(1).c_str()), atoi(numbers.at(2).c_str())));
		}
		else if (numbers.size() == 4){
			table->addStaticNumber(atoi(numbers.at(0).c_str()), atoi(numbers.at(1).c_str()),
				ccp(atoi(numbers.at(2).c_str()), atoi(numbers.at(3).c_str())));
		}
	}
}