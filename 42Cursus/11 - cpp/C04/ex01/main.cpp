#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

#define N 4

int main()
{
	const Animal	**a = new const Animal*[N]();
	int i = 0;

	for (i = 0; i < N / 2; i++)
		a[i] = new Dog();

	for (; i < N; i++)
		a[i] = new Cat();

	for (i = 0; i < N; i++)
	{
		std::cout << a[i]->getType() << " ";
		a[i]->makeSound();
		a[i]->printIdea(i);
	}

	for (i = 0; i < N; i++)
		delete (a[i]);

	delete[] (a);
	return 0;
}