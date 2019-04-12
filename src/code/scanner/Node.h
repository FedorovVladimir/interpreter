//
// Created by vladimir on 12.04.19.
//

#ifndef INTERPRETER_NODE_H
#define INTERPRETER_NODE_H


#include "TypeLexeme.h"
#include <string>

using namespace std;

class Node {
private:
    TypeLexeme typeLexeme;
    string text;
public:
    Node(TypeLexeme typeLexeme) {
        this->typeLexeme = typeLexeme;
    }

    Node(TypeLexeme typeLexeme, string text) {
        this->typeLexeme = typeLexeme;
        this->text = text;
    }

    TypeLexeme getTypeLexem() {
        return this->typeLexeme;
    }

    string toString();
};


#endif //INTERPRETER_NODE_H
