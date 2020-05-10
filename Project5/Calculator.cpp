#include "Calculator.h"

Calculator::Calculator()
{
}

Calculator::Calculator(const unsigned short int nrCalculator, const std::string& ip)
{
	this->ipCalculator = ip;
	this->numarCalculator = nrCalculator;
}

std::string Calculator::getIpCalculator()
{
	return this->ipCalculator;
}

Calculator* Calculator::getNextCalculator()
{
	return this->next;
}

void Calculator::setIpCalculator(const std::string& ipCalculator)
{
	this->ipCalculator = ipCalculator;
}

void Calculator::setCalculatorNextPointer(Calculator* nextCalculator)
{
	this->next = nextCalculator;
}
