#include "Parser.h"

void Parser::Parse(std::vector<Token> tokens)
{
	this->tokens = tokens;
	states.push_back(ParserState::DEFAULT);
	//temp.push_back(this->tokens[curPos]);
	
	//Transition();

	//checking break
	CheckForCorrectBreak();
}

void Parser::Transition()
{
	switch (states.back())
	{
	case ParserState::DEFAULT:
		switch (tokens[curPos].Type())
		{
		case MyTokenType::_EXTERN:
		case MyTokenType::_STATIC:
		case MyTokenType::_VOLATILE:
			break;

		case MyTokenType::_UNSIGND:
		case MyTokenType::_SIGND:
		case MyTokenType::_SHORT:
		case MyTokenType::_LONG:
			break;

		case MyTokenType::_INT:
		case MyTokenType::_FLOAT:
		case MyTokenType::_DOUBLE:
		case MyTokenType::_CHAR:
		case MyTokenType::_AUTO:
		case MyTokenType::_VOID:
			DataTypeExpectation();
			break;

		case MyTokenType::_STRUCT:
		case MyTokenType::_UNION:
			break;

		case MyTokenType::_ENUM:
			break;

		default:
			std::string message = "Error at line: ";
			message += std::to_string(tokens[curPos].Line());
			message += " : expected declaration.\n";
			throw(message);
		}
		break;
	case ParserState::IN_MATH:
	case ParserState::IN_FUNCTION:
	case ParserState::IN_FOR:
	case ParserState::IN_WHILE:
	case ParserState::IN_DO:
	case ParserState::IN_STRUCT: // also union
	case ParserState::IN_ENUM:
	case ParserState::IN_BRA:
	case ParserState::IN_PAR:
	case ParserState::IN_SQR:
		break;
	}
}

void Parser::DataTypeExpectation()
{
	curPos++;

	switch (states.back())
	{
	case ParserState::DEFAULT:
		switch (tokens[curPos].Type())
		{
		case MyTokenType::_IDENTIFIER:
			//IdentifierExpectation();
			break;
		case MyTokenType::_STAR:
		case MyTokenType::_AMPERSAND:
			//UnaryOpExpectation();
			break;
		default:
			std::string message = "Error at line ";
			message += std::to_string(tokens[curPos].Line());
			message += ": expected identifier.\n";
			throw(message);
		}
		break;
	case ParserState::IN_MATH:
	case ParserState::IN_FUNCTION:
	case ParserState::IN_FOR:
	case ParserState::IN_WHILE:
	case ParserState::IN_DO:
	case ParserState::IN_STRUCT: // also union
	case ParserState::IN_ENUM:
	case ParserState::IN_BRA:
	case ParserState::IN_PAR:
	case ParserState::IN_SQR:
	default:
		break;
	}
}

void Parser::CheckForCorrectBreak()
{
	for (; curPos < tokens.size(); curPos++)
	{
		switch (tokens[curPos].Type())
		{
		case MyTokenType::_LBRA:
			states.push_back(ParserState::IN_BRA);
			break;

		case MyTokenType::_RBRA:
			if (states.back() == ParserState::IN_BRA)
			{
				states.pop_back();
				if (states.back() == ParserState::IN_FOR     ||
					states.back() == ParserState::IN_WHILE   ||
					states.back() == ParserState::IN_SWITCH)
					states.pop_back();
			}
			else
			{
				std::string message = "Error at line ";
				message += std::to_string(tokens[curPos].Line());
				message += ": expected declaration.\n";
				throw(message);
			}
			break;

		case MyTokenType::_FOR:
			CheckLoop(MyTokenType::_FOR);
			break;

		case MyTokenType::_DO:
			CheckLoop(MyTokenType::_DO);
			break;
			
		case MyTokenType::_WHILE:
			CheckLoop(MyTokenType::_WHILE);
			break;

		case MyTokenType::_SWITCH:
			if (states.back() == ParserState::IN_BRA)
				states.push_back(ParserState::IN_SWITCH);
			else
			{
				std::string message = "Error at line ";
				message += std::to_string(tokens[curPos].Line());
				message += ": expected declaration.\n";
				throw(message);
			}
			break;

		case MyTokenType::_BREAK:

			int b = states.size() - 1;
			while (states[b] != ParserState::DEFAULT)
			{
				if (states[b] == ParserState::IN_FOR ||
					states[b] == ParserState::IN_WHILE ||
					states[b] == ParserState::IN_DO ||
					states[b] == ParserState::IN_SWITCH)
					break;
				b--;
			}

			if(states[b] == ParserState::DEFAULT)
			{
				std::string message = "Error at line ";
				message += std::to_string(tokens[curPos].Line());
				message += ": break is not in the right place.\n";
				throw(message);
			}

			if (curPos + 1 >= tokens.size() ||
				tokens[curPos + 1].Type() != MyTokenType::_SEMICOLON)
			{
				std::string message = "Error at line ";
				message += std::to_string(tokens[curPos].Line());
				message += ": expected ;.\n";
				throw(message);
			}

			if (curPos - 1 >= tokens.size() ||
				(tokens[curPos - 1].Type() != MyTokenType::_SEMICOLON &&
				tokens[curPos - 1].Type() != MyTokenType::_LBRA &&
				tokens[curPos - 1].Type() != MyTokenType::_RPAR))
			{
				std::string message = "Error at line ";
				message += std::to_string(tokens[curPos].Line());
				message += ": expected expression.\n";
				throw(message);
			}
			break;

		}
	}
}

