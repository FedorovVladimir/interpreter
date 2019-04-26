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
    string text = readCode("../src/resources/testcode1.txt");
    Scanner* scanner = new Scanner(text);
    while (scanner->getCurrentNode()->getTypeLexem() != END_OF_FILE) {
        cout << scanner->getCurrentNode()->toString() << endl;
        scanner->next();
    }
    cout << scanner->getCurrentNode()->toString() << endl;
    return 0;
}