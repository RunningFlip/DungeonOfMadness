#pragma once
#include <map>
#include "DialogueBranch.h"


class DialogueContainer
{
private:
	bool inDialogue;

	const std::string name;

	DialogueBranch* startBranch;
	DialogueBranch* currentBranch;

	void PrintAllEntries(const DialogueBranch* _branch) const;
	void PrintDialogue(const DialogueBranch* _branch);

public:
	DialogueContainer(const std::string _name, DialogueBranch* _startBranch);
	~DialogueContainer();

	void StartDialogue();
	void CancelDialogue();

	void EnterBranch(const char _trigger);
};