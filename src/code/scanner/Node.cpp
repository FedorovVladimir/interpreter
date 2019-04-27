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
        case INT: s << "INT" << " " << name << " " << valueInteger;
            break;
        case DOUBLE: s << "DOUBLE" << " " << name << " " << valueDouble;
            break;
        case MAIN: s << "MAIN";
            break;
        case ID: s << "ID" << " " << name;
            break;
        case CONST_INT: s << "CONST_INT" << " " <<  valueInteger;
            break;
        case CONST_DOUBLE: s << "CONST_FLOAT" << " " << valueDouble;
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
        case FUNCTION: s << "FUNCTION" << " " << name;
            break;
    }
    return s.str();
}

void Node::display(int a) {
    for (int i = 0; i < a; ++i) {
        cout << "    ";
    }
    cout << toString() << endl;
    if (right != nullptr) {
        right->display(a + 1);
    }
    if (left != nullptr) {
        left->display(a);
    }
}

Node *operator||(Node &n1, Node &n2) {
    TypeLexeme typeLexeme = CONST_INT;
    if (n1.getTypeLexem() == CONST_DOUBLE || n2.getTypeLexem() == CONST_DOUBLE) {
        typeLexeme = CONST_DOUBLE;
    }
    double value;

    if (n1.getTypeLexem() == CONST_INT) {
        value = n1.valueInteger;
    } else {
        value = n1.valueDouble;
    }

    double value2;
    if (n2.getTypeLexem() == CONST_INT) {
        value2 = n2.valueInteger;
    } else {
        value2 = n2.valueDouble;
    }
    return new Node(typeLexeme, to_string((bool)value || (bool)value2), "");
}

Node *operator&&(Node &n1, Node &n2) {

    TypeLexeme typeLexeme = CONST_INT;
    if (n1.getTypeLexem() == CONST_DOUBLE || n2.getTypeLexem() == CONST_DOUBLE) {
        typeLexeme = CONST_DOUBLE;
    }
    double value;

    if (n1.getTypeLexem() == CONST_INT) {
        value = n1.valueInteger;
    } else {
        value = n1.valueDouble;
    }

    double value2;
    if (n2.getTypeLexem() == CONST_INT) {
        value2 = n2.valueInteger;
    } else {
        value2 = n2.valueDouble;
    }
    return new Node(typeLexeme, to_string((bool)value && (bool)value2), "");
}

Node *operator!=(Node &n1, Node &n2) {
    TypeLexeme typeLexeme = CONST_INT;
    if (n1.getTypeLexem() == CONST_DOUBLE || n2.getTypeLexem() == CONST_DOUBLE) {
        typeLexeme = CONST_DOUBLE;
    }
    double value;

    if (n1.getTypeLexem() == CONST_INT) {
        value = n1.valueInteger;
    } else {
        value = n1.valueDouble;
    }

    double value2;
    if (n2.getTypeLexem() == CONST_INT) {
        value2 = n2.valueInteger;
    } else {
        value2 = n2.valueDouble;
    }
    return new Node(typeLexeme, to_string(value != value2), "");
}

Node *operator==(Node &n1, Node &n2) {
    TypeLexeme typeLexeme = CONST_INT;
    if (n1.getTypeLexem() == CONST_DOUBLE || n2.getTypeLexem() == CONST_DOUBLE) {
        typeLexeme = CONST_DOUBLE;
    }
    double value;

    if (n1.getTypeLexem() == CONST_INT) {
        value = n1.valueInteger;
    } else {
        value = n1.valueDouble;
    }

    double value2;
    if (n2.getTypeLexem() == CONST_INT) {
        value2 = n2.valueInteger;
    } else {
        value2 = n2.valueDouble;
    }
    return new Node(typeLexeme, to_string(value == value2), "");
}

Node *operator<=(Node &n1, Node &n2) {
    TypeLexeme typeLexeme = CONST_INT;
    if (n1.getTypeLexem() == CONST_DOUBLE || n2.getTypeLexem() == CONST_DOUBLE) {
        typeLexeme = CONST_DOUBLE;
    }
    double value;

    if (n1.getTypeLexem() == CONST_INT) {
        value = n1.valueInteger;
    } else {
        value = n1.valueDouble;
    }

    double value2;
    if (n2.getTypeLexem() == CONST_INT) {
        value2 = n2.valueInteger;
    } else {
        value2 = n2.valueDouble;
    }
    return new Node(typeLexeme, to_string(value <= value2), "");
}

