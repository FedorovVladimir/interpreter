#include <utility>

#ifndef SCANER_H
#define SCANER_H

#include <string>
#include "Node.h"

using namespace std;

class Scanner {

private:
    string text = "";
    int currentPosition = 0;

    void swapGarbageSymbols();
    void swapComment();

public:

    void setCurrentPosition(const int position) {
        this->currentPosition = position;
    }

    int getCurrentPosition() {
        return currentPosition;
    }

    Node* getCurrentLexeme() {
        int i = getCurrentPosition();
        Node* node = next();
        setCurrentPosition(i);
        return node;
    }

    Node* getNextLexeme() {
        int i = getCurrentPosition();
        next();
        Node* lexeme = next();
        setCurrentPosition(i);
        return lexeme;
    }

    Node* next();

    Scanner(const string text) {
        this->text = text;
    }
};

#endif // SCANER_H
