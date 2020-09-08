#include "Environment.h"
#include "../Helper/StringHelper.h"
#include <iostream>


Environment::Environment(const std::string _name)
	: name(_name)
{
}

const std::string Environment::GetName() const { return name; }

ParserTable<NpcCharacter>& Environment::GetNpcTable() { return npcTable; }
ParserTable<Environment>& Environment::GetEnvironmentTable() { return envTable; }