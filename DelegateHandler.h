#pragma once

#include "IDelegateHandler.h"

template <typename T>
class DelegateHandler: public IDelegateHandler
{
public:
	DelegateHandler(T* pT, void (T::*pFunc)(int))
		:m_pT(pT), m_pFunc(pFunc)
	{
	}

	virtual void Invoke(int value)
	{
		(m_pT->*m_pFunc)(value);
	}

private:
	T* m_pT;
	void (T::*m_pFunc)(int);
};

template <>
class DelegateHandler<void>: public IDelegateHandler
{
public:
	DelegateHandler(void (*pFunc)(int))
		:m_pFunc(pFunc)
	{
	}

	virtual void Invoke(int value)
	{
		(*m_pFunc)(value);
	}

private:
	void (*m_pFunc)(int);
};
