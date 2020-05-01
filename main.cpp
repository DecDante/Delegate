#include <iostream>
#include <vector>

#include "A.h"
#include "B.h"
#include "DelegateHandler.h"
#include "IDelegateHandler.h"

#include "Macro_Delegate.h"

void NonmemberFunc(int value)
{
	std::cout << "NonmemberFunc: " << value << std::endl;
}

int main()
{
	A a;
	B b;

	DelegateHandler<A> ah(&a, &A::Func);
	DelegateHandler<B> bh(&b, &B::Method);
	DelegateHandler<void> vh(NonmemberFunc);

	std::vector<IDelegateHandler*> handlers;
	handlers.push_back(&ah);
	handlers.push_back(&bh);
	handlers.push_back(&vh);

	for (auto iter = handlers.begin(); iter != handlers.end(); ++iter)
	{
		(*iter)->Invoke(3);
	}

	//DELEGATE1(void, MyDelegate, int);

	return 0;
}
