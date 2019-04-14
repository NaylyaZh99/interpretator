#ifndef __POLIZ_H__
#define __POLIZ_H__

#include <string>
#include <vector>
#include <map>

std::vector<Lexem*> parseLexem(std::string input, std::map<std::string, Variable*> &varMap);
std::vector<Lexem*> buildPoliz(std::vector<Lexem*> infix);

#endif
