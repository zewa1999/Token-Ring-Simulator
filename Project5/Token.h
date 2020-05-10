#pragma once
#include <string>
#include <list>
#include "Calculator.h"
class CircularLinkedList;

class Token
{
private:

	std::string sourceIp;
	std::string destinationIp;
	std::string message;
	bool gotToDestination;
	bool isFree;
	bool sense; // false = inversul acelor de ceasornic; true = sensul acelor de ceasornic
	std::list<std::string> historic;

public:
	Token();
	Token(const std::string& , const std::string&, const std::string&);
	
	void addInHistoric(const std::string&);
	void clearHistoric();
	void printHistoric() const;


	//SETTERI

	void setSense(const bool&);
	void setSourceIp(const std::string&);
	void setDestinationIp(const std::string&);
	void setMessage(const std::string&);
	void setIsFree(const bool&);
	void setGotToDestination(const bool&);

	//GETTERI

	std::string getDestinationIp() const ;
	std::string getSourceIp() const;
	std::string getMessage() const;
	bool getSense() const;
	

	//VERIFICARI

	bool firstVerification(); // sursa!=destinatie
	bool secondVerification(CircularLinkedList&, Calculator* head); // sursa sa se gaseasca in retea

};
