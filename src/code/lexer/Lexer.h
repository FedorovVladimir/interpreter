//
// Created by vladimir on 26.04.19.
//

#ifndef INTERPRETER_LEXER_H
#define INTERPRETER_LEXER_H


#include "../scanner/Sanner.h"
#include "../tree/Tree.h"

class Lexer {
private:
    Scanner* scanner;
    Tree* tree;
public:
    Lexer(Scanner *pScanner, Tree *pTree) {
        this->scanner = pScanner;
        this->tree = pTree;
    }

    void log(string text) {
        cout << "Ошибка: " << text << "." << endl;
        exit(1);
    }

    void start();

    void opisanie();

    void opisaniePeramennih();

    void logPath(string text);

    void opisanieFunction();

    void opisanieOperatora();

    void opisanieOperatorov();

    void vizovFunction();

    void savePeramennoy();

    void opisanieIf();

    void expession();

    void expession1();

    void expession2();

    void expession3();

    void expession4();

    void expession5();

    void expession6();
};


#endif //INTERPRETER_LEXER_H
