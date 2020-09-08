#pragma once
#include <vector>
#include "../Character/PlayerCharacter.h"
#include "../Character/NpcCharacter.h"


class CharacterController
{
private:
	PlayerCharacter* player;
	std::vector<NpcCharacter*> currentCharacters;

public:
	CharacterController(const std::string _playerName, const int _startHealth);
	~CharacterController();

	PlayerCharacter& GetPlayer() const;
	std::vector<NpcCharacter*>&  GetCurrentCharacters();
};