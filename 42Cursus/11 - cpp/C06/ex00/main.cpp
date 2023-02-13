#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <stdexcept>
#include <iomanip>

bool	isNumber(const std::string& s) {
  try {
    std::stoi(s);
    return true;
  } catch (const std::invalid_argument&) {
    return false;
  }
}

bool	checkSpecial(std::string s[5], std::string input){
	for(int i = 0; i < 5; i++)
		if (!input.compare(s[i]))
			return (true);
	return (false);
}

void	convert(std::string in){
	int			n;
	float		f = std::stof(in);
	double		d = std::stod(in);
	char		c;

	try{
		n = std::stoi(in);
	}
	catch (const std::invalid_argument&){
		n = static_cast<int>(in[0]);
	}
	c = n;
	if (c >= 32 && c != 127)
		std::cout << "char: \'" << c << "\'\n";
	else
		std::cout << "char: Non displayable\n";
	std::cout << "int: " << n << "\nfloat: " << std::fixed << std::setprecision(1) << f << "f\ndouble: " << d << std::endl;
}

int main(int ac, char **av)
{
	std::string	in = av[1];
	std::string nan[5] = {"nan", "nanf", "inff", "+inff", "-inff"};

	if (ac != 2)
		std::cerr << "argument error\n";
	else if (checkSpecial(nan, in))
	{
		std::cout << "char: impossible\nint: impossible\n";
		if (!in.compare(nan[0]) || !in.compare(nan[1]))
			std::cout << "float: nanf\ndouble: nan\n";
		else
			std::cout << "float: " << in << "\ndouble: " << in << std::endl;
	}
	else if (!isNumber(in) || in.length() != 1)
		std::cerr << "Error:\t input is not a char/number\n";
	else
		convert(in);
	return (0);
}