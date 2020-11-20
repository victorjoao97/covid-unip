#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include "../header.h"

FILE* escreveArquivo(char *nomeArquivo, void (*callback)(FILE*))
{
	FILE *arquivo;
inicio:
	arquivo = fopen(nomeArquivo, "a");

	if (arquivo == NULL)
	{
		if (criaArquivoSeNaoExiste(nomeArquivo, callback))
			goto inicio;
		mensagemErro(strcat("Erro ao abrir o arquivo: ", nomeArquivo));
		exit(1);
	}
	return arquivo;
}

bool criaArquivoSeNaoExiste(char *nomeArquivo, void callback(FILE*))
{
	FILE *arquivo;
	arquivo = fopen(nomeArquivo, "w");
	if (arquivo == NULL)
	{
		mensagemErro(strcat("Erro ao criar o arquivo: ", nomeArquivo));
		return false;
	}
	mensagemSucesso("Arquivo %s não existia, e foi criado com sucesso\n", nomeArquivo);
	(*callback)(arquivo);
	fclose(arquivo);
	return true;
}

FILE* leituraArquivo(char *nomeArquivo, void (*callback)(FILE*))
{
	FILE *arquivo;
inicio:
	arquivo = fopen(nomeArquivo, "r");

	if (arquivo == NULL)
	{
		if (criaArquivoSeNaoExiste(nomeArquivo, callback))
			goto inicio;
		mensagemErro(strcat("Erro ao abrir o arquivo: ", nomeArquivo));
		exit(1);
	}
	return arquivo;
}

void deleteLine(FILE *srcFile, char *fileName, const int line)
{
	FILE* tempFile = fopen("delete-line.txt", "w");
	char buffer[BUFFER_SIZE];
	int count = 0;

	while ((fgets(buffer, BUFFER_SIZE, srcFile)) != NULL)
	{
		if (line != count)
			fputs(buffer, tempFile);

		count++;
	}
	fclose(srcFile);
	fclose(tempFile);
	remove(fileName);
	rename("delete-line.txt", fileName);
}

void deleteLines(FILE *srcFile, char *fileName, const int *lines)
{
	FILE* tempFile = fopen("delete-lines.txt", "w");
	char buffer[BUFFER_SIZE];
	int count = 0;

	while ((fgets(buffer, BUFFER_SIZE, srcFile)) != NULL)
	{
		if (lines[count] != count)
			fputs(buffer, tempFile);

		count++;
	}
	fclose(srcFile);
	fclose(tempFile);
	remove(fileName);
	rename("delete-lines.txt", fileName);
}

void criarDiretorio(char *diretorio)
{
	struct stat st = {0};
	if (stat(diretorio, &st) == -1) {
	    mkdir(diretorio);
	}
}

int totalDeLinhas(FILE *arquivo)
{
	int count_lines = 0;
	char chr = getc(arquivo);
    while (chr != EOF)
    {
        if (chr == '\n')
        {
            count_lines += 1;
        }
        chr = getc(arquivo);
    }
    return count_lines;
}