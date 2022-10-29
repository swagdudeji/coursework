#include"Source_Scaner.hpp"
#include"Source_Word.hpp"
#include"Source_Parser.hpp"
#include"Source_ScanSplitted.hpp"
#include"Source_Compiler.hpp"
#pragma warning(disable:4996)
using namespace std;
#define SEPARATION endl << "=============================="<< endl << endl


int main() {
    map<string, vector<string>> grammatics;
    Scaner scan;
    auto gram = scan.readAndSplitFile("grammatics.txt");
    if (scan.isError()) {
        cout << scan.getErrorText();
        return 1;
    }
    for (const auto& v : gram) {
        grammatics[v[0]] = { v.begin() + 1, v.end() };
    }
    auto symbols = scan.readAndSplitFile("symbols.txt");
    if (scan.isError()) {
        cout << scan.getErrorText();
        return 1;
    }

    ScanSplitted scanS(symbols);
    vector <string> wordOperators = scanS.splittedWordOperators();
    vector <string> operators = scanS.splittedOperators();

   
    auto codeFile = scan.readFileAsString("code.txt");
    if (scan.isError()) {
        cout << scan.getErrorText();
        return 1;
    }
    vector<int>isSymbol(codeFile.size());
    for (int i = 0; i < isSymbol.size(); i++) {
        isSymbol[i] = 0;
    }

    cout << "Code from file: " << endl << endl;
    Parser parser(codeFile, operators, wordOperators, isSymbol);
    parser.parseFile();
    vector <Word> operatorsStruct = parser.operatorsStruct;
    vector <Word> wordOperatorsStruct = parser.wordOperatorsStruct;
    vector <Word> miscStruct = parser.miscStruct;
    
    vector<Word>allExpressions;
    cout << codeFile << endl << SEPARATION; 
    cout << "Word operators: " << endl << endl;
    cout << "№" << setw(20) << "OPERATOR" << endl;
    for (int i = 0; i < wordOperatorsStruct.size(); i++) {
        cout << i+1 << setw(20)<< wordOperatorsStruct[i].text<< endl;
        allExpressions.push_back(wordOperatorsStruct[i]);
    }

    cout << SEPARATION;
    cout << "Operators: " << endl << endl;
    cout << "№" << setw(20) << "OPERATOR" << endl;
    for (int i = 0; i < operatorsStruct.size(); i++) {
        cout << i + 1 << setw(20) << operatorsStruct[i].text<< endl;
        allExpressions.push_back(operatorsStruct[i]);
    }
    cout << SEPARATION;
    cout << "Misc: " << endl << endl;
    cout << "№" << setw(20) << "TEXT" << endl;
    for (int i = 0; i < miscStruct.size(); i++) {
        cout << i + 1 << setw(20) << miscStruct[i].text<< endl;
        allExpressions.push_back(miscStruct[i]);
    }

    cout << SEPARATION;
    sort(allExpressions.begin(), allExpressions.end(), 
        [](const Word& left, const Word& right){
            return left.index < right.index;
    });
    cout << "Program tree" << endl << endl;
    Compiler compilator(grammatics, allExpressions);
    compilator.compile();
    return 0;
}
