#pragma once
#include<stdlib.h>
#include<string>
#include<ctype.h>
#include<iostream>
#include<vector>
#include<fstream>
#include"Source_Word.hpp"
#pragma warning(disable:4996)


class Parser{

private:
    vector<string> operators;
    vector<string> wordOperators;
    vector<int> isSymbol;
    string file;
    string getType(string str);

public:
    Parser(string file, vector<string> operators, vector<string> wordOperators, vector<int> isSymbol);

    vector<Word> operatorsStruct;
    vector<Word> wordOperatorsStruct;
    vector<Word> miscStruct;

    void parseFile();
};