#include <iostream>
#include <fstream>
#include "scanner/Sanner.h"

string readCode(string path) {
    string text;
    ifstream inf;
    inf.open(path);
    getline(inf, text, '\0');
    inf.close();
    text += "\n";
    return text;
}

int main() {
    string text = readCode("../src/resources/code.txt");
    Scanner* scanner = new Scanner(text);
    while (scanner->getCurrentLexeme()->getTypeLexem() != END_OF_FILE) {
        cout << scanner->getCurrentLexeme()->toString() << endl;
        scanner->next();
    }
    return 0;
}