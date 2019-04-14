#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "objects.h"
#include "poliz.h"
#include "executor.h"

void print(std::vector<Lexem*> vec, std::map<std::string, Variable*> &varMap);

int main(void) {
	std::string line;
	std::map<std::string, Variable*> varMap;
	std::vector<Lexem *> vec;
	std::vector<Lexem *> poliz;
	while (getline(std::cin, line)) {
		std::cout << line << std::endl;
		vec = parseLexem(line, varMap);
		print(vec, varMap);
		poliz = buildPoliz(vec);
		print(poliz, varMap);
		std::cout << evaluatePoliz(poliz, varMap) << std::endl;
		std::map<std::string, Variable*>::iterator it = varMap.begin();
		while (it != varMap.end()) {
			std::cout << it->first << " :: " << it->second->getValue() << std::endl;
			it++;
		}
	}
	return 0;
}

void print(std::vector<Lexem*> vec, std::map<std::string, Variable*> &varMap) {
	for (unsigned int i = 0; i < vec.size(); i++) {
		if (vec[i]->type == Lexem::NUM) {
			Number *tmp = static_cast<Number*>(vec[i]);
			std::cout << tmp->getValue() << ' ';
		} else if (vec[i]->type == Lexem::OPER) {
			Oper *temp = static_cast<Oper*>(vec[i]);
			std::cout << Oper::OPERTEXT[temp->getType()] << ' ';
		} else if (vec[i]->type == Lexem::VAR) {
			Variable *temp = static_cast<Variable*>(vec[i]);
			std::cout << temp->getName() << '(' << temp->getValue() << ") ";
		}
	}
	std::cout << std::endl;
}

