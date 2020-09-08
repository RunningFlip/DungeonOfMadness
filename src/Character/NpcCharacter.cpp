#include "NpcCharacter.h"


NpcCharacter::NpcCharacter(const std::string _name, const int _health, const int _damage, const int _phyDef, DialogueContainer* _dialogueContainer)
	: Character(_name, _health), damage(_damage), phyDefend(_phyDef), dialogueContainer(_dialogueContainer)
{
}

NpcCharacter::~NpcCharacter()
{
	delete dialogueContainer;
}

const int NpcCharacter::GetDamage() const { return damage; }
const int NpcCharacter::GetPhyDefend() const { return phyDefend; }

void NpcCharacter::StartDialogue()
{
	dialogueContainer->StartDialogue();
}

void NpcCharacter::CancelDialogue()
{
	dialogueContainer->CancelDialogue();
}