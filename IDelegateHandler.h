#pragma once

class IDelegateHandler
{
public:
	virtual ~IDelegateHandler()
	{}

	virtual void Invoke(int value) = 0;
};
