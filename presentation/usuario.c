#include <stdio.h>
#include "../header.h"

extern int totalUsuarios;
extern struct Usuario *todosUsuarios;

void menuUsuarios()
{
	int opcao;
inicio:
	limpaTela();
	headerMenu("USU�RIOS");
	printf("1 - Cadastrar \n2 - Mostrar\n3 - Deletar\n0 - Voltar\n");
	scanf("%d", &opcao);
	limpaTela();
	switch (opcao)
	{
	case 1:
		headerMenu("CADASTRAR USU�RIO");
		cadastrarUsuario();
		goto inicio;
		break;
	case 2:
		headerMenu("MOSTRAR USU�RIOS");
		mostrarUsuarios();
		goto inicio;
		break;
	case 3:
		headerMenu("DELETAR USU�RIO");
		deletarUsuario();
		goto inicio;
		break;
	case 0:
		break;
	default:
		mensagemAviso("Voce deve escolher uma opcao valida\n");
		goto inicio;
	}

}

void mostrarUsuarios()
{
	struct Usuario usuario;
	lerTodosUsuarios();
	const int inicioUsuario = 1;
	int contadorPulaAdmin = inicioUsuario;
	
	if (totalUsuarios == inicioUsuario)
	{
		mensagemErro("Nenhum usu�rio encontrado\n");
		return;
	}

	for(contadorPulaAdmin = inicioUsuario; contadorPulaAdmin < totalUsuarios; contadorPulaAdmin++)
	{
		usuario = todosUsuarios[contadorPulaAdmin];
		printf("ID: %d, Nome: %s\n", usuario.id, usuario.nome);
	}
	pausaParaContinuar();
}