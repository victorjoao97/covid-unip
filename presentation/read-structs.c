#if defined(UNIX)
    #include <curses.h>
#else
	#include <conio.h>
#endif
#include <stdio.h>
#include <string.h>
#include <time.h>
#include "../header.h"

extern int totalComorbidades;
extern struct Comorbidade *todasComorbidades;

int qtdEspacos(char *string);

void leituraChar(char *mensagem, char *textoSaida, int limiteCaracteres)
{
inicio:
	printf(mensagem);
	fflush(stdin);
	gets(textoSaida);
	textoSaida = trim(textoSaida);

	if (strlen(textoSaida) >= limiteCaracteres)
	{
		mensagemErroSemLimpar("Excedeu o tamanho m�ximo de %d caracteres\n", limiteCaracteres-1);
		goto inicio;
	}

	if (validaPorRegex("^[\\w ]*$", textoSaida) != strlen(textoSaida))
	{
		mensagemErroSemLimpar("Caracteres inv�lidos\n");
		goto inicio;
	}
}

int leituraInt(char *mensagem)
{
	int numero;
	printf(mensagem);
	fflush(stdin);
	scanf("%d", &numero);
	return numero;
}

void leituraEndereco(char *mensagem, struct Endereco* endereco)
{
	printf(mensagem);

	inicioRua: ;
	leituraChar("Rua: ", endereco->rua, sizeof(endereco->rua));
	if (validaPorRegex("^[\\w ]*$", endereco->rua) < 5)
	{
		mensagemErroSemLimpar("Minimo de 5 caracteres\n");
		goto inicioRua;
	}

	inicioNumero: ;
	leituraChar("N�mero: ", endereco->numero, sizeof(endereco->numero));
	if (validaPorRegex("^[\\w ]*$", endereco->numero) < 1)
	{
		mensagemErroSemLimpar("Minimo de 1 caracteres\n");
		goto inicioNumero;
	}

	inicioBairro: ;
	leituraChar("Bairro: ", endereco->bairro, sizeof(endereco->bairro));
	if (validaPorRegex("^[\\w ]*$", endereco->bairro) < 3)
	{
		mensagemErroSemLimpar("Minimo de 3 caracteres\n");
		goto inicioBairro;
	}

	inicioCidade: ;
	leituraChar("Cidade: ", endereco->cidade, sizeof(endereco->cidade));
	if (validaPorRegex("^[\\w ]*$", endereco->cidade) < 3)
	{
		mensagemErroSemLimpar("Minimo de 3 caracteres\n");
		goto inicioCidade;
	}

	inicioEstado: ;
	leituraChar("Sigla do estado: ", endereco->estado, sizeof(endereco->estado));
	if (validaPorRegex("^[a-zA-Z]*$", endereco->estado) != 2)
	{
		mensagemErroSemLimpar("Digite somente as siglas do estado\n");
		goto inicioEstado;
	}

	inicioCep: ;
	leituraChar("CEP: ", endereco->cep, sizeof(endereco->cep));
	if (validaPorRegex("^[0-9]*$", endereco->cep) != 8)
	{
		mensagemErroSemLimpar("CEP tem que ter 8 digitos\n");
		goto inicioCep;
	}
}

void leituraData(char *mensagem, struct Data* data)
{
    time_t t = time(NULL);
	struct tm tm = *localtime(&t);

	printf(mensagem);

inicioDia: ;
	data->dia = leituraInt("Dia: ");
	if (data->dia < 1 || data->dia > 31)
	{
		mensagemErroSemLimpar("Dia inv�lido\n");
		goto inicioDia;
	}

inicioMes: ;
	data->mes = leituraInt("M�s: ");
	if (data->mes < 1 || data->mes > 12)
	{
		mensagemErroSemLimpar("M�s inv�lido\n");
		goto inicioMes;
	}

inicioAno: ;
	data->ano = leituraInt("Ano: ");
	if (data->ano < 1800 || data->ano > (tm.tm_year + 1900))
	{
		mensagemErroSemLimpar("Ano inv�lido\n");
		goto inicioAno;
	}
}

int selectWithArrows(struct ItensParaSelecionar **itensParaSelecionar, char *mensagemHeader, char *type, int totalItens)
{
	int contador = 0;
	int itemSelecionado = contador;
	int key;

	do
	{
		headerMenu(mensagemHeader);
		printf("Use as setas direcionais (PARA CIMA/PARA BAIXO) para selecionar %s\n", type);
		printf("Depois pressione ENTER para confirmar\nPara cancelar, pressione ESC\n\n");
		for(contador = 0; contador < totalItens; contador++)
		{
			printf("[%c] ID: %d, Nome: %s\n", itemSelecionado == contador ? 'x' : '\0', (*itensParaSelecionar)[contador].id, (*itensParaSelecionar)[contador].text);
		}
		fflush(stdin);
		key = getch();
		if (key == 224)
		{
			do
			{
				key = getch();
			}
			while(key == 224);
			switch (key)
			{
			case 72:
				if (itemSelecionado > 0) itemSelecionado--;
				break;
			case 80:
				if (itemSelecionado < (totalItens - 1)) itemSelecionado++;
				break;
			}
		}
		else if (key == 13)
		{
			key = 27;
			return itemSelecionado;
		}
		limpaTela();
	}
	while (key != 27);

	return -1;
}

int qtdEspacos(char *string)
{
	int qtd = 0, a;
	for(a = 0; a < strlen(string); a++)
		if (string[a] == ' ') qtd++;

	return qtd;
}
