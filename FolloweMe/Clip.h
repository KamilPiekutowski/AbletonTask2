#pragma once
#include <string>
#include "IClip.h"
#include "IFollowActionFunctor.h"
#include <iostream>
class Clip :
	public IClip
{
	enum
	{
		ACTION_1_CHANCE = 1,
		ACTION_2_CHANCE = 2
	};
public:
	//cons/destrutor
	Clip(
		std::string name,
		int clTicksToPlay,
		double followChance1,
		double followChance2,
		IFollowActionFunctor* followAction1,
		IFollowActionFunctor* followAction2);
	~Clip();

	//members
	std::string m_clipName;
	int m_iTickNum;
	int m_itickCounter;
	int * m_iPtrChancePool;
	

	//methods
	IFollowActionFunctor* FollowAction1; //this behaves like a method
	IFollowActionFunctor* FollowAction2; //this behaves like a method

	int chooseFollowAction();
	int playClip(int* idx, int clipArrSize, int* engineTickNum);
	int resetTickCount();
	void createChancePool(double followChance1, double followChance2);
};

