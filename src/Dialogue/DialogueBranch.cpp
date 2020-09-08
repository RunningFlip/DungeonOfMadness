#include "DialogueBranch.h"


DialogueBranch::DialogueBranch(std::string _entry)
	: entry(_entry)
{
}

DialogueBranch::DialogueBranch(const char _trigger, std::string _entry, std::string _dialogue)
	: trigger(_trigger),
	  entry(_entry),
	  dialogue(_dialogue)
{
}

DialogueBranch::~DialogueBranch()
{
	for (int i = 0; i < nextBranches.size(); i++)
	{
		if (nextBranches[i] != nullptr)
		{
			delete nextBranches[i];
		}
	}
}

void DialogueBranch::AddBranch(DialogueBranch* _branch)
{
	nextBranches.insert({ _branch->trigger, _branch });
}