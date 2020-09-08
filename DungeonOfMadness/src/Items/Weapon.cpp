#include "Weapon.h"


Weapon::Weapon()
	: name(""),
	weaponType(WeaponType::None),
	damage(0),
	phyDefend(0)
{
}

Weapon::Weapon(const std::string _name, const WeaponType _weaponType, const int _damage, const int _phyDefend)
	: name(_name),
	weaponType(_weaponType),
	damage(_damage),
	phyDefend(_phyDefend)
{
}

const Weapon::WeaponType Weapon::GetWeaponType() const { return weaponType; }
const int Weapon::GetDamage() const { return damage; }
const int Weapon::GetPhyDefend() const { return phyDefend; }

const std::string Weapon::GetValueString() const
{
	std::string text = "None";

	if (weaponType != WeaponType::None)
	{
		text = name +
			" | Type: " + std::to_string(weaponType) +
			" | Damage: " + std::to_string(damage) +
			" | PhyDef: " + std::to_string(phyDefend);
	}
	return text;
}