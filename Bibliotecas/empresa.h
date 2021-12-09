/* ========================================================
Uma empresa possui 21 funcionários e mantém as seguintes 
informações por funcionário: número de horas trabalhadas no mês, nome. 
Elabore um programa que: 
- gere uma lista contendo os nomes dos funcionários com as 
respectivas horas trabalhadas. 
- gere uma lista contendo os nomes dos funcionários com as 
respectivas horas trabalhadas. A lista deve estar ordenada pelo número de horas trabalhadas.
*/
#ifndef EMPRESA_2021_HHH
#define EMPRESA_2021_HHH 
#include "./funcionario.h"
#include <stdlib.h>
#include <stdio.h>

#define MAX_EMPRESA 21

/* ========================================================
	# 1. Definir o novo tipo de dado (registro)
	tipo TEmpresa = registro
			empresa[MAX_EMPRESA] : TFuncionario;
		fimRegistro
*/
struct Empresa{
	PTFuncionario* empresa;
	int nReg;
};
typedef struct Empresa TEmpresa;
typedef TEmpresa* PTEmpresa;

/* ==============================
Cria o vetor de ponteiros e aloca todos os registros de funcionários
*/
PTEmpresa criarEmpresa();

/* ==============================
Libera o espaço de memória ocupado pelo vetor e respectivos registros
Entrada: Ponteiro para o registro.
*/
PTEmpresa deleteEmpresa(PTEmpresa); 

/* ==============================
Insere 01 registro de funcionários no final da lista da empresa.
Entradas: 
- Ponteiro para a lista da empresa.
- Ponteiro para o registro do funcionário.
Retorna:
- 0 (zero) se a operação é bem sucedida
- 1 em caso de erro (lista cheia).
*/
int inserirEmpresa (PTFuncionario, PTEmpresa);

/* ==============================
Imprime a lista de registro da empresa no dispositivo padrão.
Entrada: Ponteiro para o registro.
*/
void printEmpresa(PTEmpresa);

/* ==============================
Lê todos os registros do arquivo e armazena na lista.
Entradas: 
 - Identificador do arquivo físico. 
 - Ponteiro para a lista.
*/
int lerEmpresa(PTEmpresa, char*);

/* ==============================
Escreve a lista de registros da empresa em arquivo.
Entradas: 
 - Ponteiro para o arquivo. 
 - Ponteiro para o registro.
*/
int gravarEmpresa(PTEmpresa, char*);

/* ==============================
Escreve a lista de nome e horas trabalhadas em arquivo.
Entradas: 
 - Ponteiro para o arquivo. 
 - Ponteiro para o registro.
*/
int gravarNomeHoraEmpresa(PTEmpresa, char*);

/* ==============================
gerar a lista ordenada por horas trabalhadas
*/
void ordenarHoraEmpresa(PTEmpresa);

void ordenarHoraEmpresaEx(PTEmpresa pte);
#endif