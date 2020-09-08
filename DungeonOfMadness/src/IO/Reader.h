#pragma once
#include "Parser.h"
#include "../State/StateMachine.h"


class Reader
{
private:
	const std::string PREFIX = "// ";

	bool isReading;

	Parser& parser;
	StateMachine& stateMachine;

public:
	Reader(Parser& _parser, StateMachine& _stateMachine);

	void Start();
	void Stop();

	void Listen();

	bool IsReading() const;
};