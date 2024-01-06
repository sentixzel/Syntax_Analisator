#pragma once
#include <string>
#include <vector>


//const class Keywords
//{
//	std::string* keywords;
//public:
//	Keywords();
//	~Keywords();
//	//returns position
//	int IsKeyword(std::string);
//};

class Word
{
protected:
	std::string name = "";

public:
	//Word(); //че я здесь делаю
	std::string Name();
};

class MyType : public Word
{
public:
	MyType();
	MyType(std::string);
	//MyType(MyType&);
	MyType(MyType*);

	std::string operator=(std::string);
	std::string operator=(MyType&);
	std::string operator=(MyType*);
};

class Var : public Word
{
	MyType* _type;
public:
	Var();
	Var(MyType, std::string);
	~Var();
	std::string type();
};

class Function : public Word
{
	MyType returnType;
	std::vector<MyType> typeVars;
	bool described = false;
	bool mentioned = false;

public:
	//Function(Type возвращаемый тип, std::string название функции, std::vector<Type> vecType)
	Function(MyType, std::string, std::vector<MyType>);
	//Function(Type возвращаемый тип, std::string название функции)
	Function(MyType, std::string);

	MyType ReturnType();

	bool IsDescribed();
	void YesItIsDescribed();

	bool IsMentioned();
	void YesItIsMentioned();
};

class Struct : public Word
{
	std::vector<Var> vars;

public:
	Struct(std::vector<Var>);
	bool IsValidVar(std::string);
};

class Union : Struct
{
	//зачем?
};

class Enum : public Word
{
	std::vector<Var> vars;

public:
	Enum(std::vector<Var>);
};

class Dictionary
{
	std::vector<MyType>	  typeField;
	std::vector<Var>	  varField;
	std::vector<Function> funcField;
	std::vector<Struct>   structField;
	std::vector<Union>	  unionField;
	std::vector<Enum>	  enumField;

public:
	Dictionary();
	~Dictionary();

	void addType(MyType);
	void addVar(Var);
	void addFunction(Function);
	void addStruct(Struct);
	void addUnion(Union);
	void addEnum(Enum);

	void deleteType(int);
	void deleteVar(int);
	void deleteFunction(int);
	void deleteStruct(int);
	void deleteUnion(int);
	void deleteEnum(int);

	//Зачем я собираюсь делать эти функции?
	bool isType(std::string);
	bool isVar(std::string);
	bool isFunction(std::string);
	bool isStruct(std::string);
	void isUnion(std::string);
	void isEnum(std::string);

	//А ЭТО ЗАЧЕМ?
	bool isDeclared(std::string);
};



// ===== Roadhouse AUC incident=====
// Дико извеняюс пробегал кобанчиком
// увидел ваш Стрим чё тут? АХАХХААХ
// 🤣 ***** 25 + лет мужику сидит
// соточки виртуальные гоняет, я в
// твоих годах уже старший слесарь
// был)) ладно до встречи АУКционеры
// ****)))😃
// =================================
// 
// 
// 
// я еблан
// 
// 
// 
// ******* техно/рейв/днб или тп, а песня из 80-х (акапела) на фоне 