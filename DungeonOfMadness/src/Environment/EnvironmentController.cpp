#include "EnvironmentController.h"


EnvironmentController::EnvironmentController(Parser* _parser, Environment* _currentEnvironment)
	: parser(_parser), currentEnvironment(_currentEnvironment)
{
}

EnvironmentController::~EnvironmentController()
{
	delete currentEnvironment;
}

void EnvironmentController::SetCurrentEnvironment(Environment* _environment)
{
	currentEnvironment = _environment;
}

Environment* EnvironmentController::GetCurrentEnvironment() const 
{ 
	return currentEnvironment; 
}

void EnvironmentController::PrintNeighbourEnvironments() const
{
	std::cout << "Current environment:" << std::endl;

	if (currentEnvironment != nullptr)
	{
		const std::vector<Environment*>* environments = currentEnvironment->GetEnvironmentTable().GetAll();

		std::cout << "	" << currentEnvironment->GetName() << std::endl;
		std::cout << "Environments around you:" << std::endl;

		if (environments != nullptr)
		{
			for (auto& env : *environments)
			{
				std::cout << "	" << env->GetName() << std::endl;
			}
		}
		else
		{
			std::cout << "	No other environment found." << std::endl;
		}
	}
	else
	{
		std::cout << "	You are nowhere. Ups." << std::endl;
	}
}

void EnvironmentController::PrintCurrentCharacters() const
{
	const std::vector<NpcCharacter*>* npcs = currentEnvironment->GetNpcTable().GetAll();
	std::cout << "Characters in your environment:" << std::endl;

	if (currentEnvironment != nullptr || npcs != nullptr)
	{
		if (npcs->size() != 0)
		{
			for (auto& character : *npcs)
			{
				std::cout << "	" << character->GetName() << std::endl;
			}
		}
		else
		{
			std::cout << "	No characters in your environment." << std::endl;
		}
	}
	else
	{
		std::cout << "	You are nowhere. Ups." << std::endl;
	}
}