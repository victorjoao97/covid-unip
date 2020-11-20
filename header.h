#ifndef _HEADER_H_
#define _HEADER_H_

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include "libs/colors.h"

#define BUFFER_SIZE 200
#define IDADE_GRUPO_RISCO 65
#define DIRETORIO_ARQUIVOS "./db/"
#define ARQUIVO_USUARIOS "usuarios.txt"
#define ARQUIVO_PACIENTES "pacientes.txt"
#define ARQUIVO_COMORBIDADES "comorbidades.txt"
#define ARQUIVO_COMORBIDADE_PACIENTE "comorbidade-paciente.txt"
#define ARQUIVO_PACIENTES_RISCO "PACIENTES_RISCO.TXT"

#include "domain/entidades.h"
#include "infra/interfaces.h"
#include "repository/interfaces.h"
#include "presentation/interfaces.h"
#include "usecases/interfaces.h"
#include "domain/interfaces.h"

void limpaTela();
void removeEndString(char *string);
char* joinDirFilename(char *dir, char* filename);
char *ltrim(char *s);
char *rtrim(char *s);
char *trim(char *s);
int calculaIdade(struct Data dataNascimento);
int validaPorRegex(char *expressao, char *stringTest);

#endif /* _HEADER_H_ */
