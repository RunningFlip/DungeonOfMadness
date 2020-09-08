#pragma once
#include "../State/StateMachine.h"
#include "../Character/PlayerCharacter.h"
#include "../Character/NpcCharacter.h"


class BattleController
{
private:
	bool playerTurn;

	StateMachine& stateMachine;
	PlayerCharacter& player;

public:
	BattleController(StateMachine& _stateMachine, PlayerCharacter& _player);

	void StartBattle(const Character* _character);
	void NextRound();
	void EndBattle();
};