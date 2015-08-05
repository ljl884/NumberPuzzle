//
//  FontManager.hpp
//  NumberPuzzle
//
//  Created by Jin Wang on 5/08/2015.
//
//

#ifndef FontManager_hpp
#define FontManager_hpp

#include "cocos2d.h"

USING_NS_CC;

class FontManager {
    
public:
    
    static constexpr const char* BoldFont = "Ubuntu-Bold.ttf";
    static constexpr const char* RegularFont = "Ubuntu-Regular.ttf";
    static constexpr const char* MediumFont = "Ubuntu-Medium.ttf";
    static constexpr const char* LightFont = "Ubuntu-Light.ttf";
    
    static FontManager& getInstance()
    {
        static FontManager    instance; // Guaranteed to be destroyed.
        // Instantiated on first use.
        return instance;
    }
    
    TTFConfig boldFontWithSize(int size);
    TTFConfig regularFontWithSize(int size);
    TTFConfig lightFontWithSize(int size);
    TTFConfig mediumFontWithSize(int size);
    
    // More specific fonts for the whole app.
    TTFConfig levelSelectionNumberLabelFontConfig();
    TTFConfig levelSelectionTextLabelFontConfig();
    TTFConfig levelNumberLabelFontConfig();
    TTFConfig levelTextLabelFontConfig();
    TTFConfig levelCompletionTextLabelFontConfig();
    
private:
    FontManager() {};
    
    // C++ 11
    // =======
    // We can use the better technique of deleting the methods
    // we don't want.
    FontManager(FontManager const&)     = delete;
    void operator=(FontManager const&)  = delete;
    
    TTFConfig fontConfig(const char *name, int size);
};

#endif /* FontManager_hpp */
