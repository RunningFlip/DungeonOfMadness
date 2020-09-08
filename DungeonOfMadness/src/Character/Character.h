#pragma once
#include <string>
#include <iostream>


class Character
{
public:
	enum PriorityType { Primary, Secondary };

protected:
	std::string name;

	int level;

	int currenthealth;
	int maxHealth;

	virtual std::ostream& GetAdditionalCharacterValues(std::ostream& _os) const { return std::cout; };

public:
	Character(const std::string _name, const int _health, const int level = 1);
	Character(const Character& _character);

	void AddDamage(const int _damage);
	void AddHeal(const int _health);

	const std::string GetName() const;
	const int GetLevel() const;
	const int GetCurrentHealth() const;
	const int GetMaxHealth() const;

	void PrintCharacterValues() const;

	virtual const int GetPhyDefend() const = 0;
};