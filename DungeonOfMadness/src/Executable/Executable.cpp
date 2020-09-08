#include "Executable.h"
#include <iostream>

Executable::Executable(const std::string _keyword, const std::string _description, const StateContainer _stateContainer)
	: keyword(_keyword), extension(""), description(_description), stateContainer(_stateContainer)
{
}

Executable::Executable(const std::string _keyword, const std::string _extension, const std::string _description, const StateContainer _stateContainer)
	: keyword(_keyword), extension("<" + _extension + ">"), description(_description), stateContainer(_stateContainer)
{
}

void Executable::PrintDeniedState() const
{
	std::cout << "Command not valid right now." << std::endl;
}

std::string Executable::GetKeyword() { return keyword; }
std::string Executable::GetExtension() { return extension; }
std::string Executable::GetDescription() { return description; }

void Executable::Execute(const StateMachine& _stateMachine, const std::string _extension)
{
	if (_stateMachine.StateIsValid(stateContainer))
	{
		OnExecute(_stateMachine, _extension);
	}
	else
	{
		PrintDeniedState();
	}
}