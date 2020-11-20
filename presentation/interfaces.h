#ifndef _INTERFACES_PRESENTATION_H_
#define _INTERFACES_PRESENTATION_H_

void menuPrincipal();
void menuUsuarios();
void menuPacientes();
void menuComorbidades();

void leituraChar(char *mensagem, char *textoSaida, int limiteCaracteres);
int leituraInt(char *mensagem);
void leituraEndereco(char *mensagem, struct Endereco* endereco);
void leituraData(char *mensagem, struct Data* data);
int selectWithArrows(struct ItensParaSelecionar **itensParaSelecionar, char *mensagemHeader, char *type, int totalItens);
void mostrarUsuarios();

void cadastrarComorbidade();
void mostrarComorbidades();

void cadastrarPaciente();

int mensagemErro(char *format, ...);
void mensagemErroSemLimpar(char *format, ...);
void mensagemSucesso(char *format, ...);
void mensagemAviso(char *format, ...);

void headerMenu(char *mensagem);
void pausaParaContinuar();

#endif /* _INTERFACES_PRESENTATION_H_ */
