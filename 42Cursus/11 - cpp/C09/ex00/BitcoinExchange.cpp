#include "BitcoinExchange.hpp"

Btc::Btc(){}

Btc::Btc(std::ifstream &file){
	std::string	line, data, value;
	double		valu;

	std::getline(file, line);
	while (std::getline(file, line))
	{
		std::stringstream lines(line);
		if(!getline(lines, data, ',') || !getline(lines, value))
			throw incorrectFormat();
		try{
			checkData(data);
		}
		catch(std::exception &e){
			throw incorrectData();
		}
		for (int i = 0; value[i]; i++)
			if (!std::isdigit(value[i]) && value[i] != '-' && value[i] != '.')
				throw incorrectValue();
		try{
			valu = std::stod(value);
		}
		catch(std::invalid_argument &e){
			throw incorrectValue();
		}
		if (valu < 0.0)
			throw negativeValue();
		val.insert(std::pair<std::string, double>(data, valu));
	}
}

Btc::Btc( const Btc &c ){
	*this = c;
}

Btc::~Btc(){
	this->val.clear();
}

Btc	&Btc::operator=( const Btc &c ){
	if (this == &c)
		return (*this);
	this->val.clear();
	this->val.insert(c.val.begin(), c.val.end());
	return (*this);
}

void	Btc::checkData(std::string data){
	int			anno, mese, giorno;
	std::string	value, year, month, day;

	std::stringstream datas(data);
	if(!getline(datas, year, '-') || !getline(datas, month, '-') || !getline(datas, day))
		throw incorrectData();
	if (year.length() != 4 || month.length() != 2 || day.length() != 2)
		throw incorrectData();
	for (int i = 0; i < 4; i++)
		if (!std::isdigit(year[i]))
			throw incorrectData();
	for (int i = 0; i < 2; i++)
		if (!std::isdigit(month[i]) || !std::isdigit(day[i]))
			throw incorrectData();
	try{
		anno = std::stoi(year);
		mese = std::stoi(month);
		giorno = std::stoi(day);
	}
	catch(std::invalid_argument &e){
		throw incorrectData();
	}
	if (anno < 1 || mese < 1 || mese > 12 || giorno > 31 || giorno < 1)
		throw incorrectData();
	if (mese == 2 && giorno > 28)
		if (anno % 4 != 0 && giorno > 29)
			throw incorrectData();
	if ((mese == 4 || mese == 6 || mese == 9 || mese == 11) && giorno > 30)
		throw incorrectData();
}

void	Btc::convert(std::string input){
	std::stringstream	sinput(input);
	std::string			data, amount;
	double				damount;

	if(!getline(sinput, data, '|') || !getline(sinput, amount)){
		std::cout << "Error: bad input => " << input << std::endl;
		return ;
	}

	size_t endpos = data.find_last_not_of(" ");
    data = data.substr(0, endpos + 1);

	ssize_t startpos = amount.find_first_not_of(" ");
    amount = amount.substr(startpos);

	try{
		checkData(data);
	}
	catch(std::exception &e){
		std::cout << "Error: bad input => " << input << std::endl;
		return ;
	}

	for (int i = 0; amount[i]; i++)
		if (!std::isdigit(amount[i]) && amount[i] != '-' && amount[i] != '.'){
			std::cout << "Error: bad input => " << input << std::endl;
			return ;
		}

	try{
		damount = std::stoi(amount);
	}
	catch(std::invalid_argument &e){
		std::cout << "Error: bad input => " << input << std::endl;
		return ;
	}
	catch(std::out_of_range &e){
		std::cout << "Error: too large a number.\n";
		return ;
	}

	damount = std::stod(amount);

	if (damount < 0.0)
	{
		std::cout << "Error: not a positive number.\n";
		return ;
	}

	std::map<std::string, double>::iterator it = val.lower_bound(data);
	if (it == val.end())
	{
		std::cout << "Error: date not in database.\n";
		return ;
	}

	std::cout << data << " => " << amount << " = " << damount * it->second << std::endl;	
}