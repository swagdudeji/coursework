#include "Source_Compiler.hpp"

bool Compiler::isInclude(const vector<string>& in, const string& str) {
    for (const string& sin : in) {
        if (sin == str) return true;
    }
    return false;
}

Compiler::Compiler(map<string, vector<string>> grammatics, vector<Word> all) : grammatics(grammatics), all(all) {}

void Compiler::compile() {
  
    bool isCompiledCorrect = true;
    string errorString = "";
  
    for (int i = 1; i < all.size(); i++) {
        cout << all[i - 1].text << endl;
        string currentOperator = all[i - 1].type;
        string nextOperator = all[i].type;
        if (!isInclude(grammatics[currentOperator], nextOperator)) {
            isCompiledCorrect = false;
            errorString = all[i - 1].text + " " + all[i].text;
            cout << "ERROR" << endl;
            break;
        }
    }
  
    if (isCompiledCorrect) {
        cout << all.back().text << endl;
        cout << "Compiled" << endl;
    }
    else {
        cout << "Can't compile on string: " << errorString << endl;
    }
}