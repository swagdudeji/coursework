#pragma once
#include<stdlib.h>
#include<string>
#include<ctype.h>
#include<iostream>
#include<vector>
#include<fstream>
#include<set>
#include <algorithm>
#include <map>
#include<iomanip>
#pragma warning(disable:4996)

using namespace std;


struct Error {
    bool isError;
    string error;
};


class Scaner {

private:
    vector<string> split(string str, char separator);
    Error err;
    void resetError();

public:
    Scaner();
    bool isError();
    string getErrorText();
    string readFileAsString(string fileName);
    vector<vector<string>> readAndSplitFile(string fileName);
};