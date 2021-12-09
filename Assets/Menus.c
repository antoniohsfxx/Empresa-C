#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Variável char que contém o nome do arquivo .txt que será usado na segunda opção do Menu Principal.
char nomeTXT[100]; 

//Procedimento para imprimir o cabeçario.
void cabecario() {
    printf("--------------------------------------------------\n");
	printf("|                   AH-Empresa                   |\n");
	printf("--------------------------------------------------\n");
}

//Procedimento para voltar ao Menu Principal após uma busca.
void voltarMenuPrincipal() {
	int continuar;
	printf("\n[AVISO] Digite qualquer NÚMERO e clique enter para continuar!");
	scanf("%d", &continuar);
	system("cls");
    menuPrincipal();
}

/*
Procedimento que mostra o Menu Principal do programa AH-Empresa.
Nesse procedimento, foi usado 'switch case' para navegar entre as possíveis escolhas 
do usuário, que no caso podem ser três diferentes.
*/
void menuPrincipal() {
    int escolha; //Variável local usada no 'switch case'.
    cabecario();
    	printf(
		"1 - Empresa com 21 Funcionários.\n"
		"2 - Digitar funcionários.\n"
		"3 - Ler funcionários de uma lista.\n"
        "4 - Ordenar lista por Horas Trabalhadas"
		"\nDigite a sua opcao: "
	);scanf("%d", &escolha);
    
    switch (escolha) {
    case 1:
        system("cls");
        cabecario();
        mp01();
        break;
    
    case 2: 
        system("cls");
        cabecario();
        mp02();
        break;

    case 3: 
        system("cls");
        cabecario();
        printf("Digite o nome do arquivo .txt: ");    
        scanf("%s", nomeTXT);
        printf("\n");
        mp03();
        break;
    
    case 4:
        system("cls");
        cabecario();
        printf("Digite o nome do arquivo .txt: ");    
        scanf("%s", nomeTXT);
        printf("\n");
        mp04();
        break;
    
    default: break;
    }
}