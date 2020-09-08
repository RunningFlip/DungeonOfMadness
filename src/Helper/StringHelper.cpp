#include "StringHelper.h"


std::string StringHelper::ParseString(const std::string _string)
{
	std::string parsed;

	for (auto it = _string.begin(); it != _string.end(); ++it)
	{
		parsed += std::tolower(*it);
	}
	return parsed;
}

std::vector<std::string> StringHelper::SplitIntoWords(const std::string _string)
{
	std::vector<std::string> words;
	std::string currentWord = "";

	for (auto x : _string)
	{
		if (x == ' ')
		{
			if (currentWord != "")
			{
				words.push_back(currentWord);
			}
			currentWord = "";
		}
		else
		{
			currentWord = currentWord + x;
		}
	}

	if (currentWord != "")
	{
		words.push_back(currentWord);
	}

	return words;
}