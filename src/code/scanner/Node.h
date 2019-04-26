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
public:
    Node* parent = nullptr;
    Node* right = nullptr;
    Node* left = nullptr;
    char* name;
    union {
        double valueDouble;
        double valueExp;
        int valueInteger;
    };

    Node(TypeLexeme typeLexeme) {
        this->typeLexeme = typeLexeme;
    }

    Node(TypeLexeme typeLexeme, string text, string name = "") {
        this->typeLexeme = typeLexeme;

        char* value = new char[text.length() + 1];
        strcpy(value, text.c_str());

        this->name = new char[name.length() + 1];
        strcpy(this->name, name.c_str());

        if (typeLexeme == CONST_INT || typeLexeme == INT) {
            valueInteger = atoi(text.c_str());
        }

        if (typeLexeme == CONST_DOUBLE || typeLexeme == DOUBLE) {
            valueDouble = atof(text.c_str());
        }
    }

    TypeLexeme getTypeLexem() {
        return this->typeLexeme;
    }

    string toString();

    void display(int a = 0);

    void add(Node *pNode);

    friend Node *operator || (Node &n1, Node &n2);
    friend Node *operator && (Node &n1, Node &n2);
    friend Node *operator | (Node &n1, Node &n2);
    friend Node *operator & (Node &n1, Node &n2);
    friend Node *operator != (Node &n1, Node &n2);
    friend Node *operator == (Node &n1, Node &n2);
    friend Node *operator <= (Node &n1, Node &n2);
    friend Node *operator >= (Node &n1, Node &n2);
    friend Node *operator < (Node &n1, Node &n2);
    friend Node *operator > (Node &n1, Node &n2);
    friend Node *operator + (Node &n1, Node &n2);
    friend Node *operator - (Node &n1, Node &n2);
    friend Node *operator * (Node &n1, Node &n2);
    friend Node *operator / (Node &n1, Node &n2);

    string getValue();

    void setValue(string basicString);
};


#endif //INTERPRETER_NODE_H
