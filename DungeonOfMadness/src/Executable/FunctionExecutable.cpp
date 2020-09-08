#include "FunctionExecutable.h"
#include <iostream>


FunctionExecutable::FunctionExecutable(const std::string _keyword, const std::string _description, const StateContainer _stateContainer, const std::function<void()> _function)
	: Executable(_keyword,_description, _stateContainer), function(_function)
{
}

void FunctionExecutable::OnExecute(const StateMachine& _stateMachine, const std::string _extension)
{ 
	if (_extension == "")
	{
		function();
	}
	else
	{
		std::cout << "Keyword: '" << keyword << "' - Extension not allowed!" << std::endl;
	}
}