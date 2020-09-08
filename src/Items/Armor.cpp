#include "Armor.h"


Armor::Armor()
	: name(""),
	armorPart(ArmorPart::None),
	phyDefend(0)
{
}

Armor::Armor(const std::string _name, const ArmorPart _armorPart, const int _phyDefend)
	: name(_name),
	armorPart(_armorPart),
	phyDefend(_phyDefend)
{
}

const Armor::ArmorPart Armor::GetArmorPart() const { return armorPart; }
const int Armor::GetPhyDefend() const { return phyDefend; }

const std::string Armor::GetValueString() const
{
	std::string text = "None";

	if (armorPart != ArmorPart::None)
	{
		text = name +
			" | Part: " + std::to_string(armorPart) +
			" | PhyDef: " + std::to_string(phyDefend);
	}
	return text;
}