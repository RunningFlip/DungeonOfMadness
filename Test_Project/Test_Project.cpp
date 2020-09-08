#include "pch.h"
#include "CppUnitTest.h"

#include "../DungeonOfMadness/src/Manager/GameManager.h"
#include "../DungeonOfMadness/src/Executable/FunctionExecutable.h"
#include "../DungeonOfMadness/src/Executable/HelpExecutable.h"
#include "../DungeonOfMadness/src/Executable/GotoExecutableh.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;


namespace TestProject
{
	TEST_CLASS(UnitTestController)
	{
	private:
		GameManager gameManager;

		Parser& parser;
		Reader& reader;

		PlayerCharacter& player;
		EnvironmentController& environmentController;


	public:
		UnitTestController()
			: parser(gameManager.GetParser()),
			  reader(gameManager.GetReader()),
			  player(gameManager.GetCharacterController().GetPlayer()),
			  environmentController(gameManager.GetEnvironmentController())
		{
			//Create manager
			gameManager.Start();

			///ParserExecutables
			FunctionExecutable exitExecutable("Exit", "Ends the game.", { { }, { } }, std::bind(&GameManager::Stop, &gameManager));
			FunctionExecutable characterExecutable("Char", "Lists all character values.", { { }, { } }, std::bind(&Character::PrintCharacterValues, &player));
			FunctionExecutable nearEnvironmentsExecutable("Env Near", "Lists all near environments.", { { },							{ StateContainer::Fight, StateContainer::Conversation } }, std::bind(&EnvironmentController::PrintNeighbourEnvironments, &environmentController));
			FunctionExecutable nearCharactersExecutable("Env Chars", "Lists all characters in the current environment.", { { },							{ StateContainer::Fight, StateContainer::Conversation } }, std::bind(&EnvironmentController::PrintCurrentCharacters, &environmentController));
			GotoExecutable gotoExecutable("Enter", "environment name", "Enters a specific environment.", { { StateContainer::Default },	{ StateContainer::Fight, StateContainer::Conversation } }, environmentController);
			HelpExecutable helpExecutable("Help", "Lists all commands that can be executed.", { { }, { } }, parser);

			///Add executables
			parser.AddExecutable(&exitExecutable);
			parser.AddExecutable(&characterExecutable);
			parser.AddExecutable(&nearEnvironmentsExecutable);
			parser.AddExecutable(&nearCharactersExecutable);
			parser.AddExecutable(&gotoExecutable);
			parser.AddExecutable(&helpExecutable);
		}

		TEST_METHOD(Executable_Null_Check)
		{
			std::string extension = "";
			Assert::IsNotNull(parser.TryGetMatch(" Help", extension));
			Assert::IsNotNull(parser.TryGetMatch(" Help       ", extension));		
			Assert::IsNotNull(parser.TryGetMatch("hELp", extension));
			Assert::IsNotNull(parser.TryGetMatch(" Help  me", extension));
		}

		TEST_METHOD(Executable_Equal_Check)
		{
			std::string extension = "";
			Assert::IsNotNull(parser.TryGetMatch("help me", extension));

			std::string a = "me";
			std::string b = "hello";

			Assert::AreEqual(extension, a);
			Assert::AreNotEqual(extension, b);
		}
	};
}
