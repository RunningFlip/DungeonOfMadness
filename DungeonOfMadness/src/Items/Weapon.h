#pragma once
#include <string>


class Weapon
{
public:
	enum WeaponType { None, Melee, MidRange, Range };

protected:
	std::string name;

	WeaponType weaponType;

	int damage;
	int phyDefend;

public:
	Weapon();
	Weapon(const std::string _name, const WeaponType _weaponType, const int _damage, const int _phyDefend);

	const WeaponType GetWeaponType() const;
	const int GetDamage() const;
	const int GetPhyDefend() const;

	const std::string GetValueString() const;
};