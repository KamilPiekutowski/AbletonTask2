#include "pch.h"
#include "ActionFunctorFactory.h"


IFollowActionFunctor* ActionFunctorFactory::getActionFunctor(std::string followActionFunctrName)
{
	if (followActionFunctrName == "any")
	{
		return new ActionFunctorAny();
	}
	else if (followActionFunctrName == "other")
	{
		return new ActionFunctorOther();
	}
	else if (followActionFunctrName == "next")
	{
		return new ActionFunctorNext();
	}
	else if (followActionFunctrName == "previous")
	{
		return new ActionFunctorPrevious();
	}
	else if (followActionFunctrName == "none")
	{
		return new ActionFunctorNone();
	}
	else
	{
		return NULL;
	}
}