void Parser::CheckLoop(MyTokenType loop)
{
	//if in not construction then throw
	if (states.back() != ParserState::IN_BRA)
	{
		std::string message = "Error at line ";
		message += std::to_string(tokens[curPos].Line());
		message += ": expected declaration.\n";
		throw(message);
	}

	ParserState state;

	//in which loop
	switch (loop)
	{
	case MyTokenType::_FOR:
		state = ParserState::IN_FOR;
		break;
	case MyTokenType::_DO:
		state = ParserState::IN_DO;
		break;
	case MyTokenType::_WHILE:
		state = ParserState::IN_WHILE;
		break;
	default:
		std::string message = "Coding error! You are an IDIOT!!!\n";
		throw(message);
	}
	states.push_back(state);

	//checking for ( and )
	if(state != ParserState::IN_DO)
	{
		if (curPos + 1 >= tokens.size() ||
			tokens[curPos + 1].Type() != MyTokenType::_LPAR)
		{
			std::string message = "Error at line ";
			message += std::to_string(tokens[curPos].Line());
			message += ": expected (.\n";
			throw(message);
		}
		states.push_back(ParserState::IN_PAR);
		curPos += 2;

		for (; curPos < tokens.size() && states.back() != state; curPos++)
		{
			switch (tokens[curPos].Type())
			{
			case MyTokenType::_LPAR:
				states.push_back(ParserState::IN_PAR);
				break;

			case MyTokenType::_RPAR:
				states.pop_back();
				break;
			}
		}
	}

	if (tokens[curPos].Type() == MyTokenType::_LBRA)
	{
		--curPos;
		return;
	}

	if (tokens[curPos].Type() == MyTokenType::_BREAK)
	{
		if (curPos + 1 >= tokens.size() ||
			tokens[curPos + 1].Type() != MyTokenType::_SEMICOLON)
		{
			std::string message = "Error at line ";
			message += std::to_string(tokens[curPos].Line());
			message += ": expected ;.\n";
			throw(message);
		}

		curPos++;
	}
	else
	{
		for (; curPos < tokens.size() && tokens[curPos].Type() != MyTokenType::_SEMICOLON; curPos++)
		{
			if (tokens[curPos].Type() == MyTokenType::_BREAK)
			{
				std::string message = "Error at line ";
				message += std::to_string(tokens[curPos].Line());
				message += ": break is not in the right place.\n";
				throw(message);
			}
		}

	}

	if (state != ParserState::IN_DO)
	{
		states.pop_back();
		return;
	}

	if (tokens[curPos].Type() != MyTokenType::_WHILE)
	{
		std::string message = "Error at line ";
		message += std::to_string(tokens[curPos].Line());
		message += ": expected while.\n";
		throw(message);
	}
}

//@opsolyut все хорошо, а у тебя как? Taa