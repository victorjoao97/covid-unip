#include "../header.h"

void adicionarArquivoPacientesRisco(struct Paciente* paciente)
{
	FILE *arquivo = escreveArquivoPacientesRisco();
	fprintf(arquivo, "%s,%d\n", paciente->endereco.cep, paciente->idade);
	fclose(arquivo);
}