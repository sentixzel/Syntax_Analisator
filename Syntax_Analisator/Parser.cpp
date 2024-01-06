#include "Parser.h"

void Parser::Parse(std::vector<Token>& tokens)
{
	this->tokens = tokens;
	states.push_back(ParserState::DEFAULT);
	temp.push_back(this->tokens[curPos]);
	
	Transition();
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
			message += " : need declaration.\n";
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
			IdentifierExpectation();
			break;
		case MyTokenType::_STAR:
		case MyTokenType::_AMPERSAND:
			UnaryOpExpectation();
			break;
		default:
			std::string message = "Error at line: ";
			message += std::to_string(tokens[curPos].Line());
			message += " : need identifier.\n";
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

	}
}

void Parser::CheckForCorrectBreak()
{

}