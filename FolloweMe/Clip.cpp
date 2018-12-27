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
	m_clipName = name;
	m_iTickNum = clTicksToPlay;
	m_itickCounter = clTicksToPlay;
	createChancePool(followChance1, followChance2);

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
	while (m_itickCounter > 0)
	{
		--m_itickCounter;
		std::cout << m_clipName + " ";
	}

	resetTickCount();

	return 0;
}
int Clip::resetTickCount()
{
	m_itickCounter = m_iTickNum;

	return 0;
}

void Clip::createChancePool(double followChance1, double followChance2)
{
	int intFollowCh1 = (int) followChance1 * 10;
	int intFollowCh2 = (int) followChance2 * 10;
	int poolSize = followChance1 + followChance2;
	m_iPtrChancePool = new int[poolSize];

	//populate the chance pool;
	int idx = 0;
	for (; idx < followChance1; ++idx)
	{
		m_iPtrChancePool[idx] = ACTION_1_CHANCE;
	}
	for (; idx < poolSize; ++idx)
	{
		m_iPtrChancePool[idx] = ACTION_2_CHANCE;
	}

}