#pragma once
#include "../State/StateMachine.h"

#include "../IO/Parser.h"
#include "../IO/Reader.h"

#include "../Battle/BattleController.h"
#include "../Character/CharacterController.h"
#include "../Environment/EnvironmentController.h"


class GameManager
{
private:
	///Flags
	bool isActive;

	///Editor
	StateMachine* stateMachine;
	Parser* parser;
	Reader* reader;

	///Controller
	CharacterController* characterController;
	BattleController* battleController;
	EnvironmentController* environmentController;

public:
	GameManager();
	~GameManager();

	const bool IsActive() const;

	StateMachine& GetStateMachine() const;
	Parser& GetParser() const;
	Reader& GetReader() const;

	CharacterController& GetCharacterController() const;
	BattleController& GetBattleController() const;
	EnvironmentController& GetEnvironmentController() const;

	void Start();
	void Update();
	void Stop();
};