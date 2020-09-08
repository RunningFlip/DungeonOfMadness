#include "Equiptment.h"


void Equiptment::UpdateWeapon(const PriorityType _priorityType, const Weapon& _weapon)
{
	switch (_priorityType)
	{
	case PriorityType::Primary:
		primaryWeapon = _weapon;
		break;
	case PriorityType::Secondary:
		secondaryWeapon = _weapon;
		break;
	}
}

void Equiptment::UpdateArmor(const Armor& _armor)
{
	switch (_armor.GetArmorPart())
	{
	case Armor::ArmorPart::Head:
		head = _armor;
		break;
	case Armor::ArmorPart::Chest:
		chest = _armor;
		break;
	case Armor::ArmorPart::Hands:
		hands = _armor;
		break;
	case Armor::ArmorPart::Legs:
		legs = _armor;
		break;
	}
}

const Weapon& Equiptment::GetWeapon(const PriorityType _priorityType) const
{
	switch (_priorityType)
	{
	case PriorityType::Primary:
		return primaryWeapon;
	case PriorityType::Secondary:
		return secondaryWeapon;
	}
}

const Armor& Equiptment::GetHead() const { return head; }
const Armor& Equiptment::GetChest() const { return chest; }
const Armor& Equiptment::GetHands() const { return hands; }
const Armor& Equiptment::GetLegs() const { return legs; }