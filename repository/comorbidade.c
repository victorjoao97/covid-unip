#include <stdio.h>
#include <string.h>
#include "../header.h"

extern int totalComorbidades;
extern int limitComorbidades;
extern struct Comorbidade *todasComorbidades;

void adicionarComorbidade(struct Comorbidade comorbidade)
{
	int id = ultimoIdComorbidade();
	id++;
	FILE *arquivo = escreveArquivoComorbidades(joinDirFilename(DIRETORIO_ARQUIVOS, ARQUIVO_COMORBIDADES));
	fprintf(arquivo, "%d,%s\n", id, comorbidade.nome);
	fclose(arquivo);
}

void lerTodasComorbidades()
{
	int i, totalLinhas;
	FILE *arquivo = leituraArquivoComorbidades();
	totalComorbidades = 0;
	i = 0;
	
    totalLinhas = totalDeLinhas(arquivo);
    realocaMemoriaComorbidades(totalLinhas);
    
	char row[totalLinhas][(int)(sizeof(struct Comorbidade))];
    rewind(arquivo);
	while (fgets(row[i], sizeof(row[i]), arquivo) != NULL)
	{
		comorbidadeAdapter(row[i], &todasComorbidades[i]);
		i++;
		totalComorbidades++;
	}
	fclose(arquivo);
}

int ultimoIdComorbidade()
{
	lerTodasComorbidades();
	int maiorId = todasComorbidades[0].id;
	int i;
	for (i = 0; i < totalComorbidades; i++)
	{
		if (strcmp(todasComorbidades[i].nome, "") != 0 && todasComorbidades[i].id > maiorId)
		{
			maiorId = todasComorbidades[i].id;
		}
	}
	return maiorId;
}

void realocaMemoriaComorbidades(int totalLinhas)
{
    if (totalLinhas > limitComorbidades)
	{
		limitComorbidades = (int)(totalLinhas + limitComorbidades) * 1.2;
		todasComorbidades = realloc(todasComorbidades, sizeof(struct Comorbidade) * limitComorbidades);
	}
}