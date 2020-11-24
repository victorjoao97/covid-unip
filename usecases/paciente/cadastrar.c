#include <string.h>
#include "../../header.h"

extern int totalPacientes;
extern int totalComorbidades;
extern struct Paciente *todosPacientes;
extern struct Comorbidade *todasComorbidades;

void cadastrarPaciente()
{
	struct Paciente paciente;

	inicioNome: ;
	leituraChar("Digite o nome completo do paciente: ", paciente.nome, sizeof(paciente.nome));
	if (validaPorRegex("^[a-zA-Z ]*$", paciente.nome) < 5)
	{
		mensagemErroSemLimpar("Minimo de 5 caracteres\n");
		goto inicioNome;
	}

    inicioCpf: ;
	leituraChar("Digite o CPF do paciente: ", paciente.cpf, sizeof(paciente.cpf));
	if (validaPorRegex("^[0-9]*$", paciente.cpf) != 11)
	{
		mensagemErroSemLimpar("Digite os 11 digitos do CPF\n");
		goto inicioCpf;
	}

	inicioTelefone: ;
	leituraChar("Digite o telefone do paciente: ", paciente.telefone, sizeof(paciente.telefone));
	if (validaPorRegex("^[0-9]*$", paciente.telefone) < 10 && validaPorRegex("^[0-9]*$", paciente.telefone) > 11)
	{
		mensagemErroSemLimpar("Digite o numero do telefone com DDD\n");
		goto inicioTelefone;
	}

	inicioEmail: ;
	printf("Digite o email do paciente: ");
	fgets(paciente.email, sizeof(paciente.email), stdin);
	if (validaPorRegex("^[\\w\\.]+\\@[\\w\\.]+\\.[\\w\\.]+$", paciente.email) != strlen(paciente.email))
	{
		mensagemErroSemLimpar("Digite um email v�lido\n");
		goto inicioEmail;
	}

	leituraEndereco("---Preencha os dados de endere�o do paciente---\n", &paciente.endereco);
	leituraData("---Preencha a data de nascimento do paciente---\n", &paciente.data_nascimento);
	leituraData("---Preencha a data de diagn�stico do paciente---\n", &paciente.data_diagnostico);

	adicionarPaciente(&paciente);
	leituraChar("Digite as comorbidades se houver: ", paciente.comorbidades, sizeof(paciente.comorbidades));
	mensagemSucesso("Paciente cadastrado com sucesso\n");

	verificaESalvaGrupoRisco(&paciente);
}

void verificaESalvaGrupoRisco(struct Paciente* paciente)
{
	paciente->idade = calculaIdade(paciente->data_nascimento);

	if (paciente->idade >= IDADE_GRUPO_RISCO && strlen(paciente->comorbidades) > 0)
	{
		adicionarArquivoPacientesRisco(paciente);
		mensagemAviso("Paciente tem comorbidades e est� no grupo de risco\nAssim foi salvo no arquivo %s\n", ARQUIVO_PACIENTES_RISCO);
	} else if (paciente->idade >= IDADE_GRUPO_RISCO) {
		mensagemAviso("O paciente n�o tem comorbidade, mas est� no grupo de risco\n");
	}
}
