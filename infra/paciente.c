#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../header.h"

extern char *fileName;

FILE* leituraArquivoPacientes()
{
	FILE* arquivo;
	arquivo = leituraArquivo(joinDirFilename(DIRETORIO_ARQUIVOS, ARQUIVO_PACIENTES), inicializaArquivoPacientes);
	return arquivo;
}

FILE* escreveArquivoPacientes()
{
	FILE* arquivo;
	arquivo = escreveArquivo(joinDirFilename(DIRETORIO_ARQUIVOS, ARQUIVO_PACIENTES), inicializaArquivoPacientes);
	return arquivo;
}

void inicializaArquivoPacientes(FILE *arquivo) {}