//
//  CoverLayer.hpp
//  NumberPuzzle
//
//  Created by Jin Wang on 5/08/2015.
//
//

#ifndef CoverLayer_h
#define CoverLayer_h

/*
	The cover layer is basically a layer that stops touches from going to its parent.
	Right now this is hackish. If it doesn't work I can recursively turn off touches
	for all parents... (think about that...)
 
	The cover layer also adds a black tint to whatever it's covering to give it a
	"disabled" modal look.
 */

#include "cocos2d.h"
#include "ui/CocosGUI.h"

class CoverLayer : public cocos2d::LayerColor
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    virtual bool onTouch(cocos2d::Touch*, cocos2d::Event*);
    
    void show();
    void hide();
    
    // implement the "static create()" method manually
    CREATE_FUNC(CoverLayer);
protected:
    bool _covered = true;
};

#endif /* CoverLayer_hpp */
