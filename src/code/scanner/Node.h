//
// Created by vladimir on 12.04.19.
//

#ifndef INTERPRETER_NODE_H
#define INTERPRETER_NODE_H


#include "TypeLexeme.h"
#include <string>
#include <cstring>
#include <iostream>
#include <cmath>

using namespace std;

class Node {
private:
    TypeLexeme typeLexeme;
    union {
        char* valueText;
        float valueFloat;
        float valueExp;
        int valueInteger;
    };
public:
    Node(TypeLexeme typeLexeme) {
        this->typeLexeme = typeLexeme;
    }

    Node(TypeLexeme typeLexeme, string text) {
        this->typeLexeme = typeLexeme;
        valueText = new char[text.length() + 1];
        strcpy(valueText, text.c_str());

        if (typeLexeme == CONST_EXP) {
            char * s = strtok(valueText, "Ee");
            valueFloat = atof(s);
            s = strtok(NULL, "Ee");
            valueFloat *= pow(10, atoi(s));
        }
    }

    Node(TypeLexeme typeLexeme, double d) {
        this->typeLexeme = typeLexeme;
        this->valueFloat = d;
    }

    Node(TypeLexeme typeLexeme, int i) {
        this->typeLexeme = typeLexeme;
        this->valueInteger = i;
    }

    TypeLexeme getTypeLexem() {
        return this->typeLexeme;
    }

    string toString();
};


#endif //INTERPRETER_NODE_H
