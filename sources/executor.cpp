#include "../headers/objects.h"
#include "../headers/executor.h"


int evaluatePoliz(std::vector<Lexem*> poliz, std::map<std::string, Variable*> &varMap) {
	std::vector<Lexem*> stack;
	for (unsigned int i = 0; i < poliz.size(); i++) {
		if (poliz[i]->type == Lexem::NUM) {
			Number *numTmp = static_cast<Number*>(poliz[i]);
			stack.push_back(numTmp);
		} else if (poliz[i]->type == Lexem::VAR) {
			Variable *varTmp = static_cast<Variable*>(poliz[i]);
			stack.push_back(varTmp);
		} else if (poliz[i]->type == Lexem::OPER) {
			Oper *temp = static_cast<Oper*>(poliz[i]);
			if (temp->getType() == Oper::ASSIGN) {
				int tmpVal;
				if (stack.back()->type == Lexem::VAR) {
					Variable *right = static_cast<Variable*>(stack.back());
					tmpVal = right->getValue();
					stack.pop_back();
				} else {
					Number *right = static_cast<Number*>(stack.back());
					tmpVal = right->getValue();
					stack.pop_back();
				}
				if (stack.back()->type != Lexem::VAR) {
					std::cout << "ERROR: can't assign non-variable type to something" << std::endl;
					return 0;
				}
				Variable *left = static_cast<Variable*>(stack.back());
				stack.pop_back();
				left->setValue(tmpVal);
				varMap[left->getName()] = left;
				return tmpVal;
			}
			Number *right;
			Number *left;
			if (stack.back()->type == Lexem::VAR) {
				Variable *tmp = static_cast<Variable*>(stack.back());
				stack.pop_back();
				right = new Number(tmp->getValue());
			} else {
				right = static_cast<Number*>(stack.back());
				stack.pop_back();
			}
			if (stack.back()->type == Lexem::VAR) {
				Variable *tmp = static_cast<Variable*>(stack.back());
				stack.pop_back();
				left = new Number(tmp->getValue());
			} else {
				left = static_cast<Number*>(stack.back());
				stack.pop_back();
			}
			//~ Number *left = static_cast<Number*>(stack.back());
			//stack.pop_back();
			int tmp = temp->getValue(*left, *right);
			stack.push_back(new Number(tmp));
		}
	}
	Number *numTmp = static_cast<Number*>(stack.back());
	return numTmp->getValue();
}


