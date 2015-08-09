//
//  FontManager.cpp
//  NumberPuzzle
//
//  Created by Jin Wang on 5/08/2015.
//
//

#include "FontManager.h"

#define BOLD_FONT "fonts/Ubuntu-Bold.ttf"
#define REGULAR_FONT "fonts/Ubuntu-Regular.ttf"
#define MEDIUM_FONT "fonts/Ubuntu-Medium.ttf"
#define LIGHT_FONT "fonts/Ubuntu-Light.ttf"

TTFConfig FontManager::fontConfig(const char *name, int size) {
    
    // Initialize a new TTFConfig struct
    TTFConfig config = TTFConfig(name, size, GlyphCollection::DYNAMIC);
    
//    config.fontFilePath = name;
//    config.fontSize = size;
    
    return config;
}

TTFConfig FontManager::regularFontWithSize(int size) {
    return fontConfig(REGULAR_FONT, size);
}

TTFConfig FontManager::lightFontWithSize(int size) {
    return fontConfig(LIGHT_FONT, size);
}

TTFConfig FontManager::boldFontWithSize(int size) {
    return fontConfig(BOLD_FONT, size);
}

TTFConfig FontManager::mediumFontWithSize(int size) {
    return fontConfig(MEDIUM_FONT, size);
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
