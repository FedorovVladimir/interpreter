#include <iostream>
#include <fstream>
#include "scanner/Sanner.h"
#include "lexer/Lexer.h"

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

    // вывод всех найденых токенов
//    while (scanner->getCurrentNode()->getTypeLexem() != END_OF_FILE) {
//        cout << scanner->getCurrentNode()->toString() << endl;
//        scanner->next();
//    }
//    cout << scanner->getCurrentNode()->toString() << endl;

    // разбор лексики
    Lexer* lexer = new Lexer(scanner);
    lexer->start();
    lexer->getTree()->display();

    return 0;
}