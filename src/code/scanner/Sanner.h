#include <utility>

#ifndef SCANER_H
#define SCANER_H

#include <string>
#include "Lexeme.h"

using namespace std;

class Scanner {

private:
    string text = "";
    int currentPosition = 0;
    Lexeme currentLexeme;
    Lexeme nextLexeme;

    void swapGarbageSymbols();
    void swapComment();

public:

    void setCurrentPosition(const int position) {
        this->currentPosition = position;
    }

    int getCurrentPosition() {
        return currentPosition;
    }

    Lexeme getCurrentLexeme() {
        int i = getCurrentPosition();
        Lexeme lexeme = next();
        setCurrentPosition(i);
        return lexeme;
    }

    Lexeme getNextLexeme() {
        return this->nextLexeme;
    }

    Lexeme next();

    Scanner(const string text) {
        this->text = text;
    }
};

#endif // SCANER_H
