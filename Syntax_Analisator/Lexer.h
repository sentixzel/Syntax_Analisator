#pragma once
#include <iostream>
#include "FormatText.h"
#include "Token.h"

enum class LexerState
{
	DEFAULT,
	IN_STRING,
	IN_CHAR,
};

class Lexer
{
	std::string code;
	std::vector<Token> tokens;

	int iter = 0;
	void Split();
	void Merge();
	void DeleteSpaces();
	bool IsComplexToken(char, char);
	bool IsSepareteSymbol(char);

public:
	Lexer(std::string);
	std::vector<Token> GetTokens();

	void print();	
};

