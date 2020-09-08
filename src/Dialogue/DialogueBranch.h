#pragma once
#include <map>
#include <string>
#include <iostream>


struct DialogueBranch
{
	char trigger;
	std::string entry;
	std::string dialogue;

	std::map<char, DialogueBranch*> nextBranches;

	DialogueBranch(std::string _entry);
	DialogueBranch(const char _trigger, std::string _entry, std::string _dialogue);
	~DialogueBranch();

	void AddBranch(DialogueBranch* _branch);
};