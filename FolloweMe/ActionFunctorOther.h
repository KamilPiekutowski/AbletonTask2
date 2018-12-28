#pragma once
#include "FollowActionFunctor.h"
class ActionFunctorOther :
	public FollowActionFunctor
{
public:

	void operator()(int* clipArrIdx, int clipArrSize) {
		srand(time(NULL));

		int otherClipArrIdx = *clipArrIdx;

		while (otherClipArrIdx == *clipArrIdx)
		{
			otherClipArrIdx = (rand() % clipArrSize);
		}
		
		*clipArrIdx = otherClipArrIdx -1;
	};
};

