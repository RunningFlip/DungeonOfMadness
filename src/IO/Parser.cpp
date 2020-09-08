#include "Parser.h"
#include "../Helper/StringHelper.h"


Executable* Parser::TryGetMatch(const std::string _input, std::string& _extension)
{
	std::string parsedInput = StringHelper::ParseString(_input);
	std::vector<std::string> words = StringHelper::SplitIntoWords(parsedInput);

	bool found = false;
	int foundAtIndex = 0;

	std::string str = "";
	std::string extension = "";	

	for (int i = 0; i < words.size(); i++)
	{
		if (!found)
		{
			if (i > 0) str += " ";
			str += words[i];

			if (executables.contains(str))
			{
				found = true;
				foundAtIndex = i + 1;
			}
		}
		else
		{
			if (i > foundAtIndex) extension += " ";
			extension += words[i];
		}
		
		if (executables.contains(str)) found = true;
	}
	
	if (found)
	{
		_extension = extension; 
		return executables[str];
	}
	else
	{
		_extension = "";
		return nullptr;
	}
}

void Parser::AddExecutable(Executable* _executable)
{
	std::string parsedKeyword = StringHelper::ParseString(_executable->GetKeyword());

	executables.insert({ parsedKeyword, _executable });
	infoTable.insert({ parsedKeyword, { _executable->GetKeyword(), _executable->GetExtension(),_executable->GetDescription() } });
}

void Parser::RemoveExecutable(const std::string _keyword)
{
	std::string parsedKeyword = StringHelper::ParseString(_keyword);

	delete executables[parsedKeyword];

	executables.erase(parsedKeyword);
	infoTable.erase(parsedKeyword);
}

const std::map<std::string, Parser::ParserInfo>& Parser::GetInformation() const { return infoTable; }