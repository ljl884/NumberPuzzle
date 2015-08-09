//
//  MusicManager.cpp
//  NumberPuzzle
//
//  Created by Jin Wang on 8/08/2015.
//
//

#include "MusicManager.h"

using namespace CocosDenshion;
USING_NS_CC;

#define SOUND_ENABLE_KEY "sound_enable"

#if (CC_TARGET_PLATFORM == CC_PLATFORM_BLACKBERRY || CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
    #define NUMBER_MOVE_INCOMPLETE_EFFECT "number_move_incomplete.ogg"
    #define NUMBER_MOVE_COMPLETE_EFFECT "number_move_complete.ogg"
    #define LEVEL_COMPLETE_EFFECT "level_complete.ogg"
    #define BUTTON_SELECTION_EFFECT "button_selection.ogg"
    #define NUMBER_FADE_IN_EFFECT "number_fade_in.ogg"
#else
    #define NUMBER_MOVE_INCOMPLETE_EFFECT "number_move_incomplete.mp3"
    #define NUMBER_MOVE_COMPLETE_EFFECT "number_move_complete.mp3"
    #define LEVEL_COMPLETE_EFFECT "level_complete.mp3"
    #define BUTTON_SELECTION_EFFECT "button_selection.mp3"
    #define NUMBER_FADE_IN_EFFECT "number_fade_in.mp3"
#endif

#define BACKGROUND_MUSIC "background.mp3"

SimpleAudioEngine *MusicManager::audioEngine = SimpleAudioEngine::getInstance();

void MusicManager::preload() {
    audioEngine->preloadBackgroundMusic(BACKGROUND_MUSIC);
    audioEngine->preloadEffect(NUMBER_MOVE_COMPLETE_EFFECT);
    audioEngine->preloadEffect(NUMBER_MOVE_INCOMPLETE_EFFECT);
    audioEngine->preloadEffect(NUMBER_FADE_IN_EFFECT);
    audioEngine->preloadEffect(LEVEL_COMPLETE_EFFECT);
    audioEngine->preloadEffect(BUTTON_SELECTION_EFFECT);
    audioEngine->setBackgroundMusicVolume(1.0f);
    audioEngine->setEffectsVolume(1.0F);
}

void MusicManager::playBackgroundMusic() {
    if (UserDefault::getInstance()->getBoolForKey(SOUND_ENABLE_KEY, true)) {
        audioEngine->playBackgroundMusic(BACKGROUND_MUSIC, true);
        isStarted = true;
    }
}

void MusicManager::pauseBackgroundMusic() {
    if (audioEngine->isBackgroundMusicPlaying()) {
        audioEngine->pauseBackgroundMusic();
    }
}

void MusicManager::resumeBackgroundMusic() {
    if (UserDefault::getInstance()->getBoolForKey(SOUND_ENABLE_KEY, true)) {
        // On simulator, this works but on iPhone device, it doesn't
        #if CC_TARGET_PLATFORM == CC_PLATFORM_IOS
            audioEngine->playBackgroundMusic(BACKGROUND_MUSIC);
        #else
            audioEngine->resumeBackgroundMusic();
        #endif
    }
}

void MusicManager::stopBackgroundMusic() {
    if (audioEngine->isBackgroundMusicPlaying()) {
        audioEngine->stopBackgroundMusic();
    }
}

void MusicManager::playNumberMoveCompleteEffect() {
    playEffectIfNotMute(NUMBER_MOVE_COMPLETE_EFFECT);
}

void MusicManager::playNumberMoveInCompleteEffect() {
    playEffectIfNotMute(NUMBER_MOVE_INCOMPLETE_EFFECT);
}

void MusicManager::playLevelCompleteEffect() {
    playEffectIfNotMute(LEVEL_COMPLETE_EFFECT);
}

void MusicManager::playNumberFadeInEffect() {
    playEffectIfNotMute(NUMBER_FADE_IN_EFFECT, 1.0f);
}

void MusicManager::playButtonSelectionEffect() {
    playEffectIfNotMute(BUTTON_SELECTION_EFFECT);
}

void MusicManager::playEffectIfNotMute(const char *effectName, float gain) {
    if (audioEngine->isBackgroundMusicPlaying()) {
        audioEngine->playEffect(effectName, false, 1.0f, 0.0f, gain);
    }
}

void MusicManager::setMute(bool value) {
    // Note, we need to store the sound preference inside user defaults.
    UserDefault::getInstance()->setBoolForKey(SOUND_ENABLE_KEY, !value);
    
    if (value && isStarted) {
        pauseBackgroundMusic();
    } else {
        if (isStarted) {
            resumeBackgroundMusic();
        } else {
            playBackgroundMusic();
        }
    }
}

bool MusicManager::isMute() {
    return !UserDefault::getInstance()->getBoolForKey(SOUND_ENABLE_KEY, true);
}

void MusicManager::toggleMute() {
    setMute(audioEngine->isBackgroundMusicPlaying());
}