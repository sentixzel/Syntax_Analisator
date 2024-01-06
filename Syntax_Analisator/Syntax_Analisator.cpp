//раскраска, проверка на синтаксис,
//проверка на правильность break
#include "dictionary.h"
#include "Painter.h"
#include "FileMaster.h"
#include "Parser.h"

int main(int agrc, char* argv[])
{
	FileMaster* file = new FileMaster("test");
	Painter paint;
	paint.ChangeTextColor(_DEFAULT);
	
	std::vector<std::string> testVecStr = file->getLines();

	for (int i = 0; i < testVecStr.size(); i++)
		std::cout << testVecStr[i] << std::endl;
	
	FormatText::DeleteCommentary(testVecStr);
	FormatText::DeleteSpaces(testVecStr);

	paint.ChangeTextColor(_VARIABLE);

	std::cout << FormatText::InOneString(testVecStr) << std::endl;
	
	Lexer lex(FormatText::InOneString(testVecStr));


	paint.ChangeTextColor(_ERROR);
	lex.print();

	Parser pars;

	try
	{
		pars.Parse(lex.GetTokens());
	}
	catch(std::string mess)
	{
		std::cerr << mess;
		exit(1);
	}

	std::cout << "\n All good!\n";

	delete file;
}
