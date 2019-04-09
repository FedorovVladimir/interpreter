#include "scaner.h"
#include "defs.h"

#include <string>
#include <cstring>

Scanner::Scanner(char *fileName)
{
    getData(fileName);
    putCP(0);
}
TypeLex keyWord[MAX_KEY_W] = {"if", "else", "struct", "void", "int", "double", "main"};
int indexKeyWord[MAX_KEY_W] = {T_IF, T_ELSE, T_STRUCT, T_VOID, T_INT, T_DOUBLE, T_MAIN};

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
            return TEnd;
        }
        goto start;
    }

    if (inputText[currentPosition] == '\0')
    {
        lexeme[0] = '#';
        return TEnd;
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

                return TConsInt;

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
        return TIdent;
    }
    else if (inputText[currentPosition] == '.')
    {
        lexeme[i++] = inputText[currentPosition++];
        if (inputText[currentPosition] <= '9' && inputText[currentPosition] >= '0')
        {
            lexeme[i++] = inputText[currentPosition++];
            goto N1;
        }
        return TPoint;
    }
    else if (inputText[currentPosition] == ',')
    {
        lexeme[i++] = inputText[currentPosition++];
        return TComma;
    }
    else if (inputText[currentPosition] == ';')
    {
        lexeme[i++] = inputText[currentPosition++];
        return TPC;
    }
    else if (inputText[currentPosition] == '(')
    {
        lexeme[i++] = inputText[currentPosition++];
        return TLS;
    }
    else if (inputText[currentPosition] == ')')
    {
        lexeme[i++] = inputText[currentPosition++];
        return TPS;
    }
    else if (inputText[currentPosition] == '{')
    {
        lexeme[i++] = inputText[currentPosition++];
        return TFLS;
    }
    else if (inputText[currentPosition] == '}')
    {
        lexeme[i++] = inputText[currentPosition++];
        return TFPS;
    }
    else if (inputText[currentPosition] == '*')
    {
        lexeme[i++] = inputText[currentPosition++];
        return TMult;
    }
    else if (inputText[currentPosition] == '%')
    {
        lexeme[i++] = inputText[currentPosition++];
        return TMod;
    }
    else if (inputText[currentPosition] == '/')
    {
        lexeme[i++] = inputText[currentPosition++];
        return TDiv;
    }
    else if (inputText[currentPosition] == '=')
    {
        lexeme[i++] = inputText[currentPosition++];
        if (inputText[currentPosition] == '=')
        {
            lexeme[i++] = inputText[currentPosition++];
            return TEQ;
        }
        else
            return TSave;
    }
    else if (inputText[currentPosition] == '!')
    {
        lexeme[i++] = inputText[currentPosition++];
        if (inputText[currentPosition] == '=')
        {
            lexeme[i++] = inputText[currentPosition++];
            return TNEQ;
        }
        else
        {
            printErrorScan("Error symbol", lexeme);
            return TError;
        }
    }
    else if (inputText[currentPosition] == '>')
    {
        lexeme[i++] = inputText[currentPosition++];
        if (inputText[currentPosition] == '=')
        {
            lexeme[i++] = inputText[currentPosition++];
            return TGE;
        }
        else if (inputText[currentPosition] == '>')
        {
            lexeme[i++] = inputText[currentPosition++];
            return TShiftR;
        }
        else
            return TGT;
    }
    else if (inputText[currentPosition] == '<')
    {
        lexeme[i++] = inputText[currentPosition++];
        if (inputText[currentPosition] == '=')
        {
            lexeme[i++] = inputText[currentPosition++];
            return TLE;
        }
        else if (inputText[currentPosition] == '<')
        {
            lexeme[i++] = inputText[currentPosition++];
            return TShiftL;
        }
        else
            return TLT;
    }
    else if (inputText[currentPosition] == '|')
    {
        lexeme[i++] = inputText[currentPosition++];
        if (inputText[currentPosition] == '|')
        {
            lexeme[i++] = inputText[currentPosition++];
            return TDoubleOr;
        }
        else
            return TOr;
    }
    else if (inputText[currentPosition] == '&')
    {
        lexeme[i++] = inputText[currentPosition++];
        if (inputText[currentPosition] == '&')
        {
            lexeme[i++] = inputText[currentPosition++];
            return TDoubleAnd;
        }
        else
            return TAnd;
    }
    else if (inputText[currentPosition] == '+')
    {
        lexeme[i++] = inputText[currentPosition++];
        if (inputText[currentPosition] == '+')
        {
            lexeme[i++] = inputText[currentPosition++];
            return TInc;
        }
        else
            return TPlus;
    }
    else if (inputText[currentPosition] == '-')
    {
        lexeme[i++] = inputText[currentPosition++];
        if (inputText[currentPosition] == '-')
        {
            lexeme[i++] = inputText[currentPosition++];
            return TDec;
        }
        else
            return TMinus;
    }
    else
    {
        lexeme[i++] = inputText[currentPosition++];
        printErrorScan("Unknown symbol", lexeme);
        return TError;
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
    return TConsFloat;
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
            return TError;
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
    return TConsExp;
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