Node *operator>=(Node &n1, Node &n2) {
    TypeLexeme typeLexeme = CONST_INT;
    if (n1.getTypeLexem() == CONST_DOUBLE || n2.getTypeLexem() == CONST_DOUBLE) {
        typeLexeme = CONST_DOUBLE;
    }
    double value;

    if (n1.getTypeLexem() == CONST_INT) {
        value = n1.valueInteger;
    } else {
        value = n1.valueDouble;
    }

    double value2;
    if (n2.getTypeLexem() == CONST_INT) {
        value2 = n2.valueInteger;
    } else {
        value2 = n2.valueDouble;
    }
    return new Node(typeLexeme, to_string(value >= value2), "");
}

Node *operator<(Node &n1, Node &n2) {
    TypeLexeme typeLexeme = CONST_INT;
    if (n1.getTypeLexem() == CONST_DOUBLE || n2.getTypeLexem() == CONST_DOUBLE) {
        typeLexeme = CONST_DOUBLE;
    }
    double value;

    if (n1.getTypeLexem() == CONST_INT) {
        value = n1.valueInteger;
    } else {
        value = n1.valueDouble;
    }

    double value2;
    if (n2.getTypeLexem() == CONST_INT) {
        value2 = n2.valueInteger;
    } else {
        value2 = n2.valueDouble;
    }
    return new Node(typeLexeme, to_string(value < value2), "");
}

Node *operator>(Node &n1, Node &n2) {
    TypeLexeme typeLexeme = CONST_INT;
    if (n1.getTypeLexem() == CONST_DOUBLE || n2.getTypeLexem() == CONST_DOUBLE) {
        typeLexeme = CONST_DOUBLE;
    }
    double value;

    if (n1.getTypeLexem() == CONST_INT) {
        value = n1.valueInteger;
    } else {
        value = n1.valueDouble;
    }

    double value2;
    if (n2.getTypeLexem() == CONST_INT) {
        value2 = n2.valueInteger;
    } else {
        value2 = n2.valueDouble;
    }
    return new Node(typeLexeme, to_string(value > value2), "");
}

Node *operator+(Node &n1, Node &n2) {
    TypeLexeme typeLexeme = CONST_INT;
    if (n1.getTypeLexem() == CONST_DOUBLE || n2.getTypeLexem() == CONST_DOUBLE) {
        typeLexeme = CONST_DOUBLE;
    }
    double value;

    if (n1.getTypeLexem() == CONST_INT) {
        value = n1.valueInteger;
    } else {
        value = n1.valueDouble;
    }

    if (n2.getTypeLexem() == CONST_INT) {
        value += n2.valueInteger;
    } else {
        value += n2.valueDouble;
    }
    return new Node(typeLexeme, to_string(value), "");
}

Node *operator-(Node &n1, Node &n2) {
    TypeLexeme typeLexeme = CONST_INT;
    if (n1.getTypeLexem() == CONST_DOUBLE || n2.getTypeLexem() == CONST_DOUBLE) {
        typeLexeme = CONST_DOUBLE;
    }
    double value;

    if (n1.getTypeLexem() == CONST_INT) {
        value = n1.valueInteger;
    } else {
        value = n1.valueDouble;
    }

    if (n2.getTypeLexem() == CONST_INT) {
        value -= n2.valueInteger;
    } else {
        value -= n2.valueDouble;
    }
    return new Node(typeLexeme, to_string(value), "");
}

Node *operator*(Node &n1, Node &n2) {
    TypeLexeme typeLexeme = CONST_INT;
    if (n1.getTypeLexem() == CONST_DOUBLE || n2.getTypeLexem() == CONST_DOUBLE) {
        typeLexeme = CONST_DOUBLE;
    }
    double value;

    if (n1.getTypeLexem() == CONST_INT) {
        value = n1.valueInteger;
    } else {
        value = n1.valueDouble;
    }

    if (n2.getTypeLexem() == CONST_INT) {
        value *= n2.valueInteger;
    } else {
        value *= n2.valueDouble;
    }
    return new Node(typeLexeme, to_string(value), "");
}

Node *operator/(Node &n1, Node &n2) {
    TypeLexeme typeLexeme = CONST_INT;
    if (n1.getTypeLexem() == CONST_DOUBLE || n2.getTypeLexem() == CONST_DOUBLE) {
        typeLexeme = CONST_DOUBLE;
    }
    double value;

    if (n1.getTypeLexem() == CONST_INT) {
        value = n1.valueInteger;
    } else {
        value = n1.valueDouble;
    }

    if (n2.getTypeLexem() == CONST_INT) {
        value /= n2.valueInteger;
    } else {
        value /= n2.valueDouble;
    }
    return new Node(typeLexeme, to_string(value), "");
}

string Node::getValue() {
    if (typeLexeme == CONST_INT || typeLexeme == INT) {
        return to_string(valueInteger);
    } else {
        return to_string(valueDouble);
    }
}

void Node::setValue(const string& value) {
    if (typeLexeme == INT) {
        valueInteger = atoi(value.c_str());
    } else {
        valueDouble = atof(value.c_str());
    }
}
