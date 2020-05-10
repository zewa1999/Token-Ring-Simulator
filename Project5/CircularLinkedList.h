#pragma once
#include <iostream>
#include "Calculator.h"
#include "Token.h"
class CircularLinkedList
{
public:
	void push(Calculator**, const std::string&);
	int search(Calculator*, std::string ipSursa);
	void tokenTraverse(Calculator*, Token&);
	void changeSense(CircularLinkedList&, Calculator**);
};

