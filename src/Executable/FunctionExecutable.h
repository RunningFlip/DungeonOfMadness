#pragma once
#include <iostream>
#include <functional>
#include "Executable.h"


class FunctionExecutable : public Executable
{
private:
	std::function<void()> function;

public:
	FunctionExecutable(const std::string _keyword, const std::string _description, const StateContainer _stateContainer, const std::function<void()> _function);

	void OnExecute(const StateMachine& _stateMachine, const std::string _extension) override;
};