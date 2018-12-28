#include "pch.h"
#include "Clip.h"
#include "ActionFunctorFactory.h"


Clip::Clip(
	std::string name,
	int clTicksToPlay,
	double followChance1,
	double followChance2,
	std::string followAction1,
	std::string followAction2)
{
	m_clipName = name;
	m_iTickNum = clTicksToPlay;
	m_itickCounter = clTicksToPlay;
	createChancePool(followChance1, followChance2);

	FollowAction1 = createFollowActionFunctor(followAction1);
	FollowAction2 = createFollowActionFunctor(followAction2);
}


Clip::~Clip()
{
	if(m_iPtrChancePool != NULL)
	{ 
		delete m_iPtrChancePool;
		m_iPtrChancePool = NULL;
	}

	if (FollowAction1 != NULL)
	{
		delete FollowAction1;
		FollowAction1 = NULL;
	}

	if (FollowAction2 != NULL)
	{
		delete FollowAction2;
		FollowAction1 = NULL;
	}
}

int Clip::chooseFollowAction()
{
	return 0;
}
int Clip::playClip(int* idx, int clipArrSize, int* engineTickNum)
{
	while (m_itickCounter > 0 && *engineTickNum > 0)
	{
		--m_itickCounter; --(*engineTickNum);
		std::cout << m_clipName + " ";
	}

	if(*engineTickNum > 0) //only if there are any ticks left from the engine
	{ 
		if (chooseFollowAction() == ACTION_1_CHANCE)
		{
			(*FollowAction1)(idx, clipArrSize);
		}
		else
		{
			(*FollowAction2)(idx, clipArrSize);
		}
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

//this a simple version of factory
IFollowActionFunctor* Clip::createFollowActionFunctor(std::string followActionFunctrName)
{
	ActionFunctorFactory aff;
	IFollowActionFunctor* followActionFunctor = aff.getActionFunctor(followActionFunctrName);

	return followActionFunctor;
}