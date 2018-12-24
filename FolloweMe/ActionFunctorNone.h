#pragma once
#include "FollowActionFunctor.h"
class ActionFunctorNone :
	public FollowActionFunctor
{
public:
	ActionFunctorNone();
	~ActionFunctorNone();
	void operator()(int* clipArrIdx, int clipArrSize) {
		*clipArrIdx = clipArrSize;
	};
};

