#include <string.h>
#include "../header.h"

void usuarioAdapter(char *file, struct Usuario *usuario)
{
	removeEndString(file);
	int contador = 0;
	char *p;
	for (p = strtok(file, ","); p != NULL; p = strtok(NULL, ","))
	{
		switch (contador)
		{
		case 0:
			usuario->id = atoi(p);
			break;
		case 1:
			strcpy(usuario->nome, p);
			break;
		case 2:
			strcpy(usuario->senha, p);
			break;
		default:
			break;
		}
		contador++;
	}
}

void pacienteAdapter(char *file, struct Paciente *paciente)
{
	removeEndString(file);
	int contador = 0;
	char *p;
	for (p = strtok(file, ","); p != NULL; p = strtok(NULL, ","))
	{
		switch (contador)
		{
		case 0:
			paciente->id = atoi(p);
			break;
		case 1:
			strcpy(paciente->nome, p);
			break;
		case 2:
			strcpy(paciente->cpf, p);
			break;
		case 3:
			strcpy(paciente->telefone, p);
			break;
		case 4:
			strcpy(paciente->endereco.rua, p);
			break;
		case 5:
			strcpy(paciente->endereco.numero, p);
			break;
		case 6:
			strcpy(paciente->endereco.bairro, p);
			break;
		case 7:
			strcpy(paciente->endereco.cidade, p);
			break;
		case 8:
			strcpy(paciente->endereco.estado, p);
			break;
		case 9:
			strcpy(paciente->endereco.cep, p);
			break;
		case 10:
			paciente->data_nascimento.dia = atoi(p);
			break;
		case 11:
			paciente->data_nascimento.mes = atoi(p);
			break;
		case 12:
			paciente->data_nascimento.ano = atoi(p);
			break;
		case 13:
			strcpy(paciente->email, p);
			break;
		case 14:
			paciente->data_diagnostico.dia = atoi(p);
			break;
		case 15:
			paciente->data_diagnostico.mes = atoi(p);
			break;
		case 16:
			paciente->data_diagnostico.ano = atoi(p);
			break;
		default:
			break;
		}
		contador++;
	}
}

void comorbidadeAdapter(char *file, struct Comorbidade *comorbidade)
{
	removeEndString(file);
	int contador = 0;
	char *p;
	for (p = strtok(file, ","); p != NULL; p = strtok(NULL, ","))
	{
		switch (contador)
		{
		case 0:
			comorbidade->id = atoi(p);
			break;
		case 1:
			strcpy(comorbidade->nome, p);
			break;
		default:
			break;
		}
		contador++;
	}
}