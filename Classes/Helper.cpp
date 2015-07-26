/*Written by Wentao Li*/
#include "Helper.h"



std::string Helper::int2str(int i) {
	std::string s;
	std::stringstream ss(s);
	ss << i;

	return ss.str();
}

void Helper::split(const std::string& src, const std::string& separator, std::vector<std::string>& dest)
{
	std::string str = src;
	std::string substring;
	std::string::size_type start = 0, index;

	do
	{
		index = str.find_first_of(separator, start);
		if (index != std::string::npos)
		{
			substring = str.substr(start, index - start);
			dest.push_back(substring);
			start = str.find_first_not_of(separator, index);
			if (start == std::string::npos) return;
		}
	} while (index != std::string::npos);

	//the last token
	substring = str.substr(start);
	dest.push_back(substring);
}

void Helper::scaleSprite(Node *sprite) {
    Size ratio = Constant::frameRatioSize;
    bool xLarger = ratio.width > ratio.height;
	sprite->setScaleY(ratio.width);
	sprite->setScaleX(ratio.height);
}

void Helper::scaleSpriteAndChildren(Node *sprite) {
    for (auto childSprite : sprite->getChildren()) {
        scaleSprite(childSprite);
    }
}