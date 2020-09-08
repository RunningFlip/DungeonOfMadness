#pragma once
#include <vector>
#include "../Environment/Environment.h"
#include "../Character/NpcCharacter.h"


namespace Initialisation
{
	Environment* EnvironmentInitialisation()
	{
		Environment* village = new Environment("Village");
		Environment* store = new Environment("Store");
		Environment* church = new Environment("Church");
		Environment* oldHouse = new Environment("Old House");

		NpcCharacter* shopKeeper = new NpcCharacter("Martin", 100, 20, 20, nullptr);
		

		//---Testing------------------------------------------------
		DialogueContainer* testDialogue = nullptr;

		DialogueBranch* aaBranch = new DialogueBranch('A', "Fine thanks.", "...");
		DialogueBranch* abBranch = new DialogueBranch('B', "Nothing you have to bother about", "...ehm okay, I guess..");

		DialogueBranch* aBranch = new DialogueBranch('A', "Greetings! How are you?", "..everything is perfectly fine! What about you?");
		aBranch->AddBranch(aaBranch);
		aBranch->AddBranch(abBranch);

		DialogueBranch* bBranch = new DialogueBranch('B', "Have some information for me?", "...how about: no?!");

		DialogueBranch* startBranch = new DialogueBranch("Greetings!");
		startBranch->AddBranch(aBranch);
		startBranch->AddBranch(bBranch);

		NpcCharacter* homlessMan = new NpcCharacter("Homless man", 50, 10, 10, testDialogue);
		testDialogue = new DialogueContainer(homlessMan->GetName(), startBranch);
		//----------------------------------------------------------


		///Village
		village->GetEnvironmentTable().Add(store->GetName(), store);
		village->GetEnvironmentTable().Add(church->GetName(), church);
		village->GetEnvironmentTable().Add(oldHouse->GetName(), oldHouse);
		village->GetNpcTable().Add(homlessMan->GetName(), homlessMan);

		///Buildings
		store->GetEnvironmentTable().Add(village->GetName(), village);
		store->GetNpcTable().Add(shopKeeper->GetName(), shopKeeper);

		church->GetEnvironmentTable().Add(village->GetName(), village);
		oldHouse->GetEnvironmentTable().Add(village->GetName(), village);

		return village;
	}
}