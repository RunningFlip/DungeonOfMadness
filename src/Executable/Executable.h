#pragma once
#include <string>
#include <vector>
#include "../State/StateMachine.h"


class Executable
{
protected:
	std::string keyword;
	std::string extension;
	std::string description;

	StateContainer stateContainer;

	virtual void PrintDeniedState() const;
	virtual void OnExecute(const StateMachine& _stateMachine, const std::string _extension) = 0;

	Executable(const std::string _keyword, const std::string _description, const StateContainer _stateContainer);
	Executable(const std::string _keyword, const std::string _extension, const std::string _description, const StateContainer _stateContainer);

public:
	std::string GetKeyword();
	std::string GetExtension();
	std::string GetDescription();

	void Execute(const StateMachine& _stateMachine, const std::string _extension);
};