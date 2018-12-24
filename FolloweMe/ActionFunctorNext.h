#pragma once
#include "FollowActionFunctor.h"
class ActionFunctorNext :
	public FollowActionFunctor
{
public:
	ActionFunctorNext();
	~ActionFunctorNext();
	void operator()(int* clipArrIdx, int clipArrSize) {
		(*clipArrIdx)++;
	};
};

