#pragma once
#include "Weapon.h"
#include "Armor.h"


class Equiptment
{
public:
	enum PriorityType { Primary, Secondary };

private:
	Weapon primaryWeapon;
	Weapon secondaryWeapon;

	Armor head;
	Armor chest;
	Armor hands;
	Armor legs;

public:
	void UpdateWeapon(const PriorityType _priorityType, const Weapon& _weapon);
	void UpdateArmor(const Armor& _armor);

	const Weapon& GetWeapon(const PriorityType _priorityType) const;

	const Armor& GetHead() const;
	const Armor& GetChest() const;
	const Armor& GetHands() const;
	const Armor& GetLegs() const;
};