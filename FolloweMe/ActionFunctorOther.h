#pragma once
#include "FollowActionFunctor.h"
class ActionFunctorOther :
	public FollowActionFunctor
{
public:
	ActionFunctorOther();
	~ActionFunctorOther();
	void operator()(int* clipArrIdx, int clipArrSize) {
		srand(time(NULL));

		int otherClipArrIdx = *clipArrIdx;

		while (otherClipArrIdx == *clipArrIdx)
		{
			otherClipArrIdx = rand() % (clipArrSize-1);
		}
		
		*clipArrIdx = otherClipArrIdx;
	};
};

