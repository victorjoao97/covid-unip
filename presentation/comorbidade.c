#include <stdio.h>
#include "../header.h"

extern int totalComorbidades;
extern struct Comorbidade *todasComorbidades;

void menuComorbidades()
{
	int opcao;
inicio:
	limpaTela();
	headerMenu("COMORBIDADES");
	printf("1 - Cadastrar \n2 - Mostrar\n3 - Deletar\n0 - Voltar\n");
	scanf("%d", &opcao);
	limpaTela();
	switch (opcao)
	{
	case 1:
		headerMenu("CADASTRAR COMORBIDADE");
		cadastrarComorbidade();
		goto inicio;
		break;
	case 2:
		headerMenu("MOSTRAR COMORBIDADES");
		mostrarComorbidades();
		goto inicio;
		break;
	case 3:
		headerMenu("DELETAR COMORBIDADE");
		deletarComorbidade();
		goto inicio;
		break;
	case 0:
		printf("voce pediu para voltar, prencione qualquer tecla para continuar\n");
		break;
	default:
		printf("voce deve escolher uma opcao valida\n");
		printf("Precione qualquer tecla para voltar ao menu\n");
		system("pause");
		goto inicio;
	}

}

void mostrarComorbidades()
{
	struct Comorbidade comorbidade;
	lerTodasComorbidades();
	int contador;
	
	if (totalComorbidades == 0)
	{
		mensagemErro("Nenhuma comorbidade encontrada\n");
		return;
	}

	for(contador = 0; contador < totalComorbidades; contador++)
	{
		comorbidade = todasComorbidades[contador];
		printf("ID: %d, Nome: %s\n", comorbidade.id, comorbidade.nome);
	}
	pausaParaContinuar();
}