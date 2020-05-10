#include "Token.h"
#include "CircularLinkedList.h"
Token::Token()
{
}

Token::Token(const std::string& ipSursa, const std::string& ipDestinatie, const std::string& mesajTransmis)
{
	this-> sourceIp = ipSursa;
	this-> destinationIp = ipSursa;
	this-> message = mesajTransmis;
	this-> gotToDestination = false;
	this-> isFree = false;
	this->sense = true;
	historic.clear();
}

void Token::setSourceIp(const std::string& ipSursa)
{
	this->sourceIp = ipSursa;
}

void Token::setDestinationIp(const std::string& ipDestinatie)
{
	this->destinationIp = ipDestinatie;

}

void Token::setMessage(const std::string& mesaj)
{
	this->message = mesaj;
}

void Token::setIsFree(const bool& flag )
{
	this->gotToDestination = flag;
}

void Token::setGotToDestination(const bool& flag)
{
	this->gotToDestination = flag;
}

void Token::addInHistoric(const std::string& ipCalculator)
{
	this->historic.push_back(ipCalculator);
}

void Token::clearHistoric()
{
	this->historic.clear();
}

void Token::printHistoric() const
{
	for (auto& iterator : historic)
	{
		std::cout << iterator << '\n';
	}
}

void Token::setSense(const bool& sens)
{
	this->sense = sens;
}

std::string Token::getDestinationIp() const
{
	return this->destinationIp;
}

std::string Token::getSourceIp() const
{
	return this->sourceIp;
}

std::string Token::getMessage() const
{
	return this->message;
}

bool Token::getSense() const
{
	return this->sense;
}

bool Token::firstVerification()
{
	if (destinationIp != sourceIp)
	{
		std::cout << "IP-urile sunt diferite\n";
		return true;
	}

	return false;
}

bool Token::secondVerification(CircularLinkedList& calculatorCircularLS, Calculator* head)
{
	Calculator* temp = head;
	bool okSource = false;
	bool okDestination = false;

	if (head != NULL)
	{
		do
		{
			if (temp->getIpCalculator() == sourceIp)
			{
				okSource = true;
			}
			if (temp->getIpCalculator() == destinationIp)
			{
				okDestination = true;
			}
			temp = temp->getNextCalculator();
		} while (temp != head);

	}
	
	if (okSource == false && okDestination == false)
	{
		std::cout << "Niciun IP nu este valid\n";
		return false;
	}

	if (okSource == false)
	{
		std::cout << "IP ul sursei e invalid\n";
		return false;
	}

	if (okDestination == false)
	{
		std::cout << "IP ul destinatiei e invalid\n";
		return false;
	}

	std::cout << "IP-urile sunt prezente in reteaua de calculatoare\n";
	return true;
}
