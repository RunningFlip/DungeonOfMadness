#pragma once
#include <map>
#include "StateContainer.h"


class StateMachine
{
private:
	std::map<StateContainer::State, int> stateTable;

public:
	StateMachine();

	void ResetToState(const StateContainer::State _state, const int _weight);

	void EnableState(const StateContainer::State _state);
	void DisableState(const StateContainer::State _state);

	bool StateIsActive(const StateContainer::State _state) const;
	bool StateIsValid(const StateContainer& _stateContainer) const;
};