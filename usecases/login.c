#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../header.h"

extern struct Usuario usuarioLogado;

bool login(struct Usuario *usuarios)
{
	limpaTela();
	headerMenu("Sistema Covid UNIP - PIM IV");
	struct Usuario usuarioInput;
	struct Usuario usuarioLogin;
	bool novaTentativa = false;
	printf("Digite o id do usuario: ");
	fflush(stdin);
	scanf("%d", &usuarioInput.id);
	printf("Digite a senha do usuario: ");
	fflush(stdin);
	scanf("%s", usuarioInput.senha);
	usuarioLogin = usuarioPeloId(usuarioInput.id);

	if (strcmp(usuarioLogin.senha, usuarioInput.senha) == 0)
	{
		usuarioLogado = usuarioLogin;
		mensagemSucesso("Logado com sucesso\n");
		return true;
	}
	
	int key = mensagemErro("ID/senha não confere, tente novamente\nPressione ESC para sair ou qualquer outra tecla para tentar novamente\n");
	if (key != 27)
	{
		novaTentativa = login(usuarios);
	}
	return novaTentativa;
}