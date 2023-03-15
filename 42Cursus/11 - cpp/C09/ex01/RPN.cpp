#include "RPN.hpp"

RPN::RPN(){}

RPN::RPN( std::string &expr ){
	if (!std::isdigit(expr[0]) || expr[1] != ' ')
		throw invalidExpression();
	for (size_t i = 2; i < expr.length(); i += 4)
	{
		if (!std::isdigit(expr[i]))
			throw invalidExpression();
		if (expr[i + 1] != ' ')
			throw invalidExpression();
		if (expr[i + 2] != '-' && expr[i + 2] != '+' && expr[i + 2] != '*' && expr[i + 2] != '/')
			throw invalidExpression();
	}
	std::string num;
	for (int i = expr.length() - 1; i > 0; i -= 4){
		num = std::string(1, expr[i - 2]);
		numbers.push(atoi(num.c_str()));
		operands.push(expr[i]);
	}
	num = std::string(1, expr[0]);
	numbers.push(atoi(num.c_str()));
}

RPN::RPN( const RPN &c ){
	*this = c;
}

RPN::~RPN(){
	while (numbers.size() > 0)
		numbers.pop();
	while (operands.size() > 0)
		operands.pop();
}

RPN	&RPN::operator=( const RPN &c ){
	if (this == &c)
		return (*this);
	while (this->numbers.size() > 0)
		numbers.pop();
	while (this->operands.size() > 0)
		operands.pop();
	this->numbers = c.numbers;
	this->operands = c.operands;
	return (*this);
}

void	RPN::printSolution(){
	int n1, n2;
	char op;

	n1 = numbers.top();
	numbers.pop();
	while (numbers.size() > 0)
	{
		n2 = numbers.top();
		numbers.pop();
		op = operands.top();
		operands.pop();
		switch (op)
		{
		case '+':
			n1 += n2;
			break;
		case '-':
			n1 -= n2;
			break;
		case '*':
			n1 *= n2;
			break;
		case '/':
			n1 /= n2;
		}
	}
	std::cout << n1 << std::endl;
}