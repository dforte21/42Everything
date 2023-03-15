#include "BitcoinExchange.hpp"

int main(int ac, char **av){
	if (ac != 2)
	{
		std::cerr << "Arg error, [./btc nome_file]\n";
		return (1);
	}
	
	std::ifstream data("data.csv");
	if (!data.is_open())
	{
		std::cerr << "Errore nell'apertura del file data\n";
		return (1);
	}

	std::ifstream input(av[1]);
	if (!input.is_open())
	{
		std::cerr << "Errore nell'apertura del file di input\n";
		return (1);
	}

	try{
		BTC b(data);
		std::string in;
		std::getline(input, in);
		while (std::getline(input, in))
			b.convert(in);
	}
	catch(std::exception &e){
		std::cerr << e.what();
		return (1);
	}
	
	data.close();
	input.close();
}