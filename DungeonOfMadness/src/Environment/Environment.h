#pragma once
#include <map>
#include <vector>
#include "../Character/NpcCharacter.h"
#include "../IO/ParserTable.h"


class Environment
{
private:
	std::string name;

	ParserTable<NpcCharacter> npcTable;
	ParserTable<Environment> envTable;

public:
	Environment(const std::string _name);

	const std::string GetName() const;

	ParserTable<NpcCharacter>& GetNpcTable();
	ParserTable<Environment>& GetEnvironmentTable();
};