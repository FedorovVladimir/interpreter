//
// Created by vladimir on 26.04.19.
//

#ifndef INTERPRETER_LEXER_H
#define INTERPRETER_LEXER_H


#include "../scanner/Sanner.h"

class Lexer {
private:
    Scanner* scanner;
public:
    Lexer(Scanner *pScanner) {
        this->scanner = pScanner;
    }

    void log(string text) {
        cout << "Ошибка: " << text << "." << endl;
        exit(1);
    }

    void start();

    void opisanie();

    void opisaniePeramennih();

    void logPath(string text);
};


#endif //INTERPRETER_LEXER_H
