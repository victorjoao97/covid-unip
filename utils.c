#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <time.h>
#include <stdbool.h>
#include "header.h"
#include "libs/re.c"

extern char *fileName;

void pausaParaContinuar()
{
    printf("Pressione alguma tecla para continuar");
    fflush(stdin);
    getchar();
}

void limpaTela()
{
    #if defined(UNIX)
        system("clear");
    #else
        system("cls");
    #endif
}

void removeEndString(char *string)
{
    if (strcmp(&string[strlen(string) - 1], "\n") == 0)
        string[strlen(string) - 1] = '\0';
}

char* joinDirFilename(char *dir, char* filename)
{
    free(fileName);
    fileName = NULL;
    fileName = malloc(strlen(dir) + strlen(filename) + 1);
    if (fileName == NULL)
    {
        perror("Error: ");
    }
    strcpy(fileName, dir);
    strcat(fileName, filename);
    return fileName;
}

char *ltrim(char *s)
{
    while(isspace(*s)) s++;
    return s;
}

char *rtrim(char *s)
{
    char* back = s + strlen(s);
    while(isspace(*--back));
    *(back + 1) = '\0';
    return s;
}

char *trim(char *s)
{
    return rtrim(ltrim(s));
}

int calculaIdade(struct Data dataNascimento)
{
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int idade = 0;

    if ((tm.tm_mon + 1) == dataNascimento.mes)
    {
        if (tm.tm_mday <= dataNascimento.dia)
        {
            idade = (tm.tm_year + 1900) - dataNascimento.ano;
        }
        else
        {
            idade = (tm.tm_year + 1900) - dataNascimento.ano - 1;
        }
    }
    else if ((tm.tm_mon + 1) > dataNascimento.mes)
    {
        idade = (tm.tm_year + 1900) - dataNascimento.ano;
    }
    else
    {
        idade = (tm.tm_year + 1900) - dataNascimento.ano - 1;
    }
    return idade;
}

int validaPorRegex(char *expressao, char *stringTest)
{
    int matchs;

    re_match(expressao, stringTest, &matchs);

    return matchs;
}
