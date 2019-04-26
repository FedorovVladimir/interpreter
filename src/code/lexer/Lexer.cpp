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
        opisanieFunction();
    } else {
        opisaniePeramennih();
        if (scanner->getTypeLexem() != POINT_COMMA) {
            log("Ожидалась точька с запятой");
        }
        scanner->next();
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
            expession();
        }
    } while (scanner->getTypeLexem() == COMMA);
}

void Lexer::opisanieFunction() {
    logPath("Описание функции");
    scanner->next();

    if (scanner->getTypeLexem() != ID && scanner->getTypeLexem() != MAIN) {
        log("Ожидалася идентификатор");
    }
    scanner->next();

    if (scanner->getTypeLexem() != OPEN_KRUGLAY_SKOBKA) {
        log("Ожидалася символ'('");
    }
    scanner->next();

    if (scanner->getTypeLexem() != CLOSE_KRUGLAY_SKOBKA) {
        log("Ожидалася символ')'");
    }
    scanner->next();

    if (scanner->getTypeLexem() != OPEN_FIGURNAY_SKOBKA) {
        log("Ожидалася символ'{'");
    }
    opisanieOperatora();
}

void Lexer::logPath(string text) {
    cout << text << endl;
}

void Lexer::opisanieOperatora() {
    logPath("Описание оператора");
    if (scanner->getTypeLexem() == OPEN_FIGURNAY_SKOBKA) {
        scanner->next();

        opisanieOperatorov();

        if (scanner->getTypeLexem() != CLOSE_FIGURNAY_SKOBKA) {
            log("Ожидалася символ'}'");
        }
        scanner->next();
    }

    if (scanner->getTypeLexem() == INT || scanner->getTypeLexem() == DOUBLE) {
        opisaniePeramennih();

        if (scanner->getTypeLexem() != POINT_COMMA) {
            log("Ожидалась точька с запятой");
        }
        scanner->next();
    }

    if (scanner->getTypeLexem() == ID || scanner->getTypeLexem() == MAIN) {
        if (scanner->getNextNode()->getTypeLexem() == OPEN_KRUGLAY_SKOBKA) {
            vizovFunction();
        }

        if (scanner->getNextNode()->getTypeLexem() == SAVE) {
            savePeramennoy();
        } else {
            expession();
        }

        if (scanner->getTypeLexem() != POINT_COMMA) {
            log("Ожидалась точька с запятой");
        }
        scanner->next();
    }

    if (scanner->getTypeLexem() == IF) {
        opisanieIf();
    }

    if (scanner->getTypeLexem() == POINT_COMMA) {
        scanner->next();
    }

    if (scanner->getTypeLexem() == CONST_INT || scanner->getTypeLexem() == CONST_DOUBLE || scanner->getTypeLexem() == CONST_EXP) {
        expession();
    }
}

void Lexer::opisanieOperatorov() {
    logPath("Описание операторов");

    while (scanner->getTypeLexem() != CLOSE_FIGURNAY_SKOBKA) {
        opisanieOperatora();
    }
}

void Lexer::vizovFunction() {
    logPath("Вызов функции");

    scanner->next();
    scanner->next();
    scanner->next();
}

void Lexer::savePeramennoy() {
    logPath("Присваивание переменной");

    scanner->next();
    scanner->next();

    expession();
}

void Lexer::opisanieIf() {
    logPath("Описание if");

    scanner->next();
    if (scanner->getTypeLexem() != OPEN_KRUGLAY_SKOBKA) {
        log("Ожидалася символ'('");
    }
    scanner->next();

    expession();

    if (scanner->getTypeLexem() != CLOSE_KRUGLAY_SKOBKA) {
        log("Ожидалася символ')'");
    }
    scanner->next();

    opisanieOperatora();

    if (scanner->getTypeLexem() == ELSE) {
        scanner->next();
        opisanieOperatora();
    }
}

void Lexer::expession() {
    logPath("Обработка || &&");

    expession1();
    while (scanner->getTypeLexem() == OR_OR || scanner->getTypeLexem() == AND_AND) {
        scanner->next();
        expession1();
    }
}

void Lexer::expession1() {
    logPath("Обработка | &");

    expession2();
    while (scanner->getTypeLexem() == OR || scanner->getTypeLexem() == AND) {
        scanner->next();
        expession2();
    }
}

void Lexer::expession2() {
    logPath("Обработка != ==");

    expession3();
    while (scanner->getTypeLexem() == NOT_EQUAL || scanner->getTypeLexem() == EQUAL) {
        scanner->next();
        expession3();
    }
}

void Lexer::expession3() {
    logPath("Обработка <= >= < >");

    expession4();
    while (scanner->getTypeLexem() == LARGER_EQUAL || scanner->getTypeLexem() == LESS_EQUAL || scanner->getTypeLexem() == LARGER || scanner->getTypeLexem() == LESS) {
        scanner->next();
        expession4();
    }
}

void Lexer::expession4() {
    logPath("Обработка + -");

    expession5();
    while (scanner->getTypeLexem() == PLUS || scanner->getTypeLexem() == MINUS) {
        scanner->next();
        expession5();
    }
}

void Lexer::expession5() {
    logPath("Обработка * /");

    expession6();
    while (scanner->getTypeLexem() == MUL || scanner->getTypeLexem() == DIV) {
        scanner->next();
        expession6();
    }
}

void Lexer::expession6() {
    logPath("Обработка простого выражения");

    if (scanner->getTypeLexem() == CONST_INT) {
        scanner->next();
    }

    if (scanner->getTypeLexem() == CONST_DOUBLE) {
        scanner->next();
    }

    if (scanner->getTypeLexem() == CONST_EXP) {
        scanner->next();
    }

    if (scanner->getTypeLexem() == ID) {
        scanner->next();
    }

    if (scanner->getTypeLexem() == OPEN_KRUGLAY_SKOBKA) {
        scanner->next();

        expession();

        if (scanner->getTypeLexem() != CLOSE_KRUGLAY_SKOBKA) {
            log("Ожидался символ ')'");
        }
        scanner->next();
    }
}
