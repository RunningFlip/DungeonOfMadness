#pragma once
#include "Executable.h"
#include "../Environment/EnvironmentController.h"


class GotoExecutable : public Executable
{
private:
	EnvironmentController& environmentController;

public:
	GotoExecutable(const std::string _keyword, const std::string _extendedName, const std::string _description, const StateContainer _stateContainer, EnvironmentController& _environmentController);

	void OnExecute(const StateMachine& _stateMachine, const std::string _extension) override;
};