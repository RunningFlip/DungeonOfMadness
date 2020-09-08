#include "GameManager.h"
#include "../Application/Initialisation.h"
#include<iostream>


GameManager::GameManager()
	: isActive(false)
{
	stateMachine = new StateMachine();

	parser = new Parser();
	reader = new Reader(*parser, *stateMachine);

	characterController = new CharacterController("Finn", 100);
	battleController = new BattleController(*stateMachine, characterController->GetPlayer());
	environmentController = new EnvironmentController(parser, Initialisation::EnvironmentInitialisation());
}

GameManager::~GameManager()
{
	delete stateMachine;

	delete parser;
	delete reader;

	delete characterController;
	delete battleController;
	delete environmentController;
}

const bool GameManager::IsActive() const { return isActive; }

StateMachine& GameManager::GetStateMachine() const { return *stateMachine; }
Parser& GameManager::GetParser() const { return *parser; }
Reader& GameManager::GetReader() const { return *reader; }

CharacterController& GameManager::GetCharacterController() const { return *characterController; }
BattleController& GameManager::GetBattleController() const { return *battleController; }
EnvironmentController& GameManager::GetEnvironmentController() const { return *environmentController; }

void GameManager::Start()
{
	isActive = true;
	reader->Start();
}

void GameManager::Update()
{
	if (reader->IsReading()) reader->Listen();
}

void GameManager::Stop()
{
	isActive = false;
	reader->Stop();
}