#include "Reader.h"
#include <iostream>


Reader::Reader(Parser& _parser, StateMachine& _stateMachine)
	: parser(_parser), stateMachine(_stateMachine), isReading(false)
{
}

void Reader::Start()
{
	isReading = true;
	stateMachine.EnableState(StateContainer::State::Default);

	std::cout << "----------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "-----------------------------------------|/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\|-------------------------" << std::endl;
	std::cout << "-------------------------------------------WELCOME TO THE DIALOGUEDUNGEON---------------------------" << std::endl;
	std::cout << "-----------------------------------------|/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\|-------------------------" << std::endl;
	std::cout << "----------------------------------------------------------------------------------------------------" << std::endl;
	std::cout << "                          @@/(@@@                                                                   " << std::endl;
	std::cout << "                                 @*                              @@@@@@@@@@@                        " << std::endl;
	std::cout << "                                 @@                           @@@@@#@@@@@@@@@@@                     " << std::endl;
	std::cout << "                                @@                          @@@@@@@         @@@@                    " << std::endl;
	std::cout << "                         .@@@@@@@@@@@                      @@@@@@             @@@   @@@    @@@@     " << std::endl;
	std::cout << "                      @@@@@@@@@@@@@@@@@@                   @@@.@@             @@@ #@          @@    " << std::endl;
	std::cout << "                    @@     @ @     @@@@@@*                 @@@.@&      @      @@. &           &@@   " << std::endl;
	std::cout << "                  .*       @@@      @@@@@@                 *@@@@/.     @  ,@@@/     /@@(      &@@   " << std::endl;
	std::cout << "                           %.@@     @@@@@@.                 @@@@@@ /                        @@&@    " << std::endl;
	std::cout << "                               @@  @@@@@@@                   @@@@@@@@           *%*//(&&&#&@@@     ." << std::endl;
	std::cout << "        .*.        @          .  @@@@@@@@                     .@@@ @@@@     @@@@@@@@@@@@@@@@%......." << std::endl;
	std::cout << "     @@@#  *@,         .&@@@@@@@@@@@@@@@                        @@@%@  @  @@@@@@@@@@%@@@@@@%@@@....." << std::endl;
	std::cout << "....@@@      @              @@@@@@@@@@.@                         #@@@@@ @@@@@@@@@@@@#........(&@@..." << std::endl;
	std::cout << "....@@@@ .                *@@@@@@@@@ @@@@                          @@&@@@@@@@@@@@@.............@@..." << std::endl;
	std::cout << ".....@@@@...... @@  @ ,@ ,@@@@@@@@@@@ @  @                     .@@@@@@/@@@@@@@@@@........*.....*@..." << std::endl;
	std::cout << "......@@@@@@@/@@@/@@@@@@@,@@@@@@@@*@@.@@@@,                  .%@@..*@@@@@@@@@#@@@@@ ....@......&...." << std::endl;
	std::cout << "----------------------------------------------------------------------------------------------------" << std::endl << std::endl;
}

void Reader::Stop()
{
	isReading = false;
	std::cout << "--Game Over!--" << std::endl;	
}

void Reader::Listen()
{
	std::cout << PREFIX;

	std::string input;
	std::getline(std::cin, input);

	if (input != "")
	{
		std::string extension = "";
		Executable* executable = parser.TryGetMatch(input, extension);

		if (executable != nullptr)
		{
			std::cout << "----------------------------------------------------------------------------------------------------" << std::endl;
			executable->Execute(stateMachine, extension);
			std::cout << "----------------------------------------------------------------------------------------------------" << std::endl;
		}
		else
		{
			std::cout << PREFIX << "Key not valid." << std::endl;
		}
	}
}

bool Reader::IsReading() const { return isReading; }