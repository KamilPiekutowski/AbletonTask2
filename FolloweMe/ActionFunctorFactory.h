#pragma once

#include <string>
#include "ActionFunctorAny.h"
#include "ActionFunctorNext.h"
#include "ActionFunctorNone.h"
#include "ActionFunctorOther.h"
#include "ActionFunctorPrevious.h"

class ActionFunctorFactory
{
public:
	IFollowActionFunctor* getActionFunctor(std::string followActionFunctrName);
};

