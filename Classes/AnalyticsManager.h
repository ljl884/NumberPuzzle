//
//  AnalyticsManager.hpp
//  NumberPuzzle
//
//  Created by Jin Wang on 9/08/2015.
//
//

#ifndef AnalyticsManager_h
#define AnalyticsManager_h

#include "cocos2d.h"

class AnalyticsManager {
public:
    
    static AnalyticsManager& getInstance()
    {
        static AnalyticsManager    instance; // Guaranteed to be destroyed.
        // Instantiated on first use.
        return instance;
    }
    
    void init();
    void startSession();
    void levelStarted(const std::string levelNumber);
    void levelEnded(const std::string levelNumber, bool completed);
    
private:
    AnalyticsManager() {};
    
    // C++ 11
    // =======
    // We can use the better technique of deleting the methods
    // we don't want.
    AnalyticsManager(AnalyticsManager const&)      = delete;
    void operator=(AnalyticsManager const&)    = delete;
};

#endif /* AnalyticsManager_h */
