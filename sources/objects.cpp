#include "../headers/objects.h"

const std::string Oper::OPERTEXT[21] = { ")", "*", "/", "%", "+", "-", "<<", 
	">>", "<=", "<", ">=", ">", "==", "!=", "&", "^", "|", "and", "or", "(", "=" };
const int Oper::PRIORITY[21] = {0, 1, 1, 1, 2, 2, 3, 3, 4, 4, 4, 4, 5, 
	5, 6, 7, 8, 9, 10, 11, 12};

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
	} else if (opertype == DIV) {
		return left.getValue() / right.getValue();
	} else if (opertype == MOD) {
		return left.getValue() % right.getValue();
	} else if (opertype == SHL) {
		return left.getValue() << right.getValue();
	} else if (opertype == SHR) {
		return left.getValue() >> right.getValue();
	} else if (opertype == LEQ) {
		return left.getValue() <= right.getValue();
	} else if (opertype == LT) {
		return left.getValue() < right.getValue();
	} else if (opertype == GEQ) {
		return left.getValue() >= right.getValue();
	} else if (opertype == GT) {
		return left.getValue() > right.getValue();
	} else if (opertype == EQ) {
		return left.getValue() == right.getValue();
	} else if (opertype == NEQ) {
		return left.getValue() != right.getValue();
	} else if (opertype == BITAND) {
		return left.getValue() & right.getValue();
	} else if (opertype == XOR) {
		return left.getValue() ^ right.getValue();
	} else if (opertype == BITOR) {
		return left.getValue() | right.getValue();
	} else if (opertype == AND) {
		return left.getValue() > 0 && right.getValue() > 0;
	} else if (opertype == OR) {
		return left.getValue() > 0 || right.getValue() > 0;
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
