#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <unordered_set>
#include <iostream>
#include <ctime>
#include <cmath>
#include <exception>

class PmergeMe{
	private:
		std::vector<int>		vNumber;
		std::unordered_set<int>	sNumber;
		clock_t					start;
		clock_t					end;
		size_t					size;
		
		PmergeMe();
	public:
		PmergeMe( char **av );
		PmergeMe( const PmergeMe &c );
		~PmergeMe();

		PmergeMe	&operator=( const PmergeMe &c );

		void	vStartSort();
		void	sStartSort();
		void	vMerge(int left, int mid, int right);
		void	vMergeInsert(int left, int right, int k);

		class invalidNumber : public std::exception{
			virtual const char *what() const throw(){
				return ("Error, inserito numero non valido\n");
			}
		};

		class duplicateNumber : public std::exception{
			virtual const char *what() const throw(){
				return ("Error, i numeri non devono essere duplicati\n");
			}
		};

		class alreadyOrdered : public std::exception{
			virtual const char *what() const throw(){
				return ("Error, i numeri sono già ordinati\n");
			}
		};
};

bool		checkNum( std::string n );

#endif