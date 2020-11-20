#ifndef _INTERFACES_REPOSITORY_H_
#define _INTERFACES_REPOSITORY_H_

void adicionarUsuario(struct Usuario usuario);
void lerTodosUsuarios();
void deleteUsuario(int linha);
struct Usuario usuarioPeloId(int id);
int ultimoIdUsuario();
void realocaMemoriaUsuarios(int totalLinhas);

void adicionarPaciente(struct Paciente* paciente);
void lerTodosPacientes();
int ultimoIdPaciente();
void realocaMemoriaPacientes(int totalLinhas);

void adicionarComorbidade(struct Comorbidade comorbidade);
void lerTodasComorbidades();
void deleteComorbidade(int linha);
int ultimoIdComorbidade();
void realocaMemoriaComorbidades(int totalLinhas);
void adicionarComorbidadePaciente(struct Comorbidade comorbidade, struct Paciente paciente);
void adicionarArquivoPacientesRisco(struct Paciente* paciente);

#endif /* _INTERFACES_REPOSITORY_H_ */