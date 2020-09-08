#pragma once
#include "Environment.h"
#include "../IO/Parser.h"


class EnvironmentController
{
private:
	Parser* parser;
	Environment* currentEnvironment;

public:
	EnvironmentController(Parser* _parser, Environment* _currentEnvironment);
	~EnvironmentController();

	void SetCurrentEnvironment(Environment* _environment);
	Environment* GetCurrentEnvironment() const;

	void PrintNeighbourEnvironments() const;
	void PrintCurrentCharacters() const;
};
