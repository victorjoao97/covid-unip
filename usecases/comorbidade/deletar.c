#ifdef defined(__unix__) || defined(__linux__) || defined(unix) || defined(__unix)

    #include <curses.h>

#elif defined(_WIN32) || defined(WIN32) || defined(_WIN64) || defined(WIN64)

	#include <conio.h>

#endif
#include <stdio.h>
#include <string.h>
#include "../../header.h"

extern int totalComorbidades;
extern struct Comorbidade *todasComorbidades;

void deletarComorbidade()
{
	lerTodasComorbidades();
	int comorbidadeSelecionada, contador;


	if (totalComorbidades == 0)
	{
		mensagemErro("Nenhuma comorbidade encontrada\n");
		return;
	}

	struct ItensParaSelecionar *itensParaSelecionar = malloc(totalComorbidades * sizeof(itensParaSelecionar));
	for(contador = 0; contador < totalComorbidades; contador++)
	{
		itensParaSelecionar[contador].id = todasComorbidades[contador].id;
		itensParaSelecionar[contador].text = todasComorbidades[contador].nome;
	}
	comorbidadeSelecionada = selectWithArrows(&itensParaSelecionar, "DELETAR COMORBIDADE", "uma comorbidade", totalComorbidades);
	if (comorbidadeSelecionada == -1)
	{
		mensagemAviso("Nenhuma comorbidade selecionada\n");
		return;
	}
	else
	{
		deleteComorbidade(comorbidadeSelecionada);
		mensagemSucesso("Comorbidade excluida com sucesso\n");
	}
	free(itensParaSelecionar);
}
