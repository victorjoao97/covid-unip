#include <string.h>
#include "../../header.h"

void cadastrarUsuario()
{
	struct Usuario novoUsuario;

	leituraChar("Digite o nome do usu�rio: ", novoUsuario.nome, sizeof(novoUsuario.nome));//, "[a-zA-Z]{5,}");
	leituraChar("Digite a senha: ", novoUsuario.senha, sizeof(novoUsuario.senha));//, ".{5,}");

	adicionarUsuario(novoUsuario);
	mensagemSucesso("Usu�rio cadastrado com sucesso\n");
}
