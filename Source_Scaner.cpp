#include "Source_Scaner.hpp"

vector<string> Scaner::split(string str, char separator){
    vector<string> result;
    str += separator;
    int iter = 0;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == separator && str != "\n" && str != "") {
            result.push_back(str.substr(iter, i - iter));
            iter = i + 1;
        }
    }
    return result;
}

void Scaner::resetError() {
        err.isError = false;
        err.error = "";
}

Scaner::Scaner() {
        this->err.isError = false;
        this->err.error = "";
}

bool Scaner::isError() {
    return this->err.isError;
}

string Scaner::getErrorText() {
    return this->err.error;
}

string Scaner::readFileAsString(string fileName) {
    this->resetError();
    ifstream file(fileName);
    string fileString = "";
    if (!file.is_open()) {
        this->err.isError = true;
        this->err.error = "error while opening the file\n";
        return fileString;
    }
    char ch;
    while (!file.eof()) {
        ch = file.get();
        if (ch != 9)
            fileString += ch;
    }
    return fileString;
}

vector<vector<string>> Scaner::readAndSplitFile(string fileName) {
    this->resetError();
    vector<vector<string>> result;
    ifstream file(fileName);
    if (!file.is_open()) {
        this->err.isError = true;
        this->err.error = "error while opening the file\n";
        return result;
    }
    string s;
    while (getline(file, s)) {
        vector<string>vec = this->split(s, ' ');
        result.push_back(vec);
    }
    file.close();
    return result;
}