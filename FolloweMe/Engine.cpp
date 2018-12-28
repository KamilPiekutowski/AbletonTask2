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
	runClips();
}

void Engine::runClips()
{
	for (int idx = 0; (idx < m_vClips.size()) && m_iTickNum > 0; idx++)
	{
		m_vClips[idx].playClip(&idx, m_vClips.size(), &m_iTickNum);

		int a = idx;

		int b = 0;
	}
}

void Engine::runInputCommands(std::vector<std::string> *parsedCommands)
{
}

void Engine::addClip(Clip clip)
{

}

void Engine::getInput()
{
	std::vector<std::string> inputCommands;
	std::string command;
	std::vector<std::string> tokens;


	while (command != "ticks")
	{
		std::getline(std::cin, command);
		tokens = tokenizeString(command);

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

	//get engine tick count
	std::string::size_type sz;

	m_iTickNum = std::stoi(tokens[1], &sz);
	m_iTickCOunter = m_iTickNum;
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