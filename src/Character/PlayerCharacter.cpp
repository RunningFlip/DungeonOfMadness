#include "PlayerCharacter.h"


PlayerCharacter::PlayerCharacter(const std::string _name, const int _health) 
	: Character(_name, _health, 1)
{
	CalculateRequiredExperience();
}

void PlayerCharacter::AddExperience(const float _experience)
{
	currentExperience += _experience;

	if (currentExperience >= requiredExperience)
	{
		level++;
		CalculateRequiredExperience();
	}
}

void PlayerCharacter::CalculateRequiredExperience()
{
	currentExperience = 0;
	requiredExperience = (level * level / 2) * 300 + 100;
}

Equiptment& PlayerCharacter::GetEquiptment() { return equiptment; }

std::ostream& PlayerCharacter::GetAdditionalCharacterValues(std::ostream& _os) const
{
	_os << "Experience:       " + std::to_string(currentExperience) + "/" + std::to_string(requiredExperience) + "\n" +

		"Primary Weapon:   " + equiptment.GetWeapon(Equiptment::PriorityType::Primary).GetValueString() + "\n" +
		"Secondary Weapon: " + equiptment.GetWeapon(Equiptment::PriorityType::Secondary).GetValueString() + "\n\n" +

		"Head:             " + equiptment.GetHead().GetValueString() + "\n" +
		"Chest:            " + equiptment.GetChest().GetValueString() + "\n" +
		"Hands:            " + equiptment.GetHands().GetValueString() + "\n" +
		"Legs:             " + equiptment.GetLegs().GetValueString();

	return _os;
}

const int PlayerCharacter::GetPhyDefend() const
{
	return equiptment.GetHead().GetPhyDefend() + equiptment.GetChest().GetPhyDefend() 
		+ equiptment.GetHead().GetPhyDefend() + equiptment.GetLegs().GetPhyDefend();
}