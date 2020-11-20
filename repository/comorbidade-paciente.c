#include "../header.h"

void adicionarComorbidadePaciente(struct Comorbidade comorbidade, struct Paciente paciente)
{
	FILE *arquivo = escreveArquivoComorbidadePaciente();
	fprintf(arquivo, "%d,%d\n", comorbidade.id, paciente.id);
	fclose(arquivo);
}