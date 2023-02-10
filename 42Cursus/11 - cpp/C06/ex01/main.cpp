#include "Data.hpp"

uintptr_t	serialize(Data* ptr){
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data*		deserialize(uintptr_t raw){
	return (reinterpret_cast<Data *>(raw));
}

int main(){
	Data		a(42);
	uintptr_t	p;
	Data		*b;

	p = serialize(&a);
	b = deserialize(p);

	std::cout << "a address: " << &a << "\na after serialize: " << p << "\nb value after deserialize: " << b << std::endl;
	std::cout << b->getData() << std::endl;
}