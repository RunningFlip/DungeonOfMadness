#include "BattleController.h"


BattleController::BattleController(StateMachine& _stateMachine, PlayerCharacter& _player)
	: stateMachine(_stateMachine), player(_player), playerTurn(false)
{
}

void BattleController::StartBattle(const Character* _character)
{
	stateMachine.EnableState(StateContainer::State::Fight);
}

void BattleController::NextRound()
{
	while (stateMachine.StateIsActive(StateContainer::State::Fight))
	{
		if (playerTurn)
		{


			playerTurn = false;
		}
		else
		{


			playerTurn = true;
		}
	}
}

void BattleController::EndBattle()
{
	stateMachine.DisableState(StateContainer::State::Fight);
}