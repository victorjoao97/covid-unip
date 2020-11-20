#include <stdio.h>
#include "../header.h"


FILE* escreveArquivoPacientesRisco()
{
	FILE* arquivo;
	arquivo = escreveArquivo(ARQUIVO_PACIENTES_RISCO, inicializaArquivoPacientesRisco);
	return arquivo;
}

void inicializaArquivoPacientesRisco(FILE *arquivo) {}
