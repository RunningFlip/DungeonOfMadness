#include "HelpExecutable.h"
#include <iostream>


HelpExecutable::HelpExecutable(const std::string _keyword, const std::string _description, const StateContainer _stateContainer, Parser& _parser)
	: Executable(_keyword, _description, _stateContainer), parser(_parser)
{
}

void HelpExecutable::OnExecute(const StateMachine& _stateMachine, const std::string _extension)
{
	auto infoTable = parser.GetInformation();

	const int size = infoTable.size();
	const int maxNameLength = GetMaxLength(infoTable, size) + 1;

	std::string text = "";

	for (auto& pair : infoTable)
	{
		const auto& parserInfo = pair.second;
		const std::string extendedName = parserInfo.name + " " + parserInfo.extension;
		const size_t currentLength = maxNameLength - extendedName.length();

		text += extendedName;
		text.append(currentLength, ' ');
		text += "--> " + parserInfo.description + "\n";
	}
	std::cout << text;
}

const int HelpExecutable::GetMaxLength(const std::map<std::string, Parser::ParserInfo> _information, const int _size)
{
	int maxKeywordLength = 0;

	for (auto& pair : _information)
	{
		const auto& parserInfo = pair.second;
		int currentLength = (parserInfo.name + " " + parserInfo.extension).length();

		if (maxKeywordLength < currentLength)
		{
			maxKeywordLength = currentLength;
		}
	}
	return maxKeywordLength;
}