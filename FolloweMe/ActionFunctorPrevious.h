#pragma once
#include "FollowActionFunctor.h"
class ActionFunctorPrevious :
	public FollowActionFunctor
{
public:

	void operator()(int* clipArrIdx, int clipArrSize) {
		(*clipArrIdx)--; (*clipArrIdx)--;
		if ((*clipArrIdx) < -1)
		{
			(*clipArrIdx) = -1;
		}
	};
};

