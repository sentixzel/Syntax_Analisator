#include "Lexer.h"

Lexer::Lexer(std::string text)
{
	code = text;
    Split();
    Merge();
    DeleteSpaces();
}

void Lexer::Split()
{
	std::string buf;
	LexerState state = LexerState::DEFAULT;
    int currentLine = 1;

    for (int i = 0; i < code.size(); i++)
    {
        switch (state)
        {
        case LexerState::DEFAULT:
            if (code[i] == '"')
            {
                state = LexerState::IN_STRING;
                if (buf.size() > 0)
                {
                    tokens.push_back(Token(buf, currentLine));
                    buf.clear();
                }
                buf.push_back(code[i]);
            }
            else if (code[i] == '\'')
            {
                state = LexerState::IN_CHAR;
                if (buf.size() > 0)
                {
                    tokens.push_back(Token(buf, currentLine));
                    buf.clear();
                }
                buf.push_back(code[i]);
            }
            else if (IsSepareteSymbol(code[i]))
            {
                if (buf.size() > 0)
                {
                    tokens.push_back(Token(buf, currentLine));
                    buf.clear();
                }

                buf.push_back(code[i]);
                tokens.push_back(Token(buf, currentLine));
                buf.clear();
            }
            else
            {
                buf.push_back(code[i]);
            }

            break;

        case LexerState::IN_STRING:
            if (code[i] == '"')
            {
                state = LexerState::DEFAULT;
                buf.push_back(code[i]);
                tokens.push_back(Token(buf, currentLine));
                buf.clear();
                break;
            }

            buf.push_back(code[i]);
            break;

        case LexerState::IN_CHAR:
            if (code[i] == '\'')
            {
                state = LexerState::DEFAULT;
                buf.push_back(code[i]);
                tokens.push_back(Token(buf, currentLine));
                buf.clear();
                break;
            }

            buf.push_back(code[i]);
        }

        if (code[i] == '\n')
            currentLine++;
    }
}

bool Lexer::IsComplexToken(char symbol1, char symbol2)
{
    switch (symbol1)
    {
    case '<': return symbol2 == '=' || symbol2 == '<';
    case '>': return symbol2 == '=' || symbol2 == '>';

    case '=': return symbol2 == '=';
    case '!': return symbol2 == '=';

    case '&': return symbol2 == '&';
    case '|': return symbol2 == '|';

    case '+': return symbol2 == '=' || symbol2 == '+';
    case '-': return symbol2 == '=' || symbol2 == '-' || symbol2 == '>';

    case '*': return symbol2 == '=';
    case '/': return symbol2 == '=';
    }

    return false;
}

void Lexer::Merge()
{
    std::vector<Token> buf;

    int i;
    for (i = 0; i < tokens.size() - 2; i++)
    {
        if (tokens[i].Type() == MyTokenType::_INTEGER_CONST &&
            tokens[i + 1].Type() == MyTokenType::_POINT &&
            tokens[i + 2].Type() == MyTokenType::_INTEGER_CONST)
        {
            std::string newLex = tokens[i].Lexeme() + (tokens[i + 1].Lexeme() + tokens[i + 2].Lexeme());

            buf.push_back(Token(newLex, tokens[i].Line()));

            i += 2;
        }
        else
            buf.push_back(tokens[i]);
    }
    for(; i < tokens.size(); i++)
        buf.push_back(tokens[i]);

    tokens = buf;
    buf.clear();

    for (i = 0; i < tokens.size() - 1; i++)
    {
        if (IsComplexToken(tokens[i].Lexeme().front(), tokens[i + 1].Lexeme().front()))
        {
            std::string newLex = tokens[i].Lexeme() + tokens[i + 1].Lexeme();

            buf.push_back(Token(newLex, tokens[i].Line()));

            i += 1;
        }
        else
            buf.push_back(tokens[i]);
    }

    for (; i < tokens.size(); i++)
        buf.push_back(tokens[i]);

    tokens = buf;
    buf.clear();
}

bool Lexer::IsSepareteSymbol(char symbol)
{
    return  symbol == ':'  || symbol == ';'  || symbol == ','  || symbol == '.'  ||
            symbol == '{'  || symbol == '}'  || symbol == '('  || symbol == ')'  ||
            symbol == '['  || symbol == ']'  || symbol == '*'  || symbol == '/'  ||
            symbol == '+'  || symbol == '-'  || symbol == '&'  || symbol == '|'  ||
            symbol == '='  || symbol == '!'  || symbol == '<'  || symbol == '>'  ||
            symbol == '\'' || symbol == '"'  || symbol == '^'  || symbol == '?'  ||
            symbol == '%'  || symbol == '~'  || symbol == ' '  || symbol == '\r' || 
            symbol == '\n' || symbol == '#';
}

void Lexer::print()
{
    for (int i = 0; i < tokens.size(); i++)
        //if(tokens[i].Type() != MyTokenType::_SPACE_IN_CODE)
            std::cout << "At line " << std::to_string(tokens[i].Line()) << " "
                      << tokens[i].Lexeme() << " with type: " << tokens[i].TypeToString()
                      << std::endl;
}

void Lexer::DeleteSpaces()
{
    std::vector<Token> buf;
    for (int i = 0; i < tokens.size(); i++)
        if (tokens[i].Type() != MyTokenType::_SPACE_IN_CODE)
            buf.push_back(tokens[i]);

    tokens = buf;
    buf.clear();
}

std::vector<Token> Lexer::GetTokens()
{
    return tokens;
}