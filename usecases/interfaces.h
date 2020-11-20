#ifndef _INTERFACES_USECASES_H_
#define _INTERFACES_USECASES_H_

bool login(struct Usuario *usuarios);

void cadastrarUsuario();
void deletarUsuario();

void deletarComorbidade();

void cadastrarPaciente();

void verificaESalvaGrupoRisco(struct Paciente* paciente);

#endif /* _INTERFACES_USECASES_H_ */