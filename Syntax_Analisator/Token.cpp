#include "Token.h"

Token::Token(std::string& text, int l)
{
	lexeme = text;
	line = l;
	type = WhichTokenType(lexeme);
	if (!IsCorrectIdentifier())
		type = MyTokenType::_UNDEFINED;
}

MyTokenType Token::WhichTokenType(std::string& text)
{
	//keywords
	if (text == "register")	return MyTokenType::_REGISTER;
	if (text == "extern")	return MyTokenType::_EXTERN;
	if (text == "static")	return MyTokenType::_STATIC;
	if (text == "volatile")	return MyTokenType::_VOLATILE;

	if (text == "const")	return MyTokenType::_CONST;
	if (text == "short")	return MyTokenType::_SHORT;
	if (text == "long")		return MyTokenType::_LONG;
	if (text == "unsigned")	return MyTokenType::_UNSIGND;
	if (text == "signed")	return MyTokenType::_SIGND;

	if (text == "int")		return MyTokenType::_INT;
	if (text == "float")	return MyTokenType::_FLOAT;
	if (text == "double")	return MyTokenType::_DOUBLE;
	if (text == "char")		return MyTokenType::_CHAR;
	if (text == "void")		return MyTokenType::_VOID;
	if (text == "auto")		return MyTokenType::_AUTO;

	if (text == "sizeof")	return MyTokenType::_SIZEOF;

	if (text == "struct")	return MyTokenType::_STRUCT;
	if (text == "enum")		return MyTokenType::_ENUM;
	if (text == "union")	return MyTokenType::_UNION;

	if (text == "typedef")	return MyTokenType::_TYPEDEF;

	if (text == "return")	return MyTokenType::_UNSIGND;

	if (text == "do")		return MyTokenType::_DO;
	if (text == "while")	return MyTokenType::_WHILE;
	if (text == "for")		return MyTokenType::_FOR;

	if (text == "break")	return MyTokenType::_BREAK;
	if (text == "continue")	return MyTokenType::_CONTINUE;

	if (text == "switch")	return MyTokenType::_SWITCH;
	if (text == "case")		return MyTokenType::_CASE;
	if (text == "default")	return MyTokenType::_DEFAULT;

	if (text == "if")		return MyTokenType::_IF;
	if (text == "else")		return MyTokenType::_ELSE;

	if (text == "goto")		return MyTokenType::_GOTO;

	//operators and punctuators
	if (text == "<")		return MyTokenType::_LESS;
	if (text == ">")		return MyTokenType::_GREATER;
	if (text == "<=")		return MyTokenType::_LESS_EQUAL;
	if (text == ">")		return MyTokenType::_GREATER_EQUAL;
	if (text == "==")		return MyTokenType::_EQUAL;
	if (text == "!=")		return MyTokenType::_NOT_EQUAL;

	if (text == "&&")		return MyTokenType::_AND;
	if (text == "||")		return MyTokenType::_OR;
	if (text == "!")		return MyTokenType::_EXCLAMATION;

	if (text == "+")		return MyTokenType::_PLUS;
	if (text == "-")		return MyTokenType::_MINUS;
	if (text == "*")		return MyTokenType::_STAR;
	if (text == "/")		return MyTokenType::_SLASH;
	if (text == "%")		return MyTokenType::_PERCENT;
	if (text == "++")		return MyTokenType::_INC;
	if (text == "--")		return MyTokenType::_DEC;

	if (text == "{")		return MyTokenType::_LBRA;
	if (text == "}")		return MyTokenType::_RBRA;
	if (text == "(")		return MyTokenType::_LPAR;
	if (text == ")")		return MyTokenType::_RPAR;
	if (text == "[")		return MyTokenType::_LSQR;
	if (text == "]")		return MyTokenType::_RSQR;

	if (text == "=")		return MyTokenType::_ASSIGN;
	if (text == "+=")		return MyTokenType::_ADD_ASSIGN;
	if (text == "-=")		return MyTokenType::_SUB_ASSIGN;
	if (text == "*=")		return MyTokenType::_MUL_ASSIGN;
	if (text == "/=")		return MyTokenType::_DIV_ASSIGN;

	if (text == ";")		return MyTokenType::_SEMICOLON;
	if (text == ":")		return MyTokenType::_COLON;
	if (text == ",")		return MyTokenType::_COMMA;
	if (text == ".")		return MyTokenType::_POINT;
	if (text == "?")		return MyTokenType::_QUESTION;
	if (text == "&")		return MyTokenType::_AMPERSAND;

	if (text == "|")		return MyTokenType::_BIT_OR;
	if (text == "^")		return MyTokenType::_BIT_XOR;
	if (text == "<<")		return MyTokenType::_BIT_LSHIFT;
	if (text == ">>")		return MyTokenType::_BIT_RSHIFT;
	if (text == "~")		return MyTokenType::_BIT_NEG;

	if (text == "->")		return MyTokenType::_ACCESS_OPERATOR;

	//spaces
	if (text == " " || text == "\n" || text == "\t" || text == "\r")
							return MyTokenType::_SPACE_IN_CODE;

	//const values
	if (text.front() == '"' && text.back() == '"')
		return MyTokenType::_STRING_CONST;
	if (text.front() == '\'' && text.back() == '\'')
		return MyTokenType::_CHAR_CONST;

	if (IsInteger(text))	return MyTokenType::_INTEGER_CONST;
	if (IsFloat(text))		return MyTokenType::_FLOAT_CONST;

	return MyTokenType::_IDENTIFIER;
}

bool Token::IsConstString(std::string& text)
{
	return text.front() == '"' && text.back() == '"';
}

bool Token::IsConstChar(std::string& text)
{
	return text.front() == '\'' && text.back() == '\'';
}

bool Token::IsInteger(std::string& text)
{
	for (const auto& symbol : text)
		if (symbol < '0' || symbol > '9')
			return false;
	return true;
}

bool Token::IsFloat(std::string& text)
{
	bool point = false;

	for (const char& s : text)
	{
		if (s == '.' && !point)
		{
			point = true;
			continue;
		}

		if (s == '.')
			return false;

		if (s < '0' || s > '9')
			return false;
	}

	return true;
}

std::string Token::TypeToString()
{

	switch (type)
	{
	case MyTokenType::_UNDEFINED:		return "undefined";
	case MyTokenType::_IDENTIFIER:		return "identifier";

	case MyTokenType::_INTEGER_CONST:	return "integer constant";
	case MyTokenType::_FLOAT_CONST:		return "float constant";
	case MyTokenType::_STRING_CONST:	return "string constant";
	case MyTokenType::_CHAR_CONST:		return "char constant";

	case MyTokenType::_REGISTER:		return "register";
	case MyTokenType::_EXTERN:			return "extern";
	case MyTokenType::_STATIC:			return "static";
	case MyTokenType::_VOLATILE:		return "volatile";

	case MyTokenType::_CONST:			return "const";
	case MyTokenType::_SHORT:			return "short";
	case MyTokenType::_LONG:			return "long";
	case MyTokenType::_UNSIGND:			return "unsigned";
	case MyTokenType::_SIGND:			return "signed";

	case MyTokenType::_INT:				return "int";
	case MyTokenType::_FLOAT:			return "float";
	case MyTokenType::_DOUBLE:			return "double";
	case MyTokenType::_CHAR:			return "char";
	case MyTokenType::_VOID:			return "void";
	case MyTokenType::_AUTO:			return "auto";

	case MyTokenType::_SIZEOF:			return "sizeof";

	case MyTokenType::_STRUCT:			return "struct";
	case MyTokenType::_ENUM:			return "enum";
	case MyTokenType::_UNION:			return "union";

	case MyTokenType::_TYPEDEF:			return "typedef";

	case MyTokenType::_RETURN:			return "return";

	case MyTokenType::_DO:				return "do";
	case MyTokenType::_WHILE:			return "while";
	case MyTokenType::_FOR:				return "for";

	case MyTokenType::_BREAK:			return "break";
	case MyTokenType::_CONTINUE:		return "continue";

	case MyTokenType::_SWITCH:			return "switch";
	case MyTokenType::_CASE:			return "case";
	case MyTokenType::_DEFAULT:			return "default";

	case MyTokenType::_IF:				return "if";
	case MyTokenType::_ELSE:			return "else";

	case MyTokenType::_GOTO:			return "goto";

	case MyTokenType::_LESS:			return "less";
	case MyTokenType::_GREATER:			return "greater";
	case MyTokenType::_LESS_EQUAL:		return "less and equal";
	case MyTokenType::_GREATER_EQUAL:	return "greater and equal";

	case MyTokenType::_EQUAL:			return "equal";
	case MyTokenType::_NOT_EQUAL:		return "not equal";

	case MyTokenType::_AND:				return "logic and";
	case MyTokenType::_OR:				return "logic or";
	case MyTokenType::_EXCLAMATION:		return "exclamation";

	case MyTokenType::_PLUS:			return "plus";
	case MyTokenType::_MINUS:			return "minus";
	case MyTokenType::_STAR:			return "star";
	case MyTokenType::_SLASH:			return "slash";
	case MyTokenType::_PERCENT:			return "percent";
	case MyTokenType::_INC:				return "increment";
	case MyTokenType::_DEC:				return "decrement";

	case MyTokenType::_LBRA:			return "lbra";
	case MyTokenType::_RBRA:			return "rbra";
	case MyTokenType::_LPAR:			return "lpar";
	case MyTokenType::_RPAR:			return "rpar";
	case MyTokenType::_LSQR:			return "lsqr";
	case MyTokenType::_RSQR:			return "rsqr";

	case MyTokenType::_ASSIGN:			return "assign";
	case MyTokenType::_ADD_ASSIGN:		return "add assign";
	case MyTokenType::_SUB_ASSIGN:		return "sub assign";
	case MyTokenType::_MUL_ASSIGN:		return "mul assign";
	case MyTokenType::_DIV_ASSIGN:		return "div assign";

	case MyTokenType::_SEMICOLON:		return "semicolon";
	case MyTokenType::_COLON:			return "colon";
	case MyTokenType::_COMMA:			return "comma";
	case MyTokenType::_POINT:			return "point";
	case MyTokenType::_QUESTION:		return "question";
	case MyTokenType::_AMPERSAND:		return "ampersand";

	case MyTokenType::_BIT_OR:			return "bit or";
	case MyTokenType::_BIT_XOR:			return "bit xor";
	case MyTokenType::_BIT_LSHIFT:		return "bit left shift";
	case MyTokenType::_BIT_RSHIFT:		return "bit right shift";
	case MyTokenType::_BIT_NEG:			return "bit neg";

	case MyTokenType::_ACCESS_OPERATOR:	return "access operator";

	default: return "";
	}
}

MyTokenType Token::Type()
{
	return type;
}

std::string Token::Lexeme()
{
	return lexeme;
}

bool Token::IsCorrectIdentifier()
{
	if (!isalpha(lexeme.front()) && !lexeme.front() == '_')
		return false;

	for (int i = 1; i < lexeme.size(); i++)
		if (!isalpha(lexeme[i]) && !isdigit(lexeme[i]) && !lexeme[i] == '_')
			return false;

	return true;
}

int Token::Line()
{
	return line;
}