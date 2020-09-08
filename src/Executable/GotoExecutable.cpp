#include "GotoExecutableh.h"
#include <iostream>


GotoExecutable::GotoExecutable(const std::string _keyword, const std::string _extension, const std::string _description, const StateContainer _stateContainer, EnvironmentController& _environmentController)
	: Executable(_keyword, _extension, _description, _stateContainer), environmentController(_environmentController)
{
}

void GotoExecutable::OnExecute(const StateMachine& _stateMachine, const std::string _extension) 
{
	bool isValid = environmentController.GetCurrentEnvironment()->GetEnvironmentTable().ContainsKey(_extension);

	if (isValid)
	{
		Environment* nextEnv = environmentController.GetCurrentEnvironment()->GetEnvironmentTable().Get(_extension);
		environmentController.SetCurrentEnvironment(nextEnv);

		std::cout << "You entered '" << nextEnv->GetName() << "'." << std::endl;
	}
	else
	{
		const std::string currentEnvName = environmentController.GetCurrentEnvironment()->GetName();

		if (StringHelper::ParseString(currentEnvName) == _extension)
		{
			std::cout << "You are already in '" << currentEnvName << "'" << std::endl;
		}
		else
		{
			std::cout << "'" << _extension << "' is not a valid environment to enter!" << std::endl;
		}
	}
}
