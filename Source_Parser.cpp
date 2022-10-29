#include "Source_Parser.hpp"

string Parser::getType(string str) {
    bool isVariable = true;
    bool isNumber = true;
    if (str[0] >= '0' && str[0] <= '9') isVariable = false;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] < '0' || str[i]>'9') isNumber = false;
        if (!((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))) isVariable = false;
    }
    if (isNumber) return "_number";
    if (isVariable) return "_var";
    return str;
}

Parser::Parser(string file, vector<string> operators, vector<string> wordOperators, vector<int> isSymbol) : file(file), operators(operators), wordOperators(wordOperators), isSymbol(isSymbol) {}

void Parser::parseFile() {
    for (int j = 0; j < file.size(); j++) {
        for (int i = 0; i < operators.size(); i++) {
            if (file.substr(j, operators[i].size()) == operators[i]) {
                operatorsStruct.push_back(Word(operators[i], j, operators[i]));
                for (int k = j; k < j + operators[i].size(); k++) {
                    isSymbol[k] = 1;
                }
                j += operators[i].size();
                j--;
            }
        }
        for (int i = 0; i < wordOperators.size(); i++) {
            if (file.substr(j, wordOperators[i].size()) == wordOperators[i]) {
              if (!((file[j-1] >= '0' && file[j-1] <= '9') || (file[j-1] >= 'a' && file[j-1] <= 'z') || (file[j-1] >= 'A' && file[j-1] <= 'Z'))){  
                    wordOperatorsStruct.push_back(Word(wordOperators[i], j, wordOperators[i]));
                    for (int k = j; k < j + wordOperators[i].size(); k++) {
                        isSymbol[k] = 1;
                        }
                    j += wordOperators[i].size();
                    j--;
                    }
                }
        }
    }
    string res = "";
    for (int i = 0; i < isSymbol.size(); i++) {
        if (isSymbol[i] == 0 && file[i] != ' ' && file[i] != '\n' && file[i] != '\0' && file[i] != 13) {
            res += file[i];
        }
        else if (res != "") {
            miscStruct.push_back(Word(res, i - res.size(), getType(res)));
            res = "";
        }
    }
    if (res != "" && res[0] != -1) {
        miscStruct.push_back(Word(res, isSymbol.size() - res.size(), getType(res)));
    }
}