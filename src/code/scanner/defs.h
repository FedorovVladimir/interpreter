#ifndef DEFS_H
#define DEFS_H

#include <fstream>
#include <cstring>

#include <iostream>
#include <string>

using namespace std;


enum Lexeme
{
    //Максимальная длина текста, лексемы
    MAX_TEXT = 1000,
    MAX_LEX = 30,
    //Число ключевых слов
    MAX_KEY_W = 7,
    //Ключевые слова
    T_IF = 1,
    T_ELSE = 2,
    T_STRUCT = 3,
    T_VOID = 4,
    T_INT = 5,
    T_DOUBLE = 6,
    T_MAIN = 7,
    //Идентификатор
    TIdent = 10,
    //Константы
    TConsInt = 20,
    TConsFloat = 21,
    TConsExp = 22,
    //Знаки операций
    TPlus = 30,
    TMinus = 31,
    TDiv = 32,
    TMult = 33,
    TMod = 34,
    TInc = 35,
    TDec = 36,
    TAnd = 37,
    TDoubleAnd = 38,
    TOr = 39,
    TDoubleOr = 40,
    TXor = 41,
    TShiftR = 42,
    TShiftL = 43,
    TLT = 44,
    TGT = 45,
    TLE = 46,
    TGE = 47,
    TEQ = 48,
    TNEQ = 49,
    TSave = 50,
    //Специальные знаки
    TPC = 60,
    TLS = 61,
    TPS = 62,
    TFLS = 63,
    TFPS = 64,
    TComma = 65,
    TPoint = 66,
    //Конец исходного модуля
    TEnd = 100,
    //Ошибочный символ
    TError = 200
};

enum DataType
{ 
    semInt = 1,
    semDouble,
    semFunc,
    semStruct,
    semUndefine = 0
};

#define NUMSEMTYPES 2
using namespace std;
typedef char TypeLex[MAX_LEX];
typedef char TypeMod[MAX_TEXT];

#endif // DEFS_H
