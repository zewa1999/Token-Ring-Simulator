#pragma once
#include <string>
class Calculator
{
private:
	
	unsigned short int numarCalculator;
	std::string ipCalculator;
	Calculator* next;

public:
	Calculator();
	Calculator(const unsigned short int, const std::string&);

	//GETTERS

	std::string getIpCalculator();
	Calculator* getNextCalculator();

	//SETTERS

	void setIpCalculator(const std::string&);
	void setCalculatorNextPointer(Calculator*);
};

