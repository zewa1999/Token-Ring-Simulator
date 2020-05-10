#include "CircularLinkedList.h"
#include "Token.h"
void CircularLinkedList::push(Calculator** head_ref, const std::string& ip)
{
	Calculator* ptr1 = new Calculator;
	Calculator* temp = *head_ref;
	ptr1->setIpCalculator(ip);
	ptr1->setCalculatorNextPointer(*head_ref);

	if (*head_ref != NULL)
	{
		while (temp->getNextCalculator() != *head_ref)
			temp = temp->getNextCalculator();
		temp->setCalculatorNextPointer(ptr1);
	}
	else
		ptr1->setCalculatorNextPointer(ptr1);

	*head_ref = ptr1;
}

int CircularLinkedList::search(Calculator* head, std::string ipSursa)
{
	int index = 1;
	Calculator* current = head;

	do
	{
		
		if (current == NULL)
			return -1;

		if (current->getIpCalculator() == ipSursa)
		{
			return index;
		}
		current = current->getNextCalculator();
		index++;
	} while (current != head);

	return -1;
}


void CircularLinkedList::tokenTraverse(Calculator* head, Token& token)
{

	Calculator* temp = head;
	int pozitieIpSursa = search(head, token.getSourceIp());
	int index = 1;
	while (index != pozitieIpSursa)
	{
		temp = temp->getNextCalculator();
		index++;
	}
	{
		do
		{
			token.addInHistoric(temp->getIpCalculator());
			std::cout << temp->getIpCalculator() << '\n';
			
			if (temp->getIpCalculator() == token.getDestinationIp())
			{
				std::cout << "Token-ul a ajuns la destinatie\n";
				std::cout << "Mesajul Token-ului este: " << token.getMessage()<<'\n';
				token.setGotToDestination(true);
			}

			temp = temp->getNextCalculator();

		} while (temp->getIpCalculator() != token.getSourceIp());

		token.addInHistoric(temp->getIpCalculator());
		token.setIsFree(true);
		std::cout << temp->getIpCalculator() << '\n';
		std::cout << "Jeton eliberat!\n";
	}
}



void CircularLinkedList::changeSense(CircularLinkedList& cls, Calculator** head_ref )
{

    if (*head_ref == NULL)
        return;

    Calculator* prev = NULL;
    Calculator* current = *head_ref;
    Calculator* next;
    do {
        next = current->getNextCalculator();
        current->setCalculatorNextPointer(prev);
        prev = current;
        current = next;
    } while (current != (*head_ref));

    (*head_ref)->setCalculatorNextPointer(prev);
    *head_ref = prev;

}

