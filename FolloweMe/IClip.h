#pragma once
class IClip
{
public:
	//cons/destrutor
	IClip() {};
	~IClip() {};

	//virtual methods
	virtual int chooseFollowAction() = 0;
	virtual int playClip() = 0;
	virtual int resetTickCount() = 0;
};

