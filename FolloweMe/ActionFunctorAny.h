#pragma once
#include "FollowActionFunctor.h"

class ActionFunctorAny :
	public FollowActionFunctor
{
public:
	void operator()(int* clipArrIdx, int clipArrSize) {
		srand(time(NULL));
		*clipArrIdx = rand() % (clipArrSize-1);
	};
};

