#ifndef _INTERFACES_INFRA_H_
#define _INTERFACES_INFRA_H_

FILE* leituraArquivo(char *nomeArquivo, void (FILE*));
FILE* escreveArquivo(char *nomeArquivo, void (FILE*));
void deleteLine(FILE *srcFile, char *fileName, const int line);
void deleteLines(FILE *srcFile, char *fileName, const int *lines);
bool criaArquivoSeNaoExiste(char *nomeArquivo, void (FILE*));
void criarDiretorio(char *diretorio);
int totalDeLinhas(FILE *arquivo);

FILE* escreveArquivoUsuarios();
FILE* leituraArquivoUsuarios();
void inicializaArquivoUsuarios(FILE *arquivo);
void usuarioAdapter(char *file, struct Usuario *usuario);

FILE* escreveArquivoPacientes();
FILE* leituraArquivoPacientes();
void inicializaArquivoPacientes(FILE *arquivo);
void pacienteAdapter(char *file, struct Paciente *paciente);

FILE* leituraArquivoComorbidades();
FILE* escreveArquivoComorbidades();
void inicializaArquivoComorbidades(FILE *arquivo);
void comorbidadeAdapter(char *file, struct Comorbidade *comorbidade);

FILE* escreveArquivoComorbidadePaciente();
void inicializaArquivoComorbidadePaciente(FILE *arquivo);

FILE* escreveArquivoPacientesRisco();
void inicializaArquivoPacientesRisco(FILE *arquivo);

#endif /* _INTERFACES_REPINFRA */