//
//  AnalyticsManager.cpp
//  NumberPuzzle
//
//  Created by Jin Wang on 9/08/2015.
//
//

#include "AnalyticsManager.h"
#include <time.h>

#define LEVEL_TIME_SPEND_EVENT_NAME "level_time_spend"
#define LEVEL_NUMBER_KEY "level_number"
#define LEVEL_COMPLETE_KEY "level_complete"

#if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
    #include "PluginFlurryAnalytics/PluginFlurryAnalytics.h"

    void AnalyticsManager::init() {
        sdkbox::PluginFlurryAnalytics::init();
    }

    void AnalyticsManager::startSession() {
        // Start session
        sdkbox::PluginFlurryAnalytics::setSessionContinueSeconds(10.0f);
        sdkbox::PluginFlurryAnalytics::startSession();
        
        // We'll send the report everytime the user move the session to background.
        sdkbox::PluginFlurryAnalytics::setSessionReportsOnPauseEnabled(true);
        sdkbox::PluginFlurryAnalytics::setSessionReportsOnCloseEnabled(true);
    }

    void AnalyticsManager::levelEnded(const std::string levelNumber, bool completed) {
        std::map<std::string, std::string> logParameters;
        
        logParameters[LEVEL_NUMBER_KEY] = levelNumber;
        logParameters[LEVEL_COMPLETE_KEY] = completed ? "Yes" : "No";
        
        sdkbox::PluginFlurryAnalytics::endTimedEvent(LEVEL_TIME_SPEND_EVENT_NAME, logParameters);
    }

    void AnalyticsManager::levelStarted(const std::string levelNumber) {
        
        std::map<std::string, std::string> logParameters;
        
        // End any unended time event first. This will not be effective if
        // the timed event has been ended before.
        sdkbox::PluginFlurryAnalytics::endTimedEvent(LEVEL_TIME_SPEND_EVENT_NAME, logParameters);
        
        logParameters[LEVEL_NUMBER_KEY] = levelNumber;
        logParameters[LEVEL_COMPLETE_KEY] = "No";
        
        sdkbox::PluginFlurryAnalytics::logEvent(LEVEL_TIME_SPEND_EVENT_NAME, logParameters, true);
    }

#elif CC_TARGET_PLATFORM == CC_PLATFORM_ANDROID
    void AnalyticsManager::init() {}
    void AnalyticsManager::startSession() {}
    void AnalyticsManager::levelStarted(const std::string levelNumber) {}
    void AnalyticsManager::levelEnded(const std::string levelNumber, bool completed) {}
#else
    void AnalyticsManager::init() {}
    void AnalyticsManager::startSession() {}
    void AnalyticsManager::levelStarted(const std::string levelNumber) {}
    void AnalyticsManager::levelEnded(const std::string levelNumber, bool completed) {}
#endif