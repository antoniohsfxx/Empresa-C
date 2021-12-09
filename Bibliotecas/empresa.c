#include "./empresa.h"
#include <stdlib.h>
#include <stdio.h>

/* ==============================
Cria o vetor de ponteiros e aloca todos os registros de funcionários
*/
PTEmpresa criarEmpresa(){
    PTEmpresa reg = (PTEmpresa) malloc(sizeof(TEmpresa));
    if (reg == NULL)
        return NULL;
    reg->nReg=0;
    reg->empresa = (PTFuncionario*) malloc(sizeof(TFuncionario) * MAX_EMPRESA);
    if (reg->empresa == NULL){
        free(reg);
        return NULL;
    }
    return reg;
}

/* ==============================
Insere 01 registro de funcionários no final da lista da empresa.
Entradas: 
- Ponteiro para a lista da empresa.
- Ponteiro para o registro do funcionário.
Retorna:
- 0 (zero) se a operação é bem sucedida
- 1 em caso de erro (lista cheia).
*/
int inserirEmpresa (PTFuncionario ptf, PTEmpresa pte){
    if (ptf==NULL || pte == NULL)
        return 1; // Erro de inserção
    if (pte->nReg >= MAX_EMPRESA)
        return 2; // Erro: lista cheia
    pte->empresa[pte->nReg] = ptf;
    pte->nReg++;
    // printf("inserirEmpresa: <%s> <%d> <%d>  \n", ptf->nome, ptf->idade, ptf->horas);
    // printf("pte->nReg: %d\n", pte->nReg);
    return 0;  
}

/* ==============================
Imprime a lista de registro da empresa no dispositivo padrão.
Entrada: Ponteiro para o registro.
*/
void printEmpresa(PTEmpresa pte){
    printf("= = = = = = printEmpresa: INICIO = = = = = =\n");
    printf("Ordem: ID / NOME / HORAS TRABALHADAS / IDADE\n");
    if (pte == NULL)
        return; // Não existe a lista
    printf("Numero de registros: %d\n", pte->nReg);
    int i;
    for (i=0; i<pte->nReg; i++)
        printf("%d %30s %d %d\n", i, pte->empresa[i]->nome, pte->empresa[i]->horas, pte->empresa[i]->idade);
    printf("= = = = = = printEmpresa: F I M  = = = = = =\n");
    
}

/* ==============================
Lê todos os registros do arquivo e armazena na lista.
Entradas: 
 - Ponteiro para o arquivo. 
 - Ponteiro para a lista.
*/
int lerEmpresa(PTEmpresa pte, char* arquivo){
	FILE *ifp; // Ponteiro para o arquivo de entrada
    ifp = fopen(arquivo, "r"); // Abrir o arquivo
    if (ifp == NULL)
        return 1; // Erro de abertura do arquivo
    PTFuncionario p = criarFuncionario(); // Criar registro de funcionário
    while (!feof(ifp) && lerRegFuncionario(p, ifp)==0){
        // Não é fim de arquivo e o registro lido é válido.
        if (inserirEmpresa (p, pte)){
            fclose(ifp);
            return 2; // Erro de inserção
        }
        p = criarFuncionario(); // Criar um novo registro a ser inserido
    }
    fclose(ifp);    
    return 0;    
}

/* ==============================
Libera o espaço de memória ocupado pelo vetor e respectivos registros
Entrada: Ponteiro para o registro.
*/
PTEmpresa deleteEmpresa(PTEmpresa ptempresa){
    int i;
    if (ptempresa == NULL)
        return NULL; // Lista vazia
    for (i=0; i<ptempresa->nReg; i++) // Remove todos os funcionarios
        deleteFuncionario(ptempresa->empresa[i]);
    free(ptempresa);
    return NULL;    
} 

/* ==============================
Escreve a lista de registros da empresa em arquivo.
Entradas: 
 - Ponteiro para o arquivo. 
 - Ponteiro para o registro.
*/
int gravarEmpresa(PTEmpresa pte, char* arquivo){
    int i;
    if (pte == NULL)
        return 0; // Lista vazia

    FILE* ofp = fopen(arquivo, "w");
    if (ofp == NULL)
        return 1;  // Erro de abertura do arquivo
        
    for (i=0; i<pte->nReg; i++) // Grava todos os funcionarios
        gravarRegFuncionario(pte->empresa[i], ofp);
    fflush(ofp);
    fclose(ofp);
    return 0;
}

/* ==============================
Escreve a lista de nome e horas trabalhadas em arquivo.
Entradas: 
 - Ponteiro para o arquivo. 
 - Ponteiro para o registro.
*/
int gravarNomeHoraEmpresa(PTEmpresa pte, char* arquivo){
    int i;
    if (pte == NULL)
        return 0; // Lista vazia

    FILE* ofp = fopen(arquivo, "w");
    if (ofp == NULL)
        return 1;  // Erro de abertura do arquivo
        
    for (i=0; i<pte->nReg; i++)
        gravarNomeHoraFuncionario(pte->empresa[i], ofp);
    fflush(ofp);
    fclose(ofp);
    return 0;
}

/* ==============================
Ordenar a lista ordenada por horas trabalhadas
*/
void ordenarHoraEmpresa(PTEmpresa pte){
    int i, j, k;
    PTFuncionario aux;
    if(pte == NULL)
        return; // Lista vazia
    for (i=0; i<pte->nReg-1; i++){
        k=i;
        for (j=i+1; j<pte->nReg; j++)
            if (compararHorasFuncionario(pte->empresa[k], pte->empresa[j])>0)
                k=j;
        if (k != i){ // Troca os endereços do vetor
            aux = pte->empresa[i];
            pte->empresa[i] = pte->empresa[k];
            pte->empresa[k] = aux;
        }
    }
}
/* ==============================
Ordenar a lista ordenada por horas trabalhadas
*/
void ordenarHoraEmpresaEx(PTEmpresa pte){
    int i, j, k;
    PTFuncionario aux;

            printEmpresa(pte);
            char buffer[80];
            printf("Digite algo para continuar");
            fgets(buffer, 79, stdin);
            setbuf(stdin, NULL);  

    if(pte == NULL)
        return; // Lista vazia
 //   printf("\ti\tj\tk\th1\th2\n");
    for (i=0; i<pte->nReg-1; i++){
        k=i;
        for (j=i+1; j<pte->nReg; j++){
//        printf("\t%d\t%d%d\t%d\t%d\n", i,j,k,pte->empresa[k]->horas, pte->empresa[j]->horas);
            if (compararHorasFuncionario(pte->empresa[k], pte->empresa[j])>0){
                //printf("Trocou k <ant: %d> <atual: %d>\n", k, j);
                k=j;
            }
        }
        if (k != i){ // Troca os endereços do vetor
            printf("=> Encontrou valor menor troca: empresa[%d] <-> empresa[%d]\n", i, k); 
            aux = pte->empresa[i];
            pte->empresa[i] = pte->empresa[k];
            pte->empresa[k] = aux;
            printEmpresa(pte);
            char buffer[80];
            printf("Digite algo para continuar");
            fgets(buffer, 79, stdin);
            setbuf(stdin, NULL);          

        }
    }
}