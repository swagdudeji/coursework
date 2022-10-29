#pragma once
#include<string>
using namespace std;
struct Word {
    string text;
    int index;
    string type;
    Word(string text, int index, string type) : text(text), index(index), type(type) {

    }
};