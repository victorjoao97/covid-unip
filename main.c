#include <locale.h>

#include "header.h"

int totalUsuarios = 0;
int totalPacientes = 0;
int totalComorbidades = 0;
int limitUsuarios = 100;
int limitPacientes = 100;
int limitComorbidades = 100;

char *fileName;
char *string;

struct Usuario *todosUsuarios;
struct Paciente *todosPacientes;
struct Comorbidade *todasComorbidades;

struct Usuario usuarioLogado = {-1};

int main()
{
	todosUsuarios = (struct Usuario*) malloc(sizeof(struct Usuario) * limitUsuarios);
	todosPacientes = (struct Paciente*) malloc(sizeof(struct Paciente) * limitPacientes);
	todasComorbidades = (struct Comorbidade*) malloc(sizeof(struct Comorbidade) * limitComorbidades);

	setlocale(LC_ALL, "Portuguese");

	headerMenu("Sistema Covid UNIP - PIM IV");

	criarDiretorio(DIRETORIO_ARQUIVOS);
	lerTodosUsuarios();
	lerTodosPacientes();
	lerTodasComorbidades();

	if (login(todosUsuarios))
	{
		menuPrincipal();
	}

	free(todosUsuarios);
	free(todosPacientes);
	free(todasComorbidades);
	free(fileName);

	return 0;
}
