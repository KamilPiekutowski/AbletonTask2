#pragma once
#include "FollowActionFunctor.h"
class ActionFunctorNone :
	public FollowActionFunctor
{
public:

	void operator()(int* clipArrIdx, int clipArrSize) {
		*clipArrIdx = clipArrSize;
	};
};

