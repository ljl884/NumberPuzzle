//
//  MusicManager.hpp
//  NumberPuzzle
//
//  Created by Jin Wang on 8/08/2015.
//
//

#ifndef MusicManager_h
#define MusicManager_h

#include <SimpleAudioEngine.h>

class MusicManager {
public:
    
    static MusicManager& getInstance()
    {
        static MusicManager    instance; // Guaranteed to be destroyed.
        // Instantiated on first use.
        return instance;
    }
    
    void preload();
    void playBackgroundMusic();
    void pauseBackgroundMusic();
    void stopBackgroundMusic();
    void resumeBackgroundMusic();
    void playNumberMoveCompleteEffect();
    void playNumberMoveInCompleteEffect();
    void playLevelCompleteEffect();
    void playNumberFadeInEffect();
    void playButtonSelectionEffect();
    void setMute(bool value);
    void toggleMute();
    bool isMute();
    
private:
    MusicManager() {};
    
    // C++ 11
    // =======
    // We can use the better technique of deleting the methods
    // we don't want.
    MusicManager(MusicManager const&)      = delete;
    void operator=(MusicManager const&)    = delete;
    
    static CocosDenshion::SimpleAudioEngine *audioEngine;
    
    void playEffectIfNotMute(const char *effectName, float gain = 0.5f);
    
    bool isStarted = false;
};

#endif /* MusicManager_hpp */
