#include "pch.h"
#include "Engine.h"


Engine::Engine()
{
}


Engine::~Engine()
{
}

void Engine::Run()
{
	getInput();
}

void Engine::runClips()
{
}

void Engine::runInputCommands(std::vector<std::string> *parsedCommands)
{
}

void Engine::addClip(Clip clip)
{

}

std::vector<std::string> Engine::getInput()
{
	std::vector<std::string> inputCommands;
	std::string command;


	while (command != "ticks")
	{
		std::getline(std::cin, command);
		std::vector<std::string> tokens = tokenizeString(command);

		command = tokens[0];

		//if clip command is clip create and add clip to clip array
		if (command == "clip")
		{
			std::string::size_type sz;

			std::string clName = tokens[1];
			int clTicksToPlay = std::stoi(tokens[2], &sz);
			double followChance1 = std::stod(tokens[3], &sz);
			double followChance2 = std::stod(tokens[4], &sz);
			IFollowActionFunctor* followAction1 = createFollowActionFunctor(tokens[5]);
			IFollowActionFunctor* followeAction2 = createFollowActionFunctor(tokens[6]);


			m_vClips.push_back(Clip(
				clName,
				clTicksToPlay,
				followChance1,
				followChance2,
				followAction1,
				followeAction2
			));
		}

	}

	return inputCommands;
}

std::vector<std::string> Engine::tokenizeString(std::string str)
{
	std::vector<std::string> tokens;

	std::istringstream iss(str);
	std::string token;
	while (std::getline(iss, token, ' '))
	{
		tokens.push_back(token);
	}

	return tokens;
}

//this a simple version of factory
IFollowActionFunctor* Engine::createFollowActionFunctor(std::string followActionFunctrName)
{
	ActionFunctorFactory aff;
	IFollowActionFunctor* followActionFunctor = aff.getActionFunctor(followActionFunctrName);

	return followActionFunctor;
}