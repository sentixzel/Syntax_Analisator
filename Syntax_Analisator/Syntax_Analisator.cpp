//раскраска, проверка на синтаксис,
//проверка на правильности break
#include "dictionary.h"
#include "Painter.h"
#include "FileMaster.h"
#include "Parser.h"

int main()
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


	delete file;
}
