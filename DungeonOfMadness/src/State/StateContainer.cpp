#include "StateContainer.h"


StateContainer::StateContainer(const std::vector<State> _requiredStates, const std::vector<State> _forbiddenStates)
{
	requiredStates = _requiredStates;
	forbiddenStates = _forbiddenStates;
}

const std::vector<StateContainer::State>& StateContainer::GetRequiredStates() const
{
	return requiredStates;
}

const std::vector<StateContainer::State>& StateContainer::GetForbiddenStates() const
{
	return forbiddenStates;
}