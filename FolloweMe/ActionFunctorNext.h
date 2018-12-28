#pragma once
#include "FollowActionFunctor.h"
class ActionFunctorNext :
	public FollowActionFunctor
{
public:

	void operator()(int* clipArrIdx, int clipArrSize) {
		//do nothing
	};
};

