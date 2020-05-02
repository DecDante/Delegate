#include <iostream>
#include <vector>

#include "A.h"
#include "B.h"
#include "DelegateHandler.h"
#include "IDelegateHandler.h"

#include "Macro_Delegate.h"

DELEGATE1(void, MyDelegate1, int);

void NonmemberFunc(int value)
{
	std::cout << "NonmemberFunc: " << value << std::endl;
}

int main()
{
	A a;
	B b;

	//DelegateHandler<A> ah(&a, &A::Func);
	//DelegateHandler<B> bh(&b, &B::Method);
	//DelegateHandler<void> vh(NonmemberFunc);

	MyDelegate1<A> ah(&a, &A::Func);
	MyDelegate1<B> bh(&b, &B::Method);
	MyDelegate1<void> vh(NonmemberFunc);

	std::vector<IMyDelegate1*> handlers;
	handlers.push_back(&ah);
	handlers.push_back(&bh);
	handlers.push_back(&vh);

	for (auto iter = handlers.begin(); iter != handlers.end(); ++iter)
	{
		(*iter)->Invoke(3);
	}

	return 0;
}
