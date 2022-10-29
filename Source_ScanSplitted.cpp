#include "Source_ScanSplitted.hpp"

ScanSplitted::ScanSplitted(vector<vector<string>> scan) : scan(scan) {}

vector<string> ScanSplitted::splittedOperators() {
        vector<string> operators;
        vector<string> comparisons = scan[0];
        vector<string> ass = scan[1];
        vector<string> additionGroupOperators = scan[2];
        vector<string> multGroupOperators = scan[3];
        vector<string> unaryOperators = scan[4];
        vector<string> numbers = scan[5];
        vector<string> otherOperators = scan[6];
        for (string s : comparisons)
            operators.push_back(s);
        for (string s : ass)
            operators.push_back(s);
        for (string s : additionGroupOperators)
            operators.push_back(s);
        for (string s : multGroupOperators)
            operators.push_back(s);
        for (string s : unaryOperators)
            operators.push_back(s);
        for (string s : otherOperators)
            operators.push_back(s);
        for (int i = 0; i < operators.size(); i++) {
            if (operators[i].size() == 0) {
                operators.erase(operators.begin() + i);
                i--;
            }
        }
        return operators;
    }

vector<string> ScanSplitted::splittedWordOperators() {
        vector<string> wordOperators;
        vector<string> inOutOperators = scan[7];
        vector<string> loopOperators = scan[8];
        vector<string> varTypes = scan[9];
        for (string s : inOutOperators)
            wordOperators.push_back(s);
        for (string s : loopOperators)
            wordOperators.push_back(s);
        for (string s : varTypes)
            wordOperators.push_back(s);
        for (int i = 0; i < wordOperators.size(); i++) {
            if (wordOperators[i].size() == 0) {
                wordOperators.erase(wordOperators.begin() + i);
                i--;
            }
        }
        return wordOperators;
    }