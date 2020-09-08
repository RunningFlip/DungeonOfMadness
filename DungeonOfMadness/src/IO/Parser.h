#pragma once
#include <map>
#include "../Executable/Executable.h"


class Parser
{
public:
	struct ParserInfo
	{
		std::string name;
		std::string extension;
		std::string description;
	};

private:
	std::map<std::string, Executable*> executables;
	std::map<std::string, ParserInfo> infoTable;

public:
	Executable* TryGetMatch(const std::string _input, std::string& _extension);

	void AddExecutable(Executable* _executable);
	void RemoveExecutable(const std::string _keyword);

	const std::map<std::string, ParserInfo>& GetInformation() const;
};