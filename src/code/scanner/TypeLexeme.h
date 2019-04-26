#ifndef DEFS_H
#define DEFS_H

enum TypeLexeme {

    // Ключевые слова
    IF,
    ELSE,
    VOID,
    INT,
    DOUBLE,
    MAIN,

    // Идентификатор
    ID,

    // Константы
    CONST_INT,
    CONST_DOUBLE,

    // Знаки арифметических операций
    PLUS,
    MINUS,
    DIV,
    MOD,
    MUL,
    INC,
    DEC,

    // Знаки логических операций
    AND,
    AND_AND,
    OR,
    OR_OR,

    // Сдвиги
    LARGER_LARGER,
    LESS_LESS,

    // Знаки сравнений
    LESS,
    LARGER,
    LESS_EQUAL,
    LARGER_EQUAL,
    EQUAL,
    NOT_EQUAL,
    SAVE,

    // Специальные знаки
    POINT_COMMA,
    OPEN_KRUGLAY_SKOBKA,
    CLOSE_KRUGLAY_SKOBKA,
    OPEN_FIGURNAY_SKOBKA,
    CLOSE_FIGURNAY_SKOBKA,
    COMMA,
    POINT,

    // Конец файла
    END_OF_FILE,

    // Ошибочный символ
    ERROR,

    // пустой
    EMPTY,

    // функция
    FUNCTION
};

#endif // DEFS_H
