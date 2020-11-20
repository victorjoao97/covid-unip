#include <stdio.h>
#include "../header.h"


FILE* escreveArquivoComorbidadePaciente()
{
	FILE* arquivo;
	arquivo = escreveArquivo(joinDirFilename(DIRETORIO_ARQUIVOS, ARQUIVO_COMORBIDADE_PACIENTE), inicializaArquivoComorbidadePaciente);
	return arquivo;
}

void inicializaArquivoComorbidadePaciente(FILE *arquivo) {}