#include <iostream>
#include "CircularLinkedList.h"
#include "Token.h"
int main()
{
	CircularLinkedList csl;
	Calculator* head = NULL;
	Token token;
	int optiune;
	std::cout << "Bine a-ti venit in Reteaua Token Ring!\n";

	do
	{
		std::cout << "\nCe optiune doriti?\n";
		std::cout << "Optiuni:\n 0: Iesire program\n 1: Inserare Calculator\n 2: Initializare/editare Token Ring\n 3: Tranversarea Token-ului\n";
		std::cin >> optiune;
		std::cout << '\n';
		switch (optiune)
		{

		case 0:
		{
			std::cout << "La revedere!\n";
			break;
		}

		case 1:
		{
			std::cout << "Ce IP are calculatorul dvs?\n";
			std::string ipCalculator;
			std::cin >> ipCalculator;
			csl.push(&head, ipCalculator);
			std::cout << "Calculator introdus cu succes in retea!\n";
			break;
		}

		case 2:
		{
			std::cout << "Introduceti mesajul transmis token-ului\n";
			std::string mesajToken;
			std::getline(std::cin, mesajToken);
			std::cin >> mesajToken;
			token.setMessage(mesajToken);

			std::cout << "Introduceti IP ul Sursei\n";
			std::string ipSursa;
			std::cin >> ipSursa;
			token.setSourceIp(ipSursa);

			std::cout << "Introduceti IP-ul destinatiei\n";
			std::string ipDestinatie;
			std::cin >> ipDestinatie;
			token.setDestinationIp(ipDestinatie);

			std::cout << "Ce sens doriti sa aiba Token  Ring-ul: 0 - inversul acelor de ceasornic; 1- in sensul acelor de ceasornic\n";
			bool sens;
			std::cin >> sens;
			token.setSense(sens);
			if (sens == false)
			{
				csl.changeSense(csl, &head);
			}

			token.secondVerification(csl, head);
			token.firstVerification();
			break;
		}

		case 3:
		{
			csl.tokenTraverse(head, token);
			std::cout << "\n Istoricul jetonului:\n";
			token.printHistoric();

			if (!token.getSense())
			{
				csl.changeSense(csl, &head);
				token.setSense(true);
			}
			std::cout << "Sensul token ului a fost resetat\n";
			token.clearHistoric();
			std::cout << "Istoricul a fost sters\n";
			break;
		}
		default:
		{
			std::cout << "Optiune invalida\n";
			break;
		}

		}

	
	} while (optiune != 0);

}