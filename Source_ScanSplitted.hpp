#pragma once
#include<stdlib.h>
#include<string>
#include<ctype.h>
#include<iostream>
#include<vector>
#include<fstream>
#include<set>
#include"Source_Scaner.hpp"
#pragma warning(disable:4996)


class ScanSplitted {

private:
    vector<vector<string>> scan;

public:
    ScanSplitted(vector<vector<string>> scan);

    vector<string> splittedOperators();
    vector<string> splittedWordOperators();
};