//
//  MusicManager.cpp
//  NumberPuzzle
//
//  Created by Jin Wang on 8/08/2015.
//
//

#include "MusicManager.h"

using namespace CocosDenshion;

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
    audioEngine->setBackgroundMusicVolume(0.5f);
    audioEngine->setEffectsVolume(0.5F);
}

void MusicManager::playBackgroundMusic() {
    audioEngine->playBackgroundMusic(BACKGROUND_MUSIC, true);
}

void MusicManager::pauseBackgroundMusic() {
    audioEngine->pauseBackgroundMusic();
}

void MusicManager::stopBackgroundMusic() {
    audioEngine->stopBackgroundMusic();
}

void MusicManager::resumeBackgroundMusic() {
    audioEngine->resumeBackgroundMusic();
}

void MusicManager::playNumberMoveCompleteEffect() {
    audioEngine->playEffect(NUMBER_MOVE_COMPLETE_EFFECT);
}

void MusicManager::playNumberMoveInCompleteEffect() {
    audioEngine->playEffect(NUMBER_MOVE_INCOMPLETE_EFFECT);
}

void MusicManager::playLevelCompleteEffect() {
    audioEngine->playEffect(LEVEL_COMPLETE_EFFECT);
}

void MusicManager::playNumberFadeInEffect() {
    audioEngine->playEffect(NUMBER_FADE_IN_EFFECT);
}

void MusicManager::playButtonSelectionEffect() {
    audioEngine->playEffect(BUTTON_SELECTION_EFFECT);
}