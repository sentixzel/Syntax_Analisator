#include "dictionary.h"

//Keywords::Keywords()
//{
//	keywords = new std::string[32];
//	keywords[0]  = "auto";		//+
//	keywords[1]  = "double";	//+
//	keywords[2]  = "int";		//+
//	keywords[3]  = "struct";	//+
//	keywords[4]  = "break";		//+
//	keywords[5]  = "else";		//+
//	keywords[6]  = "long";		//+
//	keywords[7]  = "switch";	//+
//	keywords[8]  = "case";		//+
//	keywords[9]  = "enum";		//+
//	keywords[10] = "register";	//+
//	keywords[11] = "typedef";	//+
//	keywords[12] = "char";		//+
//	keywords[13] = "extern";	//+
//	keywords[14] = "return";	//+
//	keywords[15] = "union";		//+
//	keywords[16] = "const";		//+
//	keywords[17] = "float";		//+
//	keywords[18] = "short";		//+
//	keywords[19] = "unsigned";	//+
//	keywords[20] = "continue";	//+
//	keywords[21] = "for";		//+
//	keywords[22] = "signed";	//+
//	keywords[23] = "void";		//+
//	keywords[24] = "default";	//+
//	keywords[25] = "goto";		//+
//	keywords[26] = "sizeof";	//+
//	keywords[27] = "while";		//+
//	keywords[28] = "do";		//+
//	keywords[29] = "if";		//+
//	keywords[30] = "static";	//+
//	keywords[31] = "volatile";	//+
//}

//Keywords::~Keywords()
//{
//	delete[] keywords;
//}

//int Keywords::IsKeyword(std::string name)
//{
//	for (int i = 0; i < 32; i++)
//		if (keywords[i] == name)
//			return i;
//
//	return -1;
//}

std::string Word::Name()
{
	return name;
}

//TYPE//////////////////////////

MyType::MyType()
{
	name = "";
}

MyType::MyType(std::string str)
{
	name = str;
}

//MyType::MyType(MyType& t)
//{
//	name = t.name;
//}

MyType::MyType(MyType* t)
{
	name = t->name;
}

std::string MyType::operator=(std::string str)
{
	name = str;
	return name;
}

std::string MyType::operator=(MyType& t)
{
	name = t.name;
	return name;
}

std::string MyType::operator=(MyType* t)
{
	name = t->name;
	return name;
}

//VAR//////////////////////////////////////////

Var::Var()
{
	_type = new MyType();
	name = "";
}

Var::Var(MyType t, std::string str)
{
	_type = new MyType(t);
	name = str;
}

Var::~Var()
{
	delete _type;
}

std::string Var::type()
{
	return name;
}

//FUNCTION/////////////////////////////////////////

Function::Function(MyType returnT, std::string str)
{
	returnType = returnT;
	name = str;
}

Function::Function(MyType returnT, std::string str, std::vector<MyType> typeV)
{
	returnType = returnT;
	name = str;
	typeVars = typeV;
}

MyType Function::ReturnType()
{
	return returnType;
}

bool Function::IsDescribed()
{
	return described;
}

void Function::YesItIsDescribed()
{
	described = true;
}

bool Function::IsMentioned()
{
	return mentioned;
}

void Function::YesItIsMentioned()
{
	mentioned = true;
}

//STRUCT//////////////////////////////

Struct::Struct(std::vector<Var> vec)
{
	vars = vec;
}

bool Struct::IsValidVar(std::string str)
{
	for (int i = 0; i < vars.size(); i++)
		if (str == vars[i].Name())
			return true;

	return false;
}

//DICTIONARY LOL///////////////////////////////////

Dictionary::Dictionary()
{
	typeField.push_back(MyType("char"));
	typeField.push_back(MyType("signed char"));
	typeField.push_back(MyType("unsigned char"));
	typeField.push_back(MyType("short"));
	typeField.push_back(MyType("short int"));
	typeField.push_back(MyType("signed short"));
	typeField.push_back(MyType("signed short int"));
	typeField.push_back(MyType("unsigned short"));
	typeField.push_back(MyType("unsigned short int"));
	typeField.push_back(MyType("int"));
	typeField.push_back(MyType("signed"));
	typeField.push_back(MyType("signed int"));
	typeField.push_back(MyType("unsigned"));
	typeField.push_back(MyType("unsigned int"));
	typeField.push_back(MyType("long"));
	typeField.push_back(MyType("long int"));
	typeField.push_back(MyType("signed long"));
	typeField.push_back(MyType("signed long int"));
	typeField.push_back(MyType("unsigned long"));
	typeField.push_back(MyType("unsigned long int"));
	typeField.push_back(MyType("long long"));
	typeField.push_back(MyType("long long int"));
	typeField.push_back(MyType("signed long long"));
	typeField.push_back(MyType("signed long long int"));
	typeField.push_back(MyType("unsigned long long"));
	typeField.push_back(MyType("unsigned long long int"));
	typeField.push_back(MyType("float"));
	typeField.push_back(MyType("double"));
	typeField.push_back(MyType("long double"));
	
}

// chipi chipi
// chapa chapa 
// dubi dubi 
// daba daba 
// magic pony 
// dubi dubi 
// boom boom boom boom