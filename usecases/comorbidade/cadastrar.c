#include <string.h>
#include "../../header.h"

void cadastrarComorbidade()
{
	struct Comorbidade novaComorbidade;

	leituraChar("Digite o nome da comorbidade: ", novaComorbidade.nome, sizeof(novaComorbidade.nome));//, "[a-zA-Z]{2,}");

	adicionarComorbidade(novaComorbidade);
	mensagemSucesso("Comorbidade cadastrada com sucesso\n");
}
