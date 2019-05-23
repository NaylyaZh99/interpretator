#include "objects.h"
#include "poliz.h"
#include <string>
#include <vector>

std::vector<Lexem*> parseLexem(std::string input, std::map<std::string, Variable*> &varMap) {
	std::vector<Lexem*> ans;
	int n = sizeof(Oper::OPERTEXT) / sizeof(std::string);
	for (unsigned int i = 0; i < input.size();) {
		if (input.at(i) >= '0' && input.at(i) <= '9') {
			int num = input.at(i) - '0';
			i++;
			while (input.at(i) >= '0' && input.at(i) <= '9' && i < input.size()) {
				num *= 10;
				num += (input.at(i) - '0');
				i++;
			}
			ans.push_back(new Number(num));
		} else if (input.at(i) != ' ' ) {
			int len, op;
			for (op = 0; op < n; op++) {
				len = Oper::OPERTEXT[op].size();
				if (Oper::OPERTEXT[op] == input.substr(i, len)) {
					ans.push_back(new Oper(Oper::OPERATOR(op)));
					break;
				}
			}
			if (op < n) {
				i = i + len + 1;
			} else {
				unsigned int start = i;
				while (input.at(i) != ' ' && i < input.size()) {
					i++;
				}
				std::string tmp = input.substr(start, i - start);
				std::map<std::string, Variable*>::iterator it = varMap.find(tmp);
				if (it == varMap.end()) {
					varMap[tmp] = 0;
					ans.push_back(new Variable(tmp));
				} else {
					ans.push_back(new Variable(it->first, it->second->getValue()));
				}
			}
		} else {
			i++;
		}
	}
	return ans;
}

std::vector<Lexem*> buildPoliz(std::vector<Lexem*> infix) {
	std::vector<Lexem*> ans;
	std::vector<Oper*> stack;
	for (unsigned int i = 0; i < infix.size(); i++) {
		if (infix[i]->type == Lexem::NUM) {
			Number *numTmp = static_cast<Number*>(infix[i]);
			ans.push_back(numTmp);
		} else if (infix[i]->type == Lexem::VAR) {
			Variable *varTmp = static_cast<Variable*>(infix[i]);
			ans.push_back(varTmp);
		} else if (infix[i]->type == Lexem::OPER) {
			Oper *temp = static_cast<Oper*>(infix[i]);
			if (temp->getType() == Oper::LBRACKET) {
				stack.push_back(temp);
			} else if (temp->getType() == Oper::RBRACKET) {
				while (stack.back()->getType() != Oper::LBRACKET) {
					Oper *opTmp = new Oper(stack.back()->getType());
					ans.push_back(opTmp);
					stack.pop_back();
				}
				stack.pop_back();
			} else {
				if (!stack.empty()) {
					while (Oper::PRIORITY[stack.back()->getType()] <= Oper::PRIORITY[temp->getType()] && !stack.empty()) {
						Oper *opTmp = new Oper(stack.back()->getType());
						ans.push_back(opTmp);
						stack.pop_back();
						if (stack.empty()) {
							break;
						}
					}
				}
				stack.push_back(temp);
			}
		}
	}
	while(!stack.empty()) {
		Oper *opTmp = new Oper(stack.back()->getType());
		ans.push_back(opTmp);
		stack.pop_back();
	}
	return ans;
}
