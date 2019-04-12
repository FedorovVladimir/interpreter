//
// Created by vladimir on 12.04.19.
//

#include "Node.h"

string Node::toString() {
    string s = " " + this->text;
    switch(this->typeLexeme) {
        case IF:return "IF" + s;
        case ELSE:return "ELSE" + s;
        case VOID:return "VOID" + s;
        case INT:return "INT" + s;
        case DOUBLE:return "DOUBLE" + s;
        case MAIN:return "MAIN" + s;
        case ID:return "ID" + s;
        case CONST_INT:return "CONST_INT" + s;
        case CONST_FLOAT:return "CONST_FLOAT" + s;
        case CONST_EXP:return "CONST_EXP" + s;
        case PLUS:return "PLUS" + s;
        case MINUS:return "MINUS" + s;
        case DIV:return "DIV" + s;
        case MOD:return "MOD" + s;
        case MUL:return "MUL" + s;
        case INC:return "INC" + s;
        case DEC:return "DEC" + s;
        case AND:return "AND" + s;
        case AND_AND:return "AND_AND" + s;
        case OR:return "OR" + s;
        case OR_OR:return "OR_OR" + s;
        case LARGER_LARGER:return "LARGER_LARGER" + s;
        case LESS_LESS:return "LESS_LESS" + s;
        case LESS:return "LESS" + s;
        case LARGER:return "LARGER" + s;
        case LESS_EQUAL:return "LESS_EQUAL" + s;
        case LARGER_EQUAL:return "LARGER_EQAL" + s;
        case EQUAL:return "EQUAL" + s;
        case NOT_EQUAL:return "NOT_EQUAL" + s;
        case SAVE:return "SAVE" + s;
        case POINT_COMMA:return "POINT_COMMA" + s;
        case OPEN_KRUGLAY_SKOBKA:return "OPEN_KRUGLAY_SKOBKA" + s;
        case CLOSE_KRUGLAY_SKOBKA:return "CLOSE_KRUGLAY_SKOBKA" + s;
        case OPEN_FIGURNAY_SKOBKA:return "OPEN_FIGURNAY_SKOBKA" + s;
        case CLOSE_FIGURNAY_SKOBKA:return "CLOSE_FIGURNAY_SKOBKA" + s;
        case COMMA:return "COMMA" + s;
        case POINT:return "POINT" + s;
        case END_OF_FILE:return "END_OF_FILE" + s;
        case ERROR:return "ERROR" + s;
    }
}
