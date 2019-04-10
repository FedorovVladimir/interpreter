#include "Sanner.h"
#include "Lexeme.h"

#include <string>
#include <iostream>

const string oneSymbols = ",;(){}*%/\n";
const Lexeme oneLexemes[] = {COMMA, POINT_COMMA, OPEN_KRUGLAY_SKOBKA, CLOSE_KRUGLAY_SKOBKA, OPEN_FIGURNAY_SKOBKA, CLOSE_FIGURNAY_SKOBKA, MUL, MOD, DIV, END_OF_FILE};

const string doubleSymbols = "||&&++--==";
const Lexeme doubleLexemes[] = {OR, OR_OR, AND, AND_AND, PLUS, INC, MINUS, DEC, SAVE, EQUAL};

const string s1 = "><";
const Lexeme l1[] = {LARGER, LESS};
const string s2 = "><";
const Lexeme l2[] = {LARGER_LARGER, LESS_LESS};
const string s3 = "==";
const Lexeme l3[] = {LARGER_EQUAL, LESS_EQUAL};

const int countWords = 6;
const string stringWord[] = {"if", "else", "void", "int", "double", "main"};
const Lexeme lexemeWord[] = {IF, ELSE, VOID, INT, DOUBLE, MAIN};

void Scanner::swapGarbageSymbols() {
    while (text[currentPosition] == ' ' || text[currentPosition] == '\n' || text[currentPosition] == '\t' || text[currentPosition] == '\r')
        currentPosition++;
}

void Scanner::swapComment() {
    if (text[currentPosition] == '/' && text[currentPosition + 1] == '/') {
        currentPosition += 2;
        while (text[currentPosition] != '\r' && text[currentPosition] != '\0')
            currentPosition++;
        currentPosition++;
        while (text[currentPosition] == '\n') {
            currentPosition++;
        }
    }
}

Lexeme Scanner::next() {
    if (currentPosition == text.length()) {
        return END_OF_FILE;
    }

    swapGarbageSymbols();
    swapComment();

    // , ; ( ) { } * % /
    int indexOneSymbols = oneSymbols.find(text[currentPosition]);
    if (0 <= indexOneSymbols && indexOneSymbols < oneSymbols.length()) {
        currentPosition++;
        return oneLexemes[indexOneSymbols];
    }

    // | || & && + ++ - -- = ==
    int indexDoubleSymbols1 = doubleSymbols.find(text[currentPosition]);
    if (0 <= indexDoubleSymbols1 && indexDoubleSymbols1 < doubleSymbols.length()) {
        currentPosition++;
        int indexDoubleSymbols2 = doubleSymbols.find(text[currentPosition]);
        if (0 <= indexDoubleSymbols2 && indexDoubleSymbols2 < doubleSymbols.length()) {
            currentPosition++;
            return doubleLexemes[indexDoubleSymbols2 + 1];
        } else {
            return doubleLexemes[indexDoubleSymbols1];
        }
    }

    // !=
    if (text[currentPosition] == '!') {
        currentPosition++;
        if (text[currentPosition] == '=') {
            currentPosition++;
            return NOT_EQUAL;
        } else {
            return ERROR;
        }
    }

    // >> >= > << <= <
    int index1 = s1.find(text[currentPosition]);
    if (0 <= index1 && index1 < s1.length()) {
        currentPosition++;
        int index2 = s2.find(text[currentPosition]);
        int index3 = s3.find(text[currentPosition]);
        if (0 <= index2 && index2 < s2.length()) {
            currentPosition++;
            return l2[index2];
        } else if (0 <= index3 && index3 < s3.length()) {
            currentPosition++;
            return l3[index3];
        } else
            return l1[index1];
    }

    // id
    if (isalpha(text[currentPosition])) {
        string s;
        s += text[currentPosition++];
        while (isdigit(text[currentPosition]) || isalpha(text[currentPosition])) {
            s += text[currentPosition++];
        }
        for (int i = 0; i < countWords; i++) {
            if (s == stringWord[i]) {
                return lexemeWord[i];
            }
        }
        return ID;
    }

    if (!isdigit(text[currentPosition]) && text[currentPosition] != '.') {
        return ERROR;
    }

    string s;
    if (isdigit(text[currentPosition])) {
        s += text[currentPosition++];
        while(isdigit(text[currentPosition])) {
            s += text[currentPosition++];
        }
        if (text[currentPosition] == '.') {
            s += text[currentPosition++];
            goto N1;
        } else if (text[currentPosition] == 'E' || text[currentPosition] == 'e') {
            s += text[currentPosition++];
            goto N2;
        }
        return CONST_INT;
    }
    if (text[currentPosition] == '.') {
        s += text[currentPosition++];
        if (isdigit(text[currentPosition])) {
            s += text[currentPosition++];
            goto N1;
        }
        return POINT;
    }
    N1:
    while (isdigit(text[currentPosition])) {
        s += text[currentPosition++];
    }
    if (text[currentPosition] == 'E' || text[currentPosition] == 'e') {
        s += text[currentPosition++];
        goto N2;
    }
    return CONST_FLOAT;
    N2:
    if (text[currentPosition] == '+' || text[currentPosition] == '-') {
        s += text[currentPosition++];
        if (isdigit(text[currentPosition])) {
            s += text[currentPosition++];
            goto N3;
        } else {
            return ERROR;
        }
    }
    N3:
    while (isdigit(text[currentPosition])) {
        s += text[currentPosition++];
    }
    return CONST_EXP;
}