#include <cstdlib>
#include <ctime>
#include <iostream>

#include <unistd.h>

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	std::srand(std::time(NULL));
	int rand = std::rand() % 3;

	switch(rand)
	{
		case 0:
			return new A();
			break;
		case 1:
			return new B();
			break;
		case 2:
			return new C();
			break;
		default:
			return NULL;
			break;
	}
}

void identify(Base *p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		(void) a;
		std::cout << "A" << std::endl;
	}
	catch (const std::exception& e)
	{
		try
		{
			B &b = dynamic_cast<B &>(p);
			(void) b;
			std::cout << "B" << std::endl;
		}
		catch (const std::exception& e)
		{
			try
			{
				C &c = dynamic_cast<C&>(p);
				(void) c;
				std::cout << "C" << std::endl;
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
	}
}

int main(void) {
	Base	*ptr;

	ptr = generate();
	identify(ptr);

	delete ptr;

	sleep(1);

	ptr = generate();
	identify(*ptr);

	delete ptr;

	return (0);
}