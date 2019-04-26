//
// Created by vladimir on 26.04.19.
//

#ifndef INTERPRETER_LEXER_H
#define INTERPRETER_LEXER_H


#include "../scanner/Sanner.h"

class Lexer {
private:
    Scanner* scanner;
    bool debug = false;
    Node* node;
    Node* current;
public:
    explicit Lexer(Scanner *pScanner) {
        this->scanner = pScanner;
        this->node = new Node(EMPTY);
        current = node;
    }

    void log(const string& text) {
        cout << "Ошибка: " << text << "." << endl;
        exit(1);
    }

    Node* getTree() {
        return node;
    }

    void start();

    void opisanie();

    void opisaniePeramennih();

    void logPath(const string& text);

    void opisanieFunction();

    void opisanieOperatora();

    void opisanieOperatorov();

    void vizovFunction();

    void savePeramennoy();

    void opisanieIf();

    Node* expession();

    Node* expession2();

    Node* expession3();

    Node* expession4();

    Node* expession5();

    Node* expession6();

    void addNode(Node *pNode);

    Node* getVar(const string& name);
};


#endif //INTERPRETER_LEXER_H
