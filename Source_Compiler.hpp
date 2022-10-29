#pragma once
#include<stdlib.h>
#include<string>
#include<ctype.h>
#include<iostream>
#include<vector>
#include<fstream>
#include <map>
#include"Source_Word.hpp"
#pragma warning(disable:4996)


class Compiler {

private:
    map<string, vector<string>>grammatics;
    vector<Word> all;
    bool isInclude(const vector<string>& in, const string& str);

public:
    Compiler(map<string, vector<string>> grammatics, vector<Word> all);
    void compile();
};
