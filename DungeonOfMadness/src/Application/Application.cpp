#include "../Manager/GameManager.h"

#include "../Executable/FunctionExecutable.h"
#include "../Executable/HelpExecutable.h"
#include "../Executable/GotoExecutableh.h"


int main()
{
	//Create manager
	GameManager gameManager;
	gameManager.Start();

	///Get components
	Parser& parser = gameManager.GetParser();
	Reader& reader = gameManager.GetReader();
	PlayerCharacter& player = gameManager.GetCharacterController().GetPlayer();
	EnvironmentController& environmentController = gameManager.GetEnvironmentController();

	///ParserExecutables
	FunctionExecutable exitExecutable				("Exit",								"Ends the game.",									{ { }, { } },																				std::bind(&GameManager::Stop, &gameManager));
	FunctionExecutable characterExecutable			("Char",								"Lists all character values.",						{ { }, { } },																				std::bind(&Character::PrintCharacterValues, &player));
	FunctionExecutable nearEnvironmentsExecutable	("Env Near",							"Lists all near environments.",						{ { },							{ StateContainer::Fight, StateContainer::Conversation } },	std::bind(&EnvironmentController::PrintNeighbourEnvironments, &environmentController));
	FunctionExecutable nearCharactersExecutable		("Env Chars",							"Lists all characters in the current environment.", { { },							{ StateContainer::Fight, StateContainer::Conversation } },	std::bind(&EnvironmentController::PrintCurrentCharacters, &environmentController));																		
	GotoExecutable gotoExecutable					("Enter", "environment name",			"Enters a specific environment.",					{ { StateContainer::Default },	{ StateContainer::Fight, StateContainer::Conversation } },	environmentController);
	HelpExecutable helpExecutable					("Help",								"Lists all commands that can be executed.",			{ { }, { } },																				parser);

	///Add executables
	parser.AddExecutable(&exitExecutable);
	parser.AddExecutable(&characterExecutable);
	parser.AddExecutable(&nearEnvironmentsExecutable);
	parser.AddExecutable(&nearCharactersExecutable);
	parser.AddExecutable(&gotoExecutable);
	parser.AddExecutable(&helpExecutable);

	///Update game loop
	while (gameManager.IsActive())
	{
		gameManager.Update();
	}
	return 0;
}