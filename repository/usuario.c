#include <stdio.h>
#include <string.h>
#include "../header.h"

extern int totalUsuarios;
extern struct Usuario *todosUsuarios;
extern int limitUsuarios;

void adicionarUsuario(struct Usuario usuario)
{
	int id = ultimoIdUsuario();
	id++;
	FILE *arquivo = escreveArquivoUsuarios(ARQUIVO_USUARIOS);
	fprintf(arquivo, "%d,%s,%s\n", id, usuario.nome, usuario.senha);
	fclose(arquivo);
}

void lerTodosUsuarios()
{
	int i, totalLinhas;
	FILE *arquivo = leituraArquivoUsuarios();
	totalUsuarios = 0;
	i = 0;

    totalLinhas = totalDeLinhas(arquivo);
    realocaMemoriaUsuarios(totalLinhas);
    
	char row[limitUsuarios][(int)(sizeof(struct Usuario))];
    rewind(arquivo);
	while (fgets(row[i], sizeof(row[i]), arquivo) != NULL)
	{
		usuarioAdapter(row[i], &todosUsuarios[i]);
		i++;
		totalUsuarios++;
	}
	fclose(arquivo);
}

int ultimoIdUsuario()
{
	lerTodosUsuarios();
	int maiorId = todosUsuarios[0].id;
	int i;
	for (i = 0; i < totalUsuarios; i++)
	{
		if (strcmp(todosUsuarios[i].nome, "") != 0 && todosUsuarios[i].id > maiorId)
		{
			maiorId = todosUsuarios[i].id;
		}
	}
	return maiorId;
}

struct Usuario usuarioPeloId(int id)
{
	int i, idUser = -1;
	for (i = 0; i < totalUsuarios; i++)
	{
		if (todosUsuarios[i].id == id)
		{
			idUser = i;
		}
	}
	return todosUsuarios[idUser];
}

void realocaMemoriaUsuarios(int totalLinhas)
{
    if (totalLinhas > limitUsuarios)
	{
		limitUsuarios = (int)(totalLinhas + limitUsuarios) * 1.2;
		todosUsuarios = realloc(todosUsuarios, sizeof(struct Usuario) * limitUsuarios);
	}
}