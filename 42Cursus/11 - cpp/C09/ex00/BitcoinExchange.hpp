#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <map>
#include <iostream>
#include <sstream>
#include <fstream>
#include <exception>
#include <string>

class BitcoinExchange{
	private:
		std::map<std::string, double> val;
	public:
		BitcoinExchange();
		BitcoinExchange(std::ifstream &file);
		BitcoinExchange( const BitcoinExchange &c );
		~BitcoinExchange();

		BitcoinExchange	&operator=( const BitcoinExchange &c );

		void	checkData(std::string data);
		void	convert(std::string input);

		class incorrectData : public std::exception{
			public:
				virtual const char *what() const throw(){
					return ("ERROR\tIncorrect Data Format, [yyyy-mm-dd]\n");
				}
		};
		class incorrectValue : public std::exception{
			public:
				virtual const char *what() const throw(){
					return ("ERROR\tIncorrect value, value is not a number\n");
				}
		};
		class incorrectFormat : public std::exception{
			public:
				virtual const char *what() const throw(){
					return ("ERROR\tIncorrect input format, [data,value]\n");
				}
		};
		class negativeValue : public std::exception{
			public:
				virtual const char *what() const throw(){
					return ("ERROR\tNegative Value, [value > 0]\n");
				}
		};
};

#endif