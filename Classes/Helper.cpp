/*Written by Wentao Li*/
#include "Helper.h"

using namespace std;

string Helper::int2str(int i) {
	string s;
	stringstream ss(s);
	ss << i;

	return ss.str();
}

void Helper::split(const string& src, const string& separator, vector<string>& dest)
{
	string str = src;
	string substring;
	string::size_type start = 0, index;

	do
	{
		index = str.find_first_of(separator, start);
		if (index != string::npos)
		{
			substring = str.substr(start, index - start);
			dest.push_back(substring);
			start = str.find_first_not_of(separator, index);
			if (start == string::npos) return;
		}
	} while (index != string::npos);

	//the last token
	substring = str.substr(start);
	dest.push_back(substring);
}

void Helper::scaleSprite(Node *sprite) {
    Size ratio = Constant::frameRatioSize;
	sprite->setScaleY(1 / ratio.height * ratio.width / ratio.height);
	sprite->setScaleX(1 / ratio.width * ratio.width / ratio.height);
}

void Helper::scaleSpriteAndChildren(Node *sprite) {
    for (auto childSprite : sprite->getChildren()) {
        scaleSprite(childSprite);
    }
}