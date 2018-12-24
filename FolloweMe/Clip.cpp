#include "pch.h"
#include "Clip.h"


Clip::Clip(
	std::string name,
	int clTicksToPlay,
	double followChance1,
	double followChance2,
	IFollowActionFunctor* followAction1,
	IFollowActionFunctor* followAction2)
{
	clipName = name;
	m_iTickNum = clTicksToPlay;
	m_itickCounter = clTicksToPlay;
	int * m_iPtrChancePool = createChancePool(followChance1, followChance2);

	FollowAction1 = followAction1;
	FollowAction2 = followAction2;
}


Clip::~Clip()
{
}

int Clip::chooseFollowAction()
{
	return 0;
}
int Clip::playClip()
{
	return 0;
}
int Clip::resetTickCount()
{
	m_itickCounter = m_iTickNum;
	return 0;
}

int* Clip::createChancePool(double followChance1, double followChance2)
{
	int intFollowCh1 = (int) followChance1 * 10;
	int intFollowCh2 = (int) followChance2 * 10;
	int poolSize = followChance1 + followChance2;
	int* newChancePool = new int[poolSize];

	//populate the chance pool;
	int idx = 0;
	for (; idx < followChance1; ++idx)
	{
		newChancePool[idx] = ACTION_1_CHANCE;
	}
	for (; idx < poolSize; ++idx)
	{
		newChancePool[idx] = ACTION_2_CHANCE;
	}

	return newChancePool;
}