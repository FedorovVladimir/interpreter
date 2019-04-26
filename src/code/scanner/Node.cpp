//
// Created by vladimir on 12.04.19.
//

#include <iostream>
#include <sstream>
#include "Node.h"

string Node::toString() {
    stringstream s;
    switch(this->typeLexeme) {
        case IF: s << "IF";
            break;
        case ELSE: s << "ELSE";
            break;
        case VOID: s << "VOID";
            break;
        case INT: s << "INT" << " " << name;
            break;
        case DOUBLE: s << "DOUBLE" << " " << name;
            break;
        case MAIN: s << "MAIN";
            break;
        case ID: s << "ID" << " " << name;
            break;
        case CONST_INT: s << "CONST_INT" << " " <<  valueInteger;
            break;
        case CONST_DOUBLE: s << "CONST_FLOAT" << " " << valueDouble;
            break;
        case CONST_EXP: s << "CONST_EXP" << " " << valueExp;
            break;
        case PLUS: s << "PLUS";
            break;
        case MINUS: s << "MINUS";
            break;
        case DIV: s << "DIV";
            break;
        case MOD: s << "MOD";
            break;
        case MUL: s << "MUL";
            break;
        case INC: s << "INC";
            break;
        case DEC: s << "DEC";
            break;
        case AND: s << "AND";
            break;
        case AND_AND: s << "AND_AND";
            break;
        case OR: s << "OR";
            break;
        case OR_OR: s << "OR_OR";
            break;
        case LARGER_LARGER: s << "LARGER_LARGER";
            break;
        case LESS_LESS: s << "LESS_LESS";
            break;
        case LESS: s << "LESS";
            break;
        case LARGER: s << "LARGER";
            break;
        case LESS_EQUAL: s << "LESS_EQUAL";
            break;
        case LARGER_EQUAL: s << "LARGER_EQAL";
            break;
        case EQUAL: s << "EQUAL";
            break;
        case NOT_EQUAL: s << "NOT_EQUAL";
            break;
        case SAVE: s << "SAVE";
            break;
        case POINT_COMMA: s << "POINT_COMMA";
            break;
        case OPEN_KRUGLAY_SKOBKA: s << "OPEN_KRUGLAY_SKOBKA";
            break;
        case CLOSE_KRUGLAY_SKOBKA: s << "CLOSE_KRUGLAY_SKOBKA";
            break;
        case OPEN_FIGURNAY_SKOBKA: s << "OPEN_FIGURNAY_SKOBKA";
            break;
        case CLOSE_FIGURNAY_SKOBKA: s << "CLOSE_FIGURNAY_SKOBKA";
            break;
        case COMMA: s << "COMMA";
            break;
        case POINT: s << "POINT";
            break;
        case END_OF_FILE: s << "END_OF_FILE";
            break;
        case ERROR: s << "ERROR";
            break;
        case EMPTY: s << "EMPTY";
            break;
    }
    return s.str();
}

void Node::display(int a) {
    for (int i = 0; i < a; ++i) {
        cout << "    ";
    }
    cout << toString() << endl;
    if (left != nullptr) {
        left->display(a);
    }
    if (right != nullptr) {
        right->display();
    }
}

void Node::add(Node *pNode) {
    left = pNode;
    pNode->parent = this;
}
