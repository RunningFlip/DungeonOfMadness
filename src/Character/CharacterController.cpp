#include "CharacterController.h"
#include "../Dialogue/DialogueContainer.h"


CharacterController::CharacterController(const std::string _playerName, const int _startHealth)
{
	player = new PlayerCharacter(_playerName, _startHealth);
}

CharacterController::~CharacterController()
{
	delete player;

	for (int i = 0; i < currentCharacters.size(); i++)
	{
		delete currentCharacters[i];
	}
}

PlayerCharacter& CharacterController::GetPlayer() const { return *player; }
std::vector<NpcCharacter*>& CharacterController::GetCurrentCharacters() { return currentCharacters; }