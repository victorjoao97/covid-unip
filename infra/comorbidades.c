#include <stdio.h>
#include <string.h>
#include "../header.h"

FILE* leituraArquivoComorbidades()
{
	FILE* arquivo;
	arquivo = leituraArquivo(joinDirFilename(DIRETORIO_ARQUIVOS, ARQUIVO_COMORBIDADES), inicializaArquivoComorbidades);
	return arquivo;
}

FILE* escreveArquivoComorbidades()
{
	FILE* arquivo;
	arquivo = escreveArquivo(joinDirFilename(DIRETORIO_ARQUIVOS, ARQUIVO_COMORBIDADES), inicializaArquivoComorbidades);
	return arquivo;
}

void inicializaArquivoComorbidades(FILE *arquivo)
{
	char *comorbidades[] = { "Diabetes", "Obesidade", "Hipertensao", "Tuberculose" };
	int i, sizeVetor;
	sizeVetor = sizeof(comorbidades)/sizeof(comorbidades[0]);
	
	for(i = 0; i < sizeVetor; i++)
	{
		int indice = i;
		fprintf(arquivo, "%d,%s\n", ++indice, comorbidades[i]);		
	}
}

void deleteComorbidade(int linha)
{
	FILE* arquivo;
	arquivo = leituraArquivoComorbidades();
	deleteLine(arquivo, joinDirFilename(DIRETORIO_ARQUIVOS, ARQUIVO_COMORBIDADES), linha);
	fclose(arquivo);
}