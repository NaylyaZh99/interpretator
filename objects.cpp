#include "objects.h"
//~ #include <string>

const std::string Oper::OPERTEXT[6] = { "+", "-", "*", "(", ")", "=" };
const int Oper::PRIORITY[6] = {2, 2, 1, 3, 0, 4};

Number::Number() {
	value = 0;
	type = NUM;
}

Number::Number(int newV) {
	value = newV;
	type = NUM;
}

int Number::getValue() {
	return value;
}

Oper::Oper() {
	type = OPER;
}

Oper::Oper(OPERATOR newOp) {
	opertype = newOp;
	type = OPER;
}

Oper::OPERATOR Oper::getType() {
	return opertype;
}

int Oper::getValue(Number& left, Number& right) {
	if (opertype == PLUS) {
		return left.getValue() + right.getValue();
	} else if (opertype == MINUS) {
		return left.getValue() - right.getValue();
	} else if (opertype == MULTIPLY) {
		return left.getValue() * right.getValue();
	}
	return 0;
}

Variable::Variable() {
	type = VAR;
	value = 0;
}

Variable::Variable(std::string newName) {
	value = 0;
	type = VAR;
	name = newName;
}

Variable::Variable(std::string newName, int newValue) {
	value = newValue;
	type = VAR;
	name = newName;
}


int Variable::getValue() {
	return value;
}

void Variable::setValue(int newValue) {
	value = newValue;
}

std::string Variable::getName() {
	return name;
}
