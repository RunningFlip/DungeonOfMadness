#include "StateMachine.h"


StateMachine::StateMachine()
{
	stateTable.insert(std::pair(StateContainer::State::Default, -1));
	stateTable.insert(std::pair(StateContainer::State::Fight, -1));
	stateTable.insert(std::pair(StateContainer::State::Conversation, -1));
}

void StateMachine::ResetToState(const StateContainer::State _state, const int _weight)
{
	for (auto& pair : stateTable) pair.second = -1;
	stateTable[_state] = _weight;
}

void StateMachine::EnableState(const StateContainer::State _state) { stateTable[_state] += 1; }
void StateMachine::DisableState(const StateContainer::State _state) { stateTable[_state] -= 1; }

bool StateMachine::StateIsActive(const StateContainer::State _state) const { return stateTable.at(_state) >= 0; }

bool StateMachine::StateIsValid(const StateContainer& _stateContainer) const
{
	const std::vector<StateContainer::State>& required = _stateContainer.GetRequiredStates();
	const std::vector<StateContainer::State>& forbidden = _stateContainer.GetForbiddenStates();

	for (int i = 0; i < required.size(); i++)
	{
		if (stateTable.at(required[i]) < 0) return false;
	}

	for (int i = 0; i < forbidden.size(); i++)
	{
		if (stateTable.at(forbidden[i]) >= 0) return false;
	}
	return true;
}