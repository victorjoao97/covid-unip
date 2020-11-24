#ifdef defined(__unix__) || defined(__linux__) || defined(unix) || defined(__unix)

    #include <curses.h>

#elif defined(_WIN32) || defined(WIN32) || defined(_WIN64) || defined(WIN64)

	#include <conio.h>

#endif
#include <stdio.h>
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
		mensagemErro("Nenhum usu�rio encontrado\n");
		return;
	}
	
	int usuarioSelecionado;
	struct ItensParaSelecionar *itensParaSelecionar = malloc((totalUsuarios - inicioUsuario) * sizeof(*itensParaSelecionar));
	
	for(contadorPulaAdmin = inicioUsuario; contadorPulaAdmin < totalUsuarios; contadorPulaAdmin++)
	{
		itensParaSelecionar[contadorPulaAdmin-inicioUsuario].id = todosUsuarios[contadorPulaAdmin].id;
		itensParaSelecionar[contadorPulaAdmin-inicioUsuario].text = todosUsuarios[contadorPulaAdmin].nome;
	}
	usuarioSelecionado = selectWithArrows(&itensParaSelecionar, "DELETAR USU�RIO", "um usu�rio", totalUsuarios - inicioUsuario);
	if (usuarioSelecionado == -1)
	{
		mensagemAviso("Nenhum usu�rio selecionado\n");
		return;
	}
	else
	{
		deleteUsuario(usuarioSelecionado+inicioUsuario);
		mensagemSucesso("Usu�rio excluido com sucesso\n");
	}
	free(itensParaSelecionar);
}