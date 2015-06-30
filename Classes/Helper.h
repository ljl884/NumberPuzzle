/*Written by Wentao Li*/
#ifndef _HELPER_
#define _HELPER_

#include "cocos2d.h"



class Helper{
public:
	static std::string int2str(int i);
	static void split(const std::string& src, const std::string& separator, std::vector<std::string>& dest);
};



#endif