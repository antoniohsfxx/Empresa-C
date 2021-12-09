/* ========================================================
Uma empresa possui 21 funcionários e mantém as seguintes 
informações por funcionário: número de horas trabalhadas no mês, nome. 
Elabore um programa que: 
- gere uma lista contendo os nomes dos funcionários com as 
respectivas horas trabalhadas. 
- gere uma lista contendo os nomes dos funcionários com as 
respectivas horas trabalhadas. A lista deve estar ordenada pelo número de horas trabalhadas.
*/
#ifndef Funcionario_ssh_789
#define Funcionario_ssh_789 

#include <stdlib.h>
#include <stdio.h>

#define NOME_TAM 40
#ifndef NULL
#define NULL 0
#endif
/* ========================================================
	# 1. Definir o novo tipo de dado (registro)
	tipo TFuncionario = registro
			horas: INTEIRO
			nome: CADEIA
		fimRegistro
*/
struct Funcionario {
    int horas;
    int idade;
    char* nome;
};
typedef struct Funcionario TFuncionario;
typedef struct Funcionario* PTFuncionario;

/* ==============================
Aloca o espaço de memória correspondente ao
tamanho do registro Funcionario.
Entrada: Ponteiro para o registro.
Retorno:  
- endereço da memória alocada, 
caso a operação seja bem sucedida.
- NULL (0) caso ocorra erro.
*/
PTFuncionario criarFuncionario();

/* ==============================
Libera o espaço de memória ocupado pelo registro
Entrada: Ponteiro para o registro.
*/
void deleteFuncionario(PTFuncionario); 

/* ==============================
Lê os dados de um funcionário, a partir do
"stream input" padrão (teclado), e os armazena 
no registro passado como argumento.
Entrada: Ponteiro para o registro.
*/
int lerFuncionario(PTFuncionario); 

/* ==============================
Imprime os dados do funcionario no dispositivo padrão 
de saída (output stream: video)
Entrada: Ponteiro para o registro.
*/
void printFuncionario(PTFuncionario);

/* ==============================
Lê um registro do arquivo.
Entradas: 
 - Ponteiro para o arquivo. 
 - Ponteiro para o registro.
*/
int lerRegFuncionario(PTFuncionario, FILE*);

/* ==============================
Escreve um registro do arquivo.
Entradas: 
 - Ponteiro para o arquivo. 
 - Ponteiro para o registro.
*/
int gravarRegFuncionario(PTFuncionario, FILE*);

/* =============================
Aloca o espaço de memória correspondente ao tamanho do registro Funcionario e
copia as entradas para os respectivos campos do registro.
Entrada: nome, horas, idade.
Retorno:  
- endereço da memória alocada, 
caso a operação seja bem sucedida.
- NULL (0) caso ocorra erro.
*/
PTFuncionario initFuncionario(char* nome, int horas, int idade);

/* ==============================
Escreve o nome do funcionario e o numero de horas trabalhadas para
no arquivo.
Entradas: 
 - Ponteiro para o arquivo. 
 - Ponteiro para o registro.
*/
int gravarNomeHoraFuncionario(PTFuncionario, FILE*);

/* ==============================
Compara o número de horas trabalhadas de dois registros de funcionário.
Retorna:
-1 (menos um) se o valor do primeiro argumento é menor;
0 (zero) se os valores são iguais
1 (um) se o valor do primeiro argumento é maior
*/
int compararHorasFuncionario(PTFuncionario, PTFuncionario);
#endif