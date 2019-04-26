//
// Created by vladimir on 26.04.19.
//

#include "Lexer.h"

void Lexer::start() {
    logPath("Старт");
    while (scanner->getTypeLexem() != END_OF_FILE) {
        if (scanner->getTypeLexem() == INT || scanner->getTypeLexem() == VOID || scanner->getTypeLexem() == DOUBLE) {
            opisanie();
        } else {
            log("Описание не найдено");
        }
    }
}

void Lexer::opisanie() {
    logPath("Описание");
    if (scanner->getTypeLexem() == VOID) {
//        function();
    } else {
        opisaniePeramennih();
    }
}

void Lexer::opisaniePeramennih() {
    logPath("Описание переменных");
    scanner->next();

    do {
        if (scanner->getTypeLexem() == COMMA) {
            scanner->next();
        }

        if (scanner->getTypeLexem() != ID) {
            log("Ожидалася идентификатор");
        }
        scanner->next();

        if (scanner->getTypeLexem() == SAVE) {
            scanner->next();
            if (scanner->getTypeLexem() != CONST_INT && scanner->getTypeLexem() != CONST_DOUBLE && scanner->getTypeLexem() != CONST_EXP) {
                log("Ожидалась константа");
            }
            scanner->next();
        }
    } while (scanner->getTypeLexem() == COMMA);

    if (scanner->getTypeLexem() != POINT_COMMA) {
        log("Ожидалась точька с запятой");
    }
    scanner->next();
}

void Lexer::logPath(string text) {
    cout << text << endl;
}
