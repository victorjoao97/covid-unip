#include <stdio.h>
#include <string.h>
#include "../header.h"

extern int totalPacientes;
extern int limitPacientes;
extern struct Paciente *todosPacientes;

void adicionarPaciente(struct Paciente* paciente)
{
	int id = ultimoIdPaciente();
	id++;
	paciente->id = id;
	FILE *arquivo = escreveArquivoPacientes(joinDirFilename(DIRETORIO_ARQUIVOS, ARQUIVO_PACIENTES));
	fprintf(arquivo, "%d,%s,%s,%s,%s,%s,%s,%s,%s,%s,%d,%d,%d,%s,%d,%d,%d\n",
		paciente->id, paciente->nome, paciente->cpf, paciente->telefone, paciente->endereco.rua,
		paciente->endereco.numero, paciente->endereco.bairro, paciente->endereco.cidade,
		paciente->endereco.estado, paciente->endereco.cep, paciente->data_nascimento.dia,
		paciente->data_nascimento.mes, paciente->data_nascimento.ano, paciente->email,
		paciente->data_diagnostico.dia, paciente->data_diagnostico.mes, paciente->data_diagnostico.ano);
	fclose(arquivo);
}

void lerTodosPacientes()
{
	int i = 0, totalLinhas;
	FILE *arquivo = leituraArquivoPacientes();
	totalPacientes = 0;
	
	totalLinhas = totalDeLinhas(arquivo);
    realocaMemoriaPacientes(totalLinhas);
    
	char row[totalLinhas][(int)(sizeof(struct Paciente))];
    rewind(arquivo);
	while (fgets(row[i], sizeof(row[i]), arquivo) != NULL)
	{
		pacienteAdapter(row[i], &todosPacientes[i]);
		i++;
		totalPacientes++;
	}
	fclose(arquivo);
}

int ultimoIdPaciente()
{
	lerTodosPacientes();
	if (totalPacientes <= 0) return 0;
	int maiorId = todosPacientes[0].id;
	int i;
	for (i = 0; i < totalPacientes; i++)
	{
		if (strcmp(todosPacientes[i].nome, "") != 0 && todosPacientes[i].id > maiorId)
		{
			maiorId = todosPacientes[i].id;
		}
	}
	return maiorId;
}

void realocaMemoriaPacientes(int totalLinhas)
{
    if (totalLinhas > limitPacientes)
	{
		limitPacientes = (int)(totalLinhas + limitPacientes) * 1.2;
		todosPacientes = realloc(todosPacientes, sizeof(struct Paciente) * limitPacientes);
	}
}