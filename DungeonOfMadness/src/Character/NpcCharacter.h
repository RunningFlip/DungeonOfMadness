#pragma once
#include "Character.h"
#include "../Dialogue/DialogueContainer.h"


class NpcCharacter : public Character
{
private:
	int damage;
	int phyDefend;

	DialogueContainer* dialogueContainer;

public:
	NpcCharacter(const std::string _name, const int _health, const int _damage, const int _phyDef, DialogueContainer* _dialogueContainer);
	~NpcCharacter();

	const int GetDamage() const;
	const int GetPhyDefend() const override;

	void StartDialogue();
	void CancelDialogue();
};