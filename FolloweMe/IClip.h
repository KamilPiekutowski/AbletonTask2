#pragma once
#include "IFollowActionFunctor.h"
class IClip
{
public:
	//virtual methods
	virtual int chooseFollowAction() = 0;
	virtual int playClip(int* idx,int clipArrSize, int* engineTickNum) = 0;
	virtual int resetTickCount() = 0;
	virtual IFollowActionFunctor* createFollowActionFunctor(std::string followActionFunctrName) = 0;
};
