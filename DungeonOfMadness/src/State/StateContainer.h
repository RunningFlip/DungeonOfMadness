#pragma once
#include <vector>


class StateContainer
{
public:
	enum State
	{
		Default,
		Fight,
		Conversation,
	};

private:
	std::vector<State> requiredStates;
	std::vector<State> forbiddenStates;

public:

	StateContainer(const std::vector<State> _requiredStates, const std::vector<State> _forbiddenSTates);

	const std::vector<State>& GetRequiredStates() const;
	const std::vector<State>& GetForbiddenStates() const;
};