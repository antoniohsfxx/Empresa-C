
#include "./funcionario.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Criar um registro vazio. 
PTFuncionario criarFuncionario(){
   PTFuncionario reg = (PTFuncionario) malloc(sizeof (TFuncionario));
   if (reg == NULL)
        return NULL; // Erro de alocação de memória
   reg->nome = (char*) malloc(sizeof (char) * NOME_TAM);
   if (reg->nome == NULL){
       free(reg);  // Erro de alocação de memória
       return NULL;
   }
   reg->nome[0] = '\0'; // Para usar a biblioteca string.h
   reg->horas = 0;
   reg->idade = 0;
   return reg;
}
// Criar com valores iniciais. 
PTFuncionario initFuncionario(char* nome, int horas, int idade){
   PTFuncionario reg = (PTFuncionario) malloc(sizeof (TFuncionario));
   if (reg == NULL)
        return NULL; // Erro de alocação de memória
   reg->nome = (char*) malloc(sizeof (char) * NOME_TAM);
   if (reg->nome == NULL){
       free(reg);  // Erro de alocação de memória
       return NULL;
   }
   reg->nome[0] = '\0'; // Para usar a biblioteca string.h
   strcpy(reg->nome, nome);
   reg->horas = horas;
   reg->idade = idade;
   return reg;
}

void deleteFuncionario(PTFuncionario p){
    if (p){
        if (p->nome)
            free(p->nome);
        free(p);
    }
}
int lerFuncionario(PTFuncionario funcionario)
{   printf(" = = = = lerRegFuncionario  = = = =\n");
    if (funcionario == NULL)
        return 1; // O registro deve ser alocado antes de ser lido
    setbuf(stdin, NULL);
    printf("Nome: ");
    fgets(funcionario->nome, NOME_TAM-1, stdin);
    funcionario->nome[strlen(funcionario->nome)-1]='\0';
    setbuf(stdin, NULL);
    printf("Horas trabalhadas: ");
    scanf("%d", &(funcionario->horas));
    printf("Idade: ");
    scanf("%d", &(funcionario->idade));
    return 0;
}

void printFuncionario(PTFuncionario funcionario)
{
    if (funcionario == NULL)
        printf("NULL?");
        return; // O registro deve ser alocado
    printf("Nome: %s\n", funcionario->nome);
    printf("Horas trabalhadas: %d\n", funcionario->horas);
    printf("Idade: %d\n\n", funcionario->idade);
}

int lerRegFuncionario(PTFuncionario funcionario, FILE* arquivo)
{
    char buffer[80];
    if (funcionario == NULL)
        return 1; // O registro deve ser alocado antes de ser lido
    fgets(funcionario->nome, NOME_TAM-1, arquivo);
    if (feof(arquivo))
        return 1;
    funcionario->nome[strlen(funcionario->nome)-1]='\0';
    if (strlen(funcionario->nome) == 0)
        return 1;
    fgets(buffer, NOME_TAM, arquivo);
    funcionario->horas = atoi(buffer); // Converte ascii to int
    fgets(buffer, NOME_TAM, arquivo);
    funcionario->idade = atoi(buffer); // Converte ascii to int
    // printf("lerRegFuncionario: <%s, %d, %d>\n", funcionario->nome, funcionario->horas,funcionario->idade);
    return 0;    
}

int gravarRegFuncionario(PTFuncionario funcionario, FILE* arquivo)
{
    fprintf(arquivo, "%s\n", funcionario->nome);
    fprintf(arquivo, "%d\n%d\n",funcionario->horas, funcionario->idade);
    return 0;
}

int gravarNomeHoraFuncionario(PTFuncionario funcionario, FILE* arquivo)
{
    fprintf(arquivo, "%s\n", funcionario->nome);
    fprintf(arquivo, "%d\n",funcionario->horas);
    return 0;
}

/* ==============================
Compara o número de horas trabalhadas de dois registros de funcionário.
Retorna:
-1 (menos um) se o valor do primeiro argumento é menor;
0 (zero) se os valores são iguais
1 (um) se o valor do primeiro argumento é maior
*/
int compararHorasFuncionario(PTFuncionario arg1, PTFuncionario arg2){
    if (arg1->horas < arg2->horas)
        return -1;
    return (arg1->horas > arg2->horas) ? 1 : 0;      
}
