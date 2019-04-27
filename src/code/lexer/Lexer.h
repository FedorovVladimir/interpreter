//
// Created by vladimir on 26.04.19.
//

#ifndef INTERPRETER_LEXER_H
#define INTERPRETER_LEXER_H


#include "../scanner/Sanner.h"
#include <list>

class Lexer {
private:
    Scanner* scanner;
    list<Node *> *listok = new list<Node*>();
    bool debug = false;
    Node* node;
    Node* current;
    bool fInt = false;
public:
    explicit Lexer(Scanner *pScanner) {
        this->scanner = pScanner;
        this->node = new Node(EMPTY);
        current = node;
        addNode(new Node(FUNCTION, "", "print"));
        addNode(new Node(FUNCTION, "", "scan"));
    }

    void log(const string& text) {
        cout << "Ошибка: " << text << "." << endl;
        exit(1);
    }

    void logWarning(const string& text) {
        cout << "Предупреждение: " << text << "." << endl;
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

    void in();

    void out();
};


#endif //INTERPRETER_LEXER_H
