#pragma once
#include "Lexer.h"
#include "ParserState.h"

//enum class WhatDoin
//{
//	DECL_VAR,
//	INIT_VAR,
//
//	DECL_FUNC,
//	DESCR_FUNC,
//	CALL_FUNC,
//};

class Parser
{
	std::vector<Token> tokens;
	std::vector<ParserState> states;
	std::vector<Token> temp;
	int curPos = 0;

public:
	void Parse(std::vector<Token>&);

	void Transition();

	//Token expectations
	void DataTypeExpectation();

	void IdentifierExpectation();

	void BinaryOpExpectation();
	void UnaryOpExpectation();

	void ForExpectation();
	void DoExpectation();
	void WhileExpectation();

	void StructExpectation();
	void EnumExpectation();

	void ReturnExpectation();

	void BreakExpectation();
	void ContinueExpectation();

	void GotoExpectation();

	// for my task
	void CheckForCorrectBreak();
};
