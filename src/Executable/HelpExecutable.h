#pragma once
#include "Executable.h"
#include "../IO/Parser.h"


class HelpExecutable : public Executable
{
private:
	Parser& parser;

public:
	HelpExecutable(const std::string _keyword, const std::string _description, const StateContainer _stateContainer, Parser& _parser);

	void OnExecute(const StateMachine& _stateMachine, const std::string _extension) override;
	const int GetMaxLength(const std::map<std::string, Parser::ParserInfo> _information, const int _size);
};