#include "Animal.hpp"

Animal::Animal( void ) : type("ă̶͇͈̰͙̖̯͜f̷̛̲̞̖̝͕̯͊ẹ̸̢̦͇̯̞͇̠̖̠͂͋̚ŗ̴̡̖̬̯͎̫̞̹̂͜͠f̴̳̈́̽̉̓ͅr̴̨̡͕̠̖͎̬̘͚͕̍̈́̀̌͑̄̓e̷̗̜̭̘̔͐͜ś̵̛̬̳͇̙͖̘͕̺̓͂̈̕͠͝"){
	std::cout << this->type << " È spawnato\n";
}

Animal::Animal( const Animal &copy ){
	*this = copy;
	std::cout << this->type << " È spawnato\n";
}
		
Animal::~Animal( void ){
	std::cout << this->type << " È passato a miglior vita\n";
}

Animal	&Animal::operator=( const Animal &copy ){
	if (this != &copy)
		this->type = copy.type;
	return (*this);
}

void	Animal::makeSound() const{
	std::cout << this->type << " s̸̙͙̟̞̥̬̎̈́̇̽̇̄f̷̥̝͇̠̣̱̮̱̜͆̄̿̏͋̋̎̈h̴̲̪̪͈̮̃͂̊j̵̧̝̔̉̎́͝s̷̛͔̞̥̩̪̒͊̑̋̈͝ͅj̸͕̭̘͉̟̯̑̍̏͆͝b̶̛̥͉͕̺̝̼͈͖̆̒̿́̎̏͛̚͝ś̴̮͙̻̞̤̠͓̆̓̇̆ͅḧ̴̛͚̦̟̰̟̻́̔̍͠ͅr̸̯̲̞͖̠͗̈́̀j̷͓̲͚͔͉̩̮̬̼̈̈̚ţ̷̧͉̠͛b̴͈̫̜͕͗̍̃̄̋̀͘̕̕͠ğ̵̘̺͇̉̉̔̓̋̄͗͝ͅs̷̨͚̙͗͒͌͌̀͜r̶̭̝̞͕̩̪̯̞̋͆͑̀̑̍ͅs̵̟̻̄̍͋ȓ̴͎̮̇͜ͅͅḩ̴͉͕̟̺̗́̇͛͒̂̐̆̈̈́͘t̸̪̜͔̼̓̍͂̀͌͝͝g̶̨̝͍̰͉̜̅͌̈̋̈͋͜ͅŝ̷̡̟̩̦͖͙̕͝r̴͍̄̃̒̋\n";
}

std::string	Animal::getType() const{
	return (this->type);
}

void	Animal::setType( const std::string _type ){
	this->type = _type;
}