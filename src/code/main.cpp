#include <iostream>
#include <fstream>
#include "scanner/Sanner.h"

string readCode(string path) {
    string text;
    ifstream inf;
    inf.open(path);
    getline(inf, text, '\0');
    inf.close();
    text += "\n";
    return text;
}

string toString(Lexeme lexeme) {
    switch(lexeme) {
        case IF:return "IF";
        case ELSE:return "ELSE";
        case VOID:return "VOID";
        case INT:return "INT";
        case DOUBLE:return "DOUBLE";
        case MAIN:return "MAIN";
        case ID:return "ID";
        case CONST_INT:return "CONST_INT";
        case CONST_FLOAT:return "CONST_FLOAT";
        case CONST_EXP:return "CONST_EXP";
        case PLUS:return "PLUS";
        case MINUS:return "MINUS";
        case DIV:return "DIV";
        case MOD:return "MOD";
        case MUL:return "MUL";
        case INC:return "INC";
        case DEC:return "DEC";
        case AND:return "AND";
        case AND_AND:return "AND_AND";
        case OR:return "OR";
        case OR_OR:return "OR_OR";
        case LARGER_LARGER:return "LARGER_LARGER";
        case LESS_LESS:return "LESS_LESS";
        case LESS:return "LESS";
        case LARGER:return "LARGER";
        case LESS_EQUAL:return "LESS_EQUAL";
        case LARGER_EQUAL:return "LARGER_EQAL";
        case EQUAL:return "EQUAL";
        case NOT_EQUAL:return "NOT_EQUAL";
        case SAVE:return "SAVE";
        case POINT_COMMA:return "POINT_COMMA";
        case OPEN_KRUGLAY_SKOBKA:return "OPEN_KRUGLAY_SKOBKA";
        case CLOSE_KRUGLAY_SKOBKA:return "CLOSE_KRUGLAY_SKOBKA";
        case OPEN_FIGURNAY_SKOBKA:return "OPEN_FIGURNAY_SKOBKA";
        case CLOSE_FIGURNAY_SKOBKA:return "CLOSE_FIGURNAY_SKOBKA";
        case COMMA:return "COMMA";
        case POINT:return "POINT";
        case END_OF_FILE:return "END_OF_FILE";
        case ERROR:return "ERROR";
    }
}

int main() {
    string text = readCode("../src/resources/code.txt");
    Scanner scanner(text);
    while (scanner.getCurrentLexeme() != END_OF_FILE) {
        cout << toString(scanner.getCurrentLexeme()) << endl;
        scanner.next();
    }
    return 0;
}