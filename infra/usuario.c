#include <stdio.h>
#include <string.h>
#include "../header.h"

extern char *fileName;

FILE* leituraArquivoUsuarios()
{
	FILE* arquivo;
	arquivo = leituraArquivo(joinDirFilename(DIRETORIO_ARQUIVOS, ARQUIVO_USUARIOS), inicializaArquivoUsuarios);
	return arquivo;
}

FILE* escreveArquivoUsuarios()
{
	FILE* arquivo;
	arquivo = escreveArquivo(joinDirFilename(DIRETORIO_ARQUIVOS, ARQUIVO_USUARIOS), inicializaArquivoUsuarios);
	return arquivo;
}

void inicializaArquivoUsuarios(FILE *arquivo)
{
	fprintf(arquivo, "%d,%s,%s\n", 1, "admin", "CoViD0812");
}

void deleteUsuario(int linha)
{
	FILE* arquivo;
	arquivo = leituraArquivoUsuarios();
	deleteLine(arquivo, joinDirFilename(DIRETORIO_ARQUIVOS, ARQUIVO_USUARIOS), linha);
	fclose(arquivo);
}
