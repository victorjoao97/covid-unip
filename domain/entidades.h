#ifndef _STRUCTS_H_
#define _STRUCTS_H_
#include "../header.h"
struct Usuario
{
	int id;
	char nome[50];
	char senha[50];
};

struct Data
{
	int dia;
	int mes;
	int ano;
};

struct Endereco
{
	char rua[50];
	char numero[10];
	char bairro[50];
	char cidade[50];
	char estado[3];
	char cep[9];
};

struct Comorbidade
{
	int id;
	char nome[50];
};

struct Paciente
{
	int id;
	char nome[50];
	char cpf[12];
	char telefone[12];
	struct Endereco endereco;
	struct Data data_nascimento;
	int idade;
	char email[50];
	struct Data data_diagnostico;
	char comorbidades[120];
	int totalComorbidades;
};

struct ItensParaSelecionar
{
  int id;
  char *text;
};

#endif /* _STRUCTS_H_ */
