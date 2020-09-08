#pragma once
#include <string>
#include <vector>


namespace StringHelper
{
	std::string ParseString(const std::string _string);
	std::vector<std::string> SplitIntoWords(const std::string _string);
}