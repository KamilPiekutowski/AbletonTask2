#pragma once
class IFollowActionFunctor
{
public:
	virtual void operator()(int* clipArrIdx, int clipArrSize) = 0;
};

