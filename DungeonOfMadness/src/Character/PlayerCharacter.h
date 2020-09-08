#pragma once
#include "Character.h"
#include "../Items/Equiptment.h"


class PlayerCharacter : public Character
{
protected:
	int currentExperience;
	int requiredExperience;

	Equiptment equiptment;

	void CalculateRequiredExperience();

	std::ostream& GetAdditionalCharacterValues(std::ostream& _os) const override;

public:
	PlayerCharacter(const std::string _name, const int _health);

	void AddExperience(const float _experience);
	Equiptment& GetEquiptment();

	const int GetPhyDefend() const override;
};