#pragma once
#include <string>

enum class MyTokenType
{
    _UNDEFINED = 0,
    _IDENTIFIER,

    _INTEGER_CONST,
    _FLOAT_CONST,
    _STRING_CONST,
    _CHAR_CONST,

    _EXTERN,
    _STATIC,
    _VOLATILE,

    _CONST,

    _REGISTER,
    _UNSIGND,
    _SIGND,

    _SHORT,
    _LONG,

    // types
    _INT,
    _FLOAT,
    _DOUBLE,
    _CHAR,
    _VOID,
    _AUTO,

    _SIZEOF,

    //containers
    _STRUCT,
    _ENUM,
    _UNION,

    _TYPEDEF,

    // function
    //_FUNCTION,
    _RETURN,

    // cycles
    _DO,
    _WHILE,
    _FOR,

    // cycles addition
    _BREAK,
    _CONTINUE,

    _SWITCH,
    _CASE,
    _DEFAULT,

    // conditions
    _IF,
    _ELSE,

    _GOTO,

    // relationship operators
    _LESS,          // <
    _GREATER,       // >
    _LESS_EQUAL,    // <=
    _GREATER_EQUAL, // >=

    // equal operators
    _EQUAL,     // ==
    _NOT_EQUAL, // !=

    // logical operators
    _AND,         // &&
    _OR,          // ||
    _EXCLAMATION, // !

    // math operators
    _PLUS,      // +
    _MINUS,     // -
    _STAR,      // *
    _SLASH,     // /
    _PERCENT,   // %
    _INC,       // ++
    _DEC,       // --

    // brackets
    _LBRA, // {
    _RBRA, // }
    _LPAR, // (
    _RPAR, // )
    _LSQR, // [
    _RSQR, // ]

    // assign
    _ASSIGN,     // =
    _ADD_ASSIGN, // +=
    _SUB_ASSIGN, // -=
    _MUL_ASSIGN, // *=
    _DIV_ASSIGN, // /=

    // other symbols
    _SEMICOLON, // ;
    _COLON,     // :
    _COMMA,     // ,
    _POINT,     // .
    _QUESTION,  // ?
    _AMPERSAND, // &

    // byte operators
    //_BIT_AND = _AMPERSAND,    // & must be or not equal to _AMPERSAND ?????
    _BIT_OR,     // |
    _BIT_XOR,    // ^
    _BIT_LSHIFT, // <<
    _BIT_RSHIFT, // >>
    _BIT_NEG,    // ~

    //// comment
    //// do I need this? bcs I delete all comments
    //_LINE_COMMENT,        // //
    //_BLOCK_COMMENT_START, // /*
    //_BLOCK_COMMENT_END,   // */
    
    _ACCESS_OPERATOR, // ->

    //assistive field for further token processing
    _SPACE_IN_CODE
};

class Token
{
	std::string lexeme;
	MyTokenType type;
    int line;

    MyTokenType WhichTokenType(std::string&);

    bool IsInteger(std::string&);
    bool IsFloat(std::string& current_lexeme);
    //under question
    bool IsConstString(std::string&);
    bool IsConstChar(std::string&);
    bool IsCorrectIdentifier();

public:
	Token(std::string&, int);
    MyTokenType Type();
    std::string TypeToString();
    std::string Lexeme();

    int Line();
};

// Эта баллиста, твоё превосходительство.
// Плечи усилены медными плитками, 
// тетива из конского волоса.
// Болт летит даже на милю.
// Смертоносное оружие. И очень дорогое.
// Опытная прислуга стреляет до двух раз в минуту.
// Но и тут есть свои недостатки.