#include <string.h>
#include "../../header.h"

void cadastrarUsuario()
{
	struct Usuario novoUsuario;

	leituraChar("Digite o nome do usuário: ", novoUsuario.nome, sizeof(novoUsuario.nome));//, "[a-zA-Z]{5,}");
	leituraChar("Digite a senha: ", novoUsuario.senha, sizeof(novoUsuario.senha));//, ".{5,}");

	adicionarUsuario(novoUsuario);
	mensagemSucesso("Usuário cadastrado com sucesso\n");
}
