#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "Clip.h"
#include "ActionFunctorFactory.h"

class Engine
{
public:
	//cons/destructor
	Engine();
	~Engine();

	//members
	int m_iTickNum;
	int m_iTickCOunter;
	std::vector<Clip*> m_vClips;
	std::vector<std::vector<std::string>> m_vInputCommands;

	//methods
	void Run();
	void runClips();
	void getInput();

private:
	//private methods
	std::vector<std::string> tokenizeString(std::string str);
};

