#pragma once
#include <vector>
#include "Token.h"

class Identifier
{
	std::string lexeme;
	std::vector<MyTokenType> type;
	bool isVariable();

public:
	Identifier(std::vector<MyTokenType>, std::string, bool);


};

