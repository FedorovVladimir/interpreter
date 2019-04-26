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
    TypeLexeme type = scanner->getTypeLexem();
    scanner->next();

    do {
        if (scanner->getTypeLexem() == COMMA) {
            scanner->next();
        }

        if (scanner->getTypeLexem() != ID) {
            log("Ожидалася идентификатор");
        }
        string name = scanner->getCurrentNode()->name;
        scanner->next();

        string value;
        if (scanner->getTypeLexem() == SAVE) {
            scanner->next();
            Node* pNode = expession();
            if (pNode->getTypeLexem() == CONST_DOUBLE) {
                value = to_string(pNode->valueDouble);
            } else {
                value = to_string(pNode->valueInteger);
            }
        }
        addNode(new Node(type, value, name));
    } while (scanner->getTypeLexem() == COMMA);
}

void Lexer::opisanieFunction() {
    logPath("Описание функции");
    scanner->next();

    if (scanner->getTypeLexem() != ID && scanner->getTypeLexem() != MAIN) {
        log("Ожидалася идентификатор");
    }
    string name = scanner->getCurrentNode()->name;
    if (scanner->getTypeLexem() == MAIN) {
        name = "main";
    }
    scanner->next();

    addNode(new Node(FUNCTION, "", name));

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

void Lexer::logPath(const string& text) {
    if (debug) {
        cout << text << endl;
    }
}

void Lexer::opisanieOperatora() {
    logPath("Описание оператора");
    if (scanner->getTypeLexem() == OPEN_FIGURNAY_SKOBKA) {
        scanner->next();
        in();

        opisanieOperatorov();

        if (scanner->getTypeLexem() != CLOSE_FIGURNAY_SKOBKA) {
            log("Ожидалася символ'}'");
        }
        scanner->next();
        out();
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

    if (scanner->getTypeLexem() == CONST_INT || scanner->getTypeLexem() == CONST_DOUBLE) {
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

    Node* pNode = expession();
    if (getVar(pNode->name)) {
        getVar(pNode->name)->setValue(pNode->getValue());
    }
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

Node* Lexer::expession() {
    logPath("Обработка || &&");

    Node* pNode = expession2();
    while (scanner->getTypeLexem() == OR_OR || scanner->getTypeLexem() == AND_AND) {
        TypeLexeme type = scanner->getTypeLexem();
        scanner->next();
        if (type == OR_OR) {
            pNode = *pNode || *expession2();
        } else {
            pNode = *pNode && *expession2();
        }
    }
    return pNode;
}

Node* Lexer::expession2() {
    logPath("Обработка != ==");

    Node* pNode = expession3();
    while (scanner->getTypeLexem() == NOT_EQUAL || scanner->getTypeLexem() == EQUAL) {
        TypeLexeme type = scanner->getTypeLexem();
        scanner->next();
        if (type == NOT_EQUAL) {
            pNode = *pNode != *expession3();
        } else {
            pNode = *pNode == *expession3();
        }
    }
    return pNode;
}

Node* Lexer::expession3() {
    logPath("Обработка <= >= < >");

    Node* pNode = expession4();
    while (scanner->getTypeLexem() == LARGER_EQUAL || scanner->getTypeLexem() == LESS_EQUAL || scanner->getTypeLexem() == LARGER || scanner->getTypeLexem() == LESS) {
        TypeLexeme type = scanner->getTypeLexem();
        scanner->next();
        if (type == LARGER_EQUAL) {
            pNode = *pNode >= *expession4();
        } else if (type == LESS_EQUAL) {
            pNode = *pNode <= *expession4();
        } else if (type == LARGER) {
            pNode = *pNode > *expession4();
        } else {
            pNode = *pNode < *expession4();
        }
    }
    return pNode;
}

Node* Lexer::expession4() {
    logPath("Обработка + -");

    Node* pNode = expession5();
    while (scanner->getTypeLexem() == PLUS || scanner->getTypeLexem() == MINUS) {
        TypeLexeme type = scanner->getTypeLexem();
        scanner->next();
        if (type == PLUS) {
            pNode = *pNode + *expession5();
        } else {
            pNode = *pNode - *expession5();
        }
    }
    return pNode;
}

Node* Lexer::expession5() {
    logPath("Обработка * /");

    Node* pNode = expession6();
    while (scanner->getTypeLexem() == MUL || scanner->getTypeLexem() == DIV) {
        TypeLexeme type = scanner->getTypeLexem();
        scanner->next();
        if (type == MUL) {
            pNode = *pNode * *expession5();
        } else {
            pNode = *pNode / *expession5();
        }
    }
    return pNode;
}

Node* Lexer::expession6() {
    logPath("Обработка простого выражения");

    if (scanner->getTypeLexem() == CONST_INT) {
        Node* pNode = scanner->getCurrentNode();
        scanner->next();
        return pNode;
    }

    if (scanner->getTypeLexem() == CONST_DOUBLE) {
        Node* pNode = scanner->getCurrentNode();
        scanner->next();
        return pNode;
    }

    if (scanner->getTypeLexem() == ID) {
        // todo
        scanner->next();
    }

    if (scanner->getTypeLexem() == OPEN_KRUGLAY_SKOBKA) {
        scanner->next();

        Node* pNode = expession();

        if (scanner->getTypeLexem() != CLOSE_KRUGLAY_SKOBKA) {
            log("Ожидался символ ')'");
        }
        scanner->next();
        return pNode;
    }
}

Node* Lexer::getVar(const string& name) {
    Node* p = current;
    do {
        if (p->name == name) {
            return p;
        }
        p = p->parent;
    } while (p->parent);
    return nullptr;
}

void Lexer::addNode(Node *pNode) {
    current->left = pNode;
    pNode->parent = current;
    current = current->left;
}

void Lexer::in() {
    current->right = new Node(EMPTY);
    current->right->parent = current;
    current = current->right;
}

void Lexer::out() {
    Node* n = current;
    while (n->right == nullptr) {
        n = n->parent;
    }
    n->left = new Node(EMPTY);
    n->left->parent = n;
    current = n->left;
}
