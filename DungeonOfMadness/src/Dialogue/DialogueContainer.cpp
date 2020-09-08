#include "DialogueContainer.h"
#include <iostream>


DialogueContainer::DialogueContainer(const std::string _name, DialogueBranch* _startBranch)
	: name(_name), startBranch(_startBranch), inDialogue(false)
{
}

DialogueContainer::~DialogueContainer()
{
	delete startBranch;
}

void DialogueContainer::PrintAllEntries(const DialogueBranch* _branch) const
{
	for (int i = 0; i < _branch->nextBranches.size(); i++)
	{
		const DialogueBranch* current = _branch->nextBranches.at(i);
		std::cout << "	" << current->trigger << ": " << current->entry << std::endl;
	}
}

void DialogueContainer::StartDialogue()
{
	if (!inDialogue)
	{
		inDialogue = true;
		currentBranch = startBranch;

		std::cout << "Dialogue startet with " << name << ":\n" << "----\n" << std::endl;

		PrintDialogue(currentBranch);
	}
}

void DialogueContainer::CancelDialogue()
{
	if (inDialogue)
	{
		inDialogue = false;
		currentBranch = nullptr;

		std::cout << name << ": '" << "Bye.." << "'" << std::endl;
	}
}

void DialogueContainer::PrintDialogue(const DialogueBranch* _branch)
{
	if (_branch->dialogue != "")
	{
		std::cout << name << ": '" << _branch->dialogue << "'" << std::endl;
	}

	if (_branch->nextBranches.size() == 0)
	{
		currentBranch = startBranch;
		PrintDialogue(currentBranch);
	}
	else
	{
		PrintAllEntries(_branch);
	}
}

void DialogueContainer::EnterBranch(const char _trigger)
{
	if (currentBranch->nextBranches.contains(_trigger))
	{
		currentBranch = currentBranch->nextBranches[_trigger];
		PrintDialogue(currentBranch);
	}
	else
	{
		std::cout << "I have no answer to this.." << std::endl;
	}
}