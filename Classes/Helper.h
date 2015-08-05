/*Written by Wentao Li*/
#ifndef _HELPER_
#define _HELPER_

#include "cocos2d.h"
#include "Common.h"

class Helper{
private:
public:
	static std::string int2str(int i);
	static void split(const std::string& src, const std::string& separator, std::vector<std::string>& dest);
    static void scaleSprite(cocos2d::Node *sprite);
    static void scaleSpriteAndChildren(cocos2d::Node *sprite);
};

#endif