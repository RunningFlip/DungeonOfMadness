#include "Character.h"
#include <algorithm>


Character::Character(const std::string _name, const int _health, const int _level)
	: name(_name),
	currenthealth(_health),
	maxHealth(_health),
	level(_level)
{
}

Character::Character(const Character& _character)
	: name(_character.name),
	currenthealth(_character.currenthealth),
	maxHealth(_character.maxHealth),
	level(_character.level)
{
}

void Character::AddDamage(const int _damage)
{
	currenthealth = std::clamp(currenthealth -= _damage, 0, maxHealth);
}

void Character::AddHeal(const int _health)
{
	currenthealth = std::clamp(currenthealth += _health, 0, maxHealth);
}

const std::string Character::GetName() const { return name; }
const int Character::GetLevel() const { return level; }
const int Character::GetCurrentHealth() const { return currenthealth; }
const int Character::GetMaxHealth() const { return maxHealth; }

void Character::PrintCharacterValues() const
{
	std::ostream& os = std::cout; 

	os << "Name:             " + name + "\n" +
		  "Lvl:              " + std::to_string(level) + "\n" +
		  "Health:           " + std::to_string(currenthealth) + "/" + std::to_string(maxHealth) + "\n" +
		  "PhyDefend:        " + std::to_string(GetPhyDefend()) + "\n\n";

	GetAdditionalCharacterValues(os);
	os << std::endl;
}