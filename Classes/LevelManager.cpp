#include "LevelManager.h"
#include "Common.h"
#include "MainScene.h"
#include <iterator>

using namespace std;

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
    
    // Here, we need to read the level information from a file. This might be platform specific.
    
    // Initialize variables needed
    std::string fileContents;
    std::string levelFilePath, extraLevelFilePath;
    
    // Get absolute path of file
    levelFilePath = FileUtils::getInstance()->fullPathForFilename("level_info.txt");
    extraLevelFilePath = FileUtils::getInstance()->fullPathForFilename("extra_level_info.txt");
    
    // Read the file content as string.
    fileContents = FileUtils::getInstance()->getStringFromFile(levelFilePath);
    
    if (!extraLevelFilePath.empty()) {
        // Don't forget to append a break line first!!!
        fileContents.append("\n");
        fileContents.append(FileUtils::getInstance()->getStringFromFile(extraLevelFilePath));
    }
    
    Helper::split(fileContents, "\n", levelInfo);
    
}
void LevelManager::initUserData(){
    levelCompleted.clear();
    UserDefault* userData = UserDefault::getInstance();
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
        UserDefault::getInstance()->setBoolForKey(Helper::int2str(currentLevel).c_str(), true);
    }
}
void LevelManager::resetUserData(){
    levelCompleted.clear();
    UserDefault* userData = UserDefault::getInstance();
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
    vector<string> strings;
    list<string> splitedWords;
    Helper::split(levelInfo, "#", strings); //split text in script by "#"
    copy(strings.begin(), strings.end(), back_inserter(splitedWords)); //copy the vector to the list container
    for (string numberString : strings){
        vector<string> numbers;
        Helper::split(numberString, ",", numbers);
        if (numbers.size() == 3){
            table->addMoveableNumber(atoi(numbers.at(0).c_str()),
                                     Point(atoi(numbers.at(1).c_str()), atoi(numbers.at(2).c_str())));
        }
        else if (numbers.size() == 4){
            table->addStaticNumber(atoi(numbers.at(0).c_str()), atoi(numbers.at(1).c_str()),
                                   Point(atoi(numbers.at(2).c_str()), atoi(numbers.at(3).c_str())));
        }
    }
}