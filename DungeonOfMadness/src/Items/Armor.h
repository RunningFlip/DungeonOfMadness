#pragma once
#include <string>


class Armor
{
public:
	enum ArmorPart { None, Head, Chest, Hands, Legs };

protected:
	std::string name;

	ArmorPart armorPart;

	int phyDefend;

public:
	Armor();
	Armor(const std::string _name, const ArmorPart _armorPart, const int _phyDefend);

	const ArmorPart GetArmorPart() const;
	const int GetPhyDefend() const;

	const std::string GetValueString() const;
};