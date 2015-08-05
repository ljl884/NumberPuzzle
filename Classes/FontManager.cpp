//
//  FontManager.cpp
//  NumberPuzzle
//
//  Created by Jin Wang on 5/08/2015.
//
//

#include "FontManager.h"

TTFConfig FontManager::fontConfig(const char *name, int size) {
    
    // Initialize a new TTFConfig struct
    TTFConfig config;
    
    config.fontFilePath = name;
    config.fontSize = size;
    
    return config;
}

TTFConfig FontManager::regularFontWithSize(int size) {
    return fontConfig(RegularFont, size);
}

TTFConfig FontManager::lightFontWithSize(int size) {
    return fontConfig(LightFont, size);
}

TTFConfig FontManager::boldFontWithSize(int size) {
    return fontConfig(BoldFont, size);
}

TTFConfig FontManager::mediumFontWithSize(int size) {
    return fontConfig(MediumFont, size);
}

TTFConfig FontManager::levelNumberLabelFontConfig() {
    return regularFontWithSize(40);
}

TTFConfig FontManager::levelTextLabelFontConfig() {
    return regularFontWithSize(40);
}

TTFConfig FontManager::levelSelectionTextLabelFontConfig() {
    return lightFontWithSize(30);
}

TTFConfig FontManager::levelSelectionNumberLabelFontConfig() {
    return mediumFontWithSize(35);
}

TTFConfig FontManager::levelCompletionTextLabelFontConfig() {
    return boldFontWithSize(50);
}