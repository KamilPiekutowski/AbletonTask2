#pragma once
#include <time.h>
#include <stdlib.h>
#include "IFollowActionFunctor.h"
class FollowActionFunctor :
	public IFollowActionFunctor
{
public:
	void operator()(int* clipArrIdx, int clipArrSize) {};
};
