#if defined(UNIX)
    #include <curses.h>
#else
	#include <conio.h>
#endif

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "../header.h"

extern struct Usuario usuarioLogado;

void menuPrincipal()
{
	int opcao;
inicio:
	limpaTela();
	headerMenu("MENU");
	printf("1 - Usu�rios \n2 - Pacientes\n0 - SAIR\n");
	scanf("%d", &opcao);
	switch (opcao)
	{
	case 1:
		menuUsuarios();
		goto inicio;
		break;
	case 2:
		menuPacientes();
		goto inicio;
		break;
	case 0:
		printf("Saindo do sistema\n");
		break;
	default:
		mensagemAviso("Voce deve escolher uma opcao valida\n");
		goto inicio;
	}
}

int mensagemErro(char *format, ...)
{
	va_list param;
	int ret;
	limpaTela();
	background(RED);
	foreground(WHITE);

	va_start(param, format);
        printf(format, va_arg(param, char*));
    va_end(param);

    ret = getch();
	background(NORMAL);
	foreground(NORMAL_COLOR);
	return ret;
}

void mensagemErroSemLimpar(char *format, ...)
{
	va_list param;
	background(RED);
	foreground(WHITE);

	va_start(param, format);
        printf(format, va_arg(param, char*));
    va_end(param);

    pausaParaContinuar();
	background(NORMAL);
	foreground(NORMAL_COLOR);
}

void mensagemSucesso(char *format, ...)
{
	va_list param;
	limpaTela();
	background(GREEN);
	foreground(WHITE);

	va_start(param, format);
        printf(format, va_arg(param, char*));
    va_end(param);

    pausaParaContinuar();
	background(NORMAL);
	foreground(NORMAL_COLOR);
}

void mensagemAviso(char *format, ...)
{
	va_list param;
	limpaTela();
	background(YELLOW);
	foreground(WHITE);

	va_start(param, format);
        printf(format, va_arg(param, char*));
    va_end(param);

    pausaParaContinuar();
	background(NORMAL);
	foreground(NORMAL_COLOR);
}

void headerMenu(char *mensagem)
{
	limpaTela();
	if (usuarioLogado.id != -1)
	{
		printf("Usu�rio logado [ID: %d, Nome: %s]\n", usuarioLogado.id, usuarioLogado.nome);
	}
	background(BLUE);
	foreground(WHITE);
	int contador;
	printf("-----");
	for(contador = 0; contador < strlen(mensagem); contador++)
	{
		printf("-");
	}
	printf("-----\n-----%s-----\n", mensagem);
	printf("-----");
	for(contador = 0; contador < strlen(mensagem); contador++)
	{
		printf("-");
	}
	printf("-----\n");
	background(NORMAL);
	foreground(NORMAL_COLOR);
}
