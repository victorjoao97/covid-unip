#include <stdio.h>
#include <conio.h>
#include "../../header.h"

extern struct Usuario *todosUsuarios;
extern int totalUsuarios;

void deletarUsuario()
{	
	lerTodosUsuarios();
	const int inicioUsuario = 1;
	int contadorPulaAdmin = inicioUsuario;
	
	
	if (totalUsuarios == inicioUsuario)
	{
		mensagemErro("Nenhum usuário encontrado\n");
		return;
	}
	
	int usuarioSelecionado;
	struct ItensParaSelecionar *itensParaSelecionar = malloc((totalUsuarios - inicioUsuario) * sizeof(*itensParaSelecionar));
	
	for(contadorPulaAdmin = inicioUsuario; contadorPulaAdmin < totalUsuarios; contadorPulaAdmin++)
	{
		itensParaSelecionar[contadorPulaAdmin-inicioUsuario].id = todosUsuarios[contadorPulaAdmin].id;
		itensParaSelecionar[contadorPulaAdmin-inicioUsuario].text = todosUsuarios[contadorPulaAdmin].nome;
	}
	usuarioSelecionado = selectWithArrows(&itensParaSelecionar, "DELETAR USUÁRIO", "um usuário", totalUsuarios - inicioUsuario);
	if (usuarioSelecionado == -1)
	{
		mensagemAviso("Nenhum usuário selecionado\n");
		return;
	}
	else
	{
		deleteUsuario(usuarioSelecionado+inicioUsuario);
		mensagemSucesso("Usuário excluido com sucesso\n");
	}
	free(itensParaSelecionar);
}