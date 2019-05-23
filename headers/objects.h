#ifndef __OBJECTS_H__
#define __OBJECTS_H__

#include <string>

class Lexem {
public:
	enum OBJ_TYPE {
		LEX, NUM, OPER, VAR
	};
	OBJ_TYPE type; 
	Lexem() { type = LEX; }
};

class Number: public Lexem {
	int value;
public:
	Number();
	Number(int newV);
	int getValue();
};

class Oper: public Lexem {
public:
	enum OPERATOR {
		RBRACKET, MULTIPLY, DIV, MOD, PLUS, MINUS, SHL, SHR, LEQ, LT, 
		GEQ, GT, EQ, NEQ, BITAND, XOR, BITOR, AND, OR, LBRACKET, ASSIGN
	};

	static const std::string OPERTEXT[21];

	static const int PRIORITY[21];
	OPERATOR opertype;
	Oper();
	Oper(OPERATOR newOp);
	OPERATOR getType();
	int getValue(Number& left, Number& right);
};

class Variable: public Lexem {
	int value;
	std::string name;
public:
	Variable();
	Variable(std::string newName);
	Variable(std::string newName, int newValue);
	std::string getName();
	int getValue();
	void setValue(int value);
};

#endif
