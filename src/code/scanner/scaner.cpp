#include "scaner.h"
#include "Lexeme.h"

#include <string>
#include <cstring>
#include <iostream>

Scanner::Scanner(char *fileName)
{
    getData(fileName);
    putCP(0);
}
TypeLex keyWord[MAX_KEY_W] = {"if", "else", "void", "int", "double", "main"};
int indexKeyWord[MAX_KEY_W] = {IF, ELSE, VOID, INT, DOUBLE, MAIN};

void Scanner::putCP(int i)
{
    currentPosition = i;
}

int Scanner::getCP()
{
    return currentPosition;
}

void Scanner::printErrorScan(char *errors, char *symbol)
{
    if (symbol[0] == '\0')
        cout << "Error : " << errors << symbol << endl;
    else
        cout << "Error : " << errors << "\nSymbol is not correct: " << symbol <<endl;
}

void Scanner::printError(char *errors, char *symbol)
{
    if (symbol[0] == '\0')
        cout << "Error : " << errors << symbol << endl;
    else if(symbol[0] == '#')
         {
            cout << "Errors 0!" << endl;
            exit(0);
         }
         else
            cout << "Error : " << errors << " instead " << symbol <<endl;
    exit(0);
}

int Scanner::scanerMain(TypeLex lexeme)
{
    //Текущая длина лексемы
    int i;
    for (i = 0; i < MAX_LEX; i++)
        lexeme[i] = 0;
    i = 0;
    start:

    while (inputText[currentPosition] == ' ' || inputText[currentPosition] == '\n' || inputText[currentPosition] == '\t')
        currentPosition++;

    if (inputText[currentPosition] == '/' && inputText[currentPosition + 1] == '/')
    {
        currentPosition += 2;
        while (inputText[currentPosition] != '\n' && inputText[currentPosition] != '\0')
            currentPosition++;
        if (inputText[currentPosition] == '\0')
        {
            lexeme[0] = '#';
            return END_OF_FILE;
        }
        goto start;
    }

    if (inputText[currentPosition] == '\0')
    {
        lexeme[0] = '#';
        return END_OF_FILE;
    }
    if (inputText[currentPosition] <= '9' && inputText[currentPosition] >= '0')
    {
        lexeme[i++] = inputText[currentPosition++];
            while(inputText[currentPosition] <= '9' && inputText[currentPosition] >= '0')
            {
                if (i < MAX_LEX - 1)
                    lexeme[i++] = inputText[currentPosition++];
                else
                    currentPosition++;
            }
                if (inputText[currentPosition] == '.')
                {
                    lexeme[i++] = inputText[currentPosition++];
                    goto N1;
                }
                else if (inputText[currentPosition] == 'E' || inputText[currentPosition] == 'e')
                {
                    lexeme[i++] = inputText[currentPosition++];
                    goto N2;
                }

                return CONST_INT;

    }
    else if (inputText[currentPosition] >= 'a' && inputText[currentPosition] <= 'z' || inputText[currentPosition] >= 'A' && inputText[currentPosition] <= 'Z')
    {
        lexeme[i++] = inputText[currentPosition++];
        while (inputText[currentPosition] <= '9' && inputText[currentPosition] >= '0' || inputText[currentPosition] >= 'a' && inputText[currentPosition] <= 'z' || inputText[currentPosition] >= 'A' && inputText[currentPosition] <= 'Z')
        {
            if (i < MAX_LEX - 1)
                lexeme[i++] = inputText[currentPosition++];
            else
                currentPosition++;
        }
        int elementKeyWord;
        for (elementKeyWord = 0; elementKeyWord < MAX_KEY_W; elementKeyWord++)
        {
            if (strcmp(lexeme, keyWord[elementKeyWord]) == 0)
            {
                return indexKeyWord[elementKeyWord];
            }
        }
        return ID;
    }
    else if (inputText[currentPosition] == '.')
    {
        lexeme[i++] = inputText[currentPosition++];
        if (inputText[currentPosition] <= '9' && inputText[currentPosition] >= '0')
        {
            lexeme[i++] = inputText[currentPosition++];
            goto N1;
        }
        return POINT;
    }
    else if (inputText[currentPosition] == ',')
    {
        lexeme[i++] = inputText[currentPosition++];
        return COMMA;
    }
    else if (inputText[currentPosition] == ';')
    {
        lexeme[i++] = inputText[currentPosition++];
        return POINT_COMMA;
    }
    else if (inputText[currentPosition] == '(')
    {
        lexeme[i++] = inputText[currentPosition++];
        return OPEN_KRUGLAY_SKOBKA;
    }
    else if (inputText[currentPosition] == ')')
    {
        lexeme[i++] = inputText[currentPosition++];
        return CLOSE_KRUGLAY_SKOBKA;
    }
    else if (inputText[currentPosition] == '{')
    {
        lexeme[i++] = inputText[currentPosition++];
        return OPEN_FIGURNAY_SKOBKA;
    }
    else if (inputText[currentPosition] == '}')
    {
        lexeme[i++] = inputText[currentPosition++];
        return CLOSE_FIGURNAY_SKOBKA;
    }
    else if (inputText[currentPosition] == '*')
    {
        lexeme[i++] = inputText[currentPosition++];
        return MUL;
    }
    else if (inputText[currentPosition] == '%')
    {
        lexeme[i++] = inputText[currentPosition++];
        return MOD;
    }
    else if (inputText[currentPosition] == '/')
    {
        lexeme[i++] = inputText[currentPosition++];
        return DIV;
    }
    else if (inputText[currentPosition] == '=')
    {
        lexeme[i++] = inputText[currentPosition++];
        if (inputText[currentPosition] == '=')
        {
            lexeme[i++] = inputText[currentPosition++];
            return EQUAL;
        }
        else
            return SAVE;
    }
    else if (inputText[currentPosition] == '!')
    {
        lexeme[i++] = inputText[currentPosition++];
        if (inputText[currentPosition] == '=')
        {
            lexeme[i++] = inputText[currentPosition++];
            return NOT_EQUAL;
        }
        else
        {
            printErrorScan("Error symbol", lexeme);
            return ERROR;
        }
    }
    else if (inputText[currentPosition] == '>')
    {
        lexeme[i++] = inputText[currentPosition++];
        if (inputText[currentPosition] == '=')
        {
            lexeme[i++] = inputText[currentPosition++];
            return LARGER_EQUAL;
        }
        else if (inputText[currentPosition] == '>')
        {
            lexeme[i++] = inputText[currentPosition++];
            return LARGER_LARGER;
        }
        else
            return LARGER;
    }
    else if (inputText[currentPosition] == '<')
    {
        lexeme[i++] = inputText[currentPosition++];
        if (inputText[currentPosition] == '=')
        {
            lexeme[i++] = inputText[currentPosition++];
            return LESS_EQUAL;
        }
        else if (inputText[currentPosition] == '<')
        {
            lexeme[i++] = inputText[currentPosition++];
            return LESS_LESS;
        }
        else
            return LESS;
    }
    else if (inputText[currentPosition] == '|')
    {
        lexeme[i++] = inputText[currentPosition++];
        if (inputText[currentPosition] == '|')
        {
            lexeme[i++] = inputText[currentPosition++];
            return OR_OR;
        }
        else
            return OR;
    }
    else if (inputText[currentPosition] == '&')
    {
        lexeme[i++] = inputText[currentPosition++];
        if (inputText[currentPosition] == '&')
        {
            lexeme[i++] = inputText[currentPosition++];
            return AND_AND;
        }
        else
            return AND;
    }
    else if (inputText[currentPosition] == '+')
    {
        lexeme[i++] = inputText[currentPosition++];
        if (inputText[currentPosition] == '+')
        {
            lexeme[i++] = inputText[currentPosition++];
            return INC;
        }
        else
            return PLUS;
    }
    else if (inputText[currentPosition] == '-')
    {
        lexeme[i++] = inputText[currentPosition++];
        if (inputText[currentPosition] == '-')
        {
            lexeme[i++] = inputText[currentPosition++];
            return DEC;
        }
        else
            return MINUS;
    }
    else
    {
        lexeme[i++] = inputText[currentPosition++];
        printErrorScan("Unknown symbol", lexeme);
        return ERROR;
    }
    N1:
    while (inputText[currentPosition] <= '9' && inputText[currentPosition] >= '0')
    {
        if (i < MAX_LEX - 1)
            lexeme[i++] = inputText[currentPosition++];
        else
            currentPosition++;
    }
    if (inputText[currentPosition] == 'E' || inputText[currentPosition] == 'e')
    {
        lexeme[i++] = inputText[currentPosition++];
        goto N2;
    }
    return CONST_FLOAT;
    N2:
    if (inputText[currentPosition] == '+' || inputText[currentPosition] == '-')
    {
        lexeme[i++] = inputText[currentPosition++];
        if (inputText[currentPosition] <= '9' && inputText[currentPosition] >= '0')
        {
            if (i < MAX_LEX - 1)
                lexeme[i++] = inputText[currentPosition++];
            else
                currentPosition++;
            goto N3;
        }
        else
        {
            printErrorScan("Error const", lexeme);
            return ERROR;
        }    
    }
    /*else if(inputText[currentPosition] == ' ' || inputText[currentPosition] == '\n' || inputText[currentPosition] == '\t' || inputText[currentPosition] != ';')
    {
        int tmp = addLexeme(lexeme, i);
        return tmp;
    }*/
    N3:
    while (inputText[currentPosition] <= '9' && inputText[currentPosition] >= '0')
    {
        if (i < MAX_LEX - 1)
            lexeme[i++] = inputText[currentPosition++];
        else
            currentPosition++;
    }
    return CONST_EXP;
}

void Scanner::getData(char *fileName)
{
    char elementText;
    FILE * input = fopen (fileName, "r");
    if (input == NULL)
    {
        printErrorScan("File error", "");
        //exit (1);
    }
    int i = 0;
    while (!feof (input))
    {
        fscanf (input, "%c", &elementText);
        if (!feof (input))
            inputText[i++] = elementText;
        if (i >= MAX_TEXT - 1)
        {
            printErrorScan("Text over","");
            break;
        }
    }
    inputText[i] = '\0';
    fclose (input);
}


