#include <stdio.h>
#include "../header.h"

void menuPacientes()
{
	int opcao;
inicio:
	limpaTela();
	headerMenu("PACIENTES");
	printf("1 - Cadastrar \n0 - Voltar\n");
	scanf("%d", &opcao);
	limpaTela();
	switch (opcao)
	{
	case 1:
		headerMenu("CADASTRAR PACIENTE");
		cadastrarPaciente();
		goto inicio;
		break;
	case 0:
		printf("voce pediu para voltar, prencione qualquer tecla para continuar\n");
		break;
	default:
		printf("voce deve escolher uma opcao valida\n");
		printf("Precione qualquer tecla para voltar ao menu\n");
		pausaParaContinuar();
		goto inicio;
	}

}