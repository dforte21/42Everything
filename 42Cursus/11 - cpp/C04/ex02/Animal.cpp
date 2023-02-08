#include "Animal.hpp"

AAnimal::AAnimal( void ) : type("ă̶͇͈̰͙̖̯͜f̷̛̲̞̖̝͕̯͊ẹ̸̢̦͇̯̞͇̠̖̠͂͋̚ŗ̴̡̖̬̯͎̫̞̹̂͜͠f̴̳̈́̽̉̓ͅr̴̨̡͕̠̖͎̬̘͚͕̍̈́̀̌͑̄̓e̷̗̜̭̘̔͐͜ś̵̛̬̳͇̙͖̘͕̺̓͂̈̕͠͝"){
	std::cout << this->type << " È spawnato\n";
}

AAnimal::AAnimal( const AAnimal &copy ){
	*this = copy;
	std::cout << this->type << " È spawnato\n";
}
		
AAnimal::~AAnimal( void ){
	std::cout << this->type << " È passato a miglior vita\n";
}

AAnimal	&AAnimal::operator=( const AAnimal &copy ){
	if (this != &copy)
		this->type = copy.type;
	return (*this);
}

void	AAnimal::makeSound() const{
	std::cout << this->type << " s̸̙͙̟̞̥̬̎̈́̇̽̇̄f̷̥̝͇̠̣̱̮̱̜͆̄̿̏͋̋̎̈h̴̲̪̪͈̮̃͂̊j̵̧̝̔̉̎́͝s̷̛͔̞̥̩̪̒͊̑̋̈͝ͅj̸͕̭̘͉̟̯̑̍̏͆͝b̶̛̥͉͕̺̝̼͈͖̆̒̿́̎̏͛̚͝ś̴̮͙̻̞̤̠͓̆̓̇̆ͅḧ̴̛͚̦̟̰̟̻́̔̍͠ͅr̸̯̲̞͖̠͗̈́̀j̷͓̲͚͔͉̩̮̬̼̈̈̚ţ̷̧͉̠͛b̴͈̫̜͕͗̍̃̄̋̀͘̕̕͠ğ̵̘̺͇̉̉̔̓̋̄͗͝ͅs̷̨͚̙͗͒͌͌̀͜r̶̭̝̞͕̩̪̯̞̋͆͑̀̑̍ͅs̵̟̻̄̍͋ȓ̴͎̮̇͜ͅͅḩ̴͉͕̟̺̗́̇͛͒̂̐̆̈̈́͘t̸̪̜͔̼̓̍͂̀͌͝͝g̶̨̝͍̰͉̜̅͌̈̋̈͋͜ͅŝ̷̡̟̩̦͖͙̕͝r̴͍̄̃̒̋\n";
}

std::string	AAnimal::getType() const{
	return (this->type);
}

void	AAnimal::setType( const std::string _type ){
	this->type = _type;
}