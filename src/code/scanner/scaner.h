#ifndef SCANER_H
#define SCANER_H
#include "Lexeme.h"

//Максимальная длина текста, лексемы
#define MAX_TEXT 1000
#define MAX_LEX 30
//Число ключевых слов
#define MAX_KEY_W 7

using namespace std;

typedef char TypeLex[MAX_LEX];
typedef char TypeMod[MAX_TEXT];

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
