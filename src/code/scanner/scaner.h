#ifndef SCANER_H
#define SCANER_H
#include "defs.h"

using namespace std;

class Scanner
{
private:
    //Исходный текст
    TypeMod inputText;
    //Указатель на текущую позицию
    int currentPosition;

public:
    //Изменение текущего положения
    void putCP(int i);
    //Определение текущего положения
    int getCP();
    //Вывод ошибок
    void printError(char *, char *);
    void printErrorScan(char *, char *);
    //Разбор лексем
    int scanerMain(TypeLex lexeme);
    //Работа с файлом
    void getData(char *);
    //Запись лексемы до разделяющего символа
    int addLexeme(TypeLex lexeme, int i);

    Scanner(char *);
};

#endif // SCANER_H
