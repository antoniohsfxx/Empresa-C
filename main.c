#include "./Bibliotecas/funcionario.c"
#include "./Bibliotecas/funcionario.h"
#include "./Bibliotecas/empresa.c"
#include "./Bibliotecas/empresa.h"

#include "./Assets/Menus.c"
#include "./Assets/Menus.h"

#include <stdio.h>
#include <string.h>
#include <locale.h>

//=============AVISO WINDOWS CMD=============
//Use o comando: 'chcp 65001' para alterar o 
//padrão do console do Windows para UTF-8.
//=============AVISO WINDOWS CMD=============


/*
Procedimento da Primeira (e principal) opção do Menu Principal.

O procedimento possui um sistema que busca por 21 nomes aleatórios que estão presentes no vetor 'randomnames[]'
para serem os nomes dos 21 funcionários que tersão seus dados registrados no sistema e posteriormente salvos em
um documento .txt (Funcionarios.txt).

O procedimento possui um laço de repetição com objetivo de registrar os dados de cada um dos 21 funcionários.
*/
void mp01(){
    int i;
    
    PTEmpresa pte = criarEmpresa(); // Criar empresa 
   //Vetor com nomes aleatórios.
    const char *randomnames[] = {
        "Yasmim","Raphael","Rafaela","Lívia","Fabrícia","Wando",
        "Felício","Antonio","Derocy","Leonardo","Maicon","Hugo",
        "Pedro","Roberto","Cristino","Elizana","Sandro","Leal",
        "Tião","Julyane","Júnior","Jussara","Justina","Narcisa",
        "Narciso","Natacha","Natália","Natalie","Natanael","Kaila",
        "Kaio","Kalil","Kalila","Kaori","Karen","Daria",
        "Dario","Darlene","Davi","David","Daya","Kate",
        "Katerine","Katharina","Marcos","Veiga","Deyverson"
    };
    const size_t randomnames_count = sizeof(randomnames) / sizeof(randomnames[0]);
    for (i=0; i<=21; i++) {
        int random_idade = i* rand() % 60 + 15; //Número aleatório para idade.
        int random_horas = i* rand() % 320 + 1; //Número aleatório para horas trabalhadas.
        char* random_nomes = randomnames[rand()*rand()*157*i % randomnames_count]; //Variável com o nome aleatório.

        PTFuncionario pt = initFuncionario(random_nomes, random_horas, random_idade);
        inserirEmpresa(pt, pte);
    }
    gravarEmpresa(pte, "Funcionarios.txt"); //Salva os funcionários da empresa no arquivo Funcionarios.txt.
    printEmpresa(pte); //Imprime os os funcionários da empresa.
    voltarMenuPrincipal(); //Volta para o Menu Principal.
}

/*
Procedimento da Segunda opção do Menu Principal.
Usado para armazenar em variáveis locais o Nome, Horas Trabalhadas e a Idade do funcionário para
depois registrar o funcionário utilizando as bibliotecas de empresa e funcionario e depois grava-los
em um arquivo .txt e imprimi-los para o usuário.

O procedimento possui um laço de repetição com objetivo de saber quantos funcionários o usuário deseja
registrar.
*/
void mp02(){
    //Variáveis usadas no laço de repetição.
    int i, quantia;

    //Variáveis usadas para armazenar temporariamente o Nome, Horas Trabalhadas e a Idade do funcionário.
    char funcnome[100];
    int funchoras, funcidade;

    PTEmpresa pte = criarEmpresa(); //Criar empresa.
    printf("Quantos funcionários a empresa terá? ");
    scanf("%d", &quantia);
    quantia = quantia-1;
    
    for (i=0; i<=quantia; i++) {
        printf("Nome: "); scanf("%s", funcnome);
        printf("Horas Trabalhadas: "); scanf("%d", &funchoras);
        printf("Idade: "); scanf("%d", &funcidade);
        PTFuncionario pt = initFuncionario(funcnome, funchoras, funcidade);
        inserirEmpresa(pt, pte);
        printf("%s, %d, %d\n\n", funcnome, funchoras, funcidade);
    }
    gravarEmpresa(pte, "FuncionariosMP2.txt"); //Salva os funcionários da empresa no arquivo FuncionariosMP2.txt.
    printEmpresa(pte); //Imprime os os funcionários da empresa.
    voltarMenuPrincipal(); //Volta para o Menu Principal.
}

/*
Procedimento da Terceira opção do Menu Principal.

O procedimento cria uma empresa, onde serão registrados os funcionários
contidos no arquivo .txt que o usuário selecionou.
*/
void mp03(){
    PTEmpresa pte = criarEmpresa();
    lerEmpresa(pte, nomeTXT); //nomeTXT = Nome do arquivo .txt com os dados dos funcionários.
    printEmpresa(pte); //Imprime os os funcionários da empresa.
    voltarMenuPrincipal(); //Volta para o Menu Principal.
}

/*
Procedimento da Quarta opção do Menu Principal.

O procedimento cria uma empresa, onde serão registrados os funcionários
contidos no arquivo .txt que o usuário selecionou entretanto, agora em ordem de Horas Trabalhadas.
*/
void mp04(){
    PTEmpresa pte = criarEmpresa();
    lerEmpresa(pte, nomeTXT); //nomeTXT = Nome do arquivo .txt com os dados dos funcionários.
    ordenarHoraEmpresa(pte);
    printEmpresa(pte); //Imprime os os funcionários da empresa.
    gravarEmpresa(pte, nomeTXT);
    voltarMenuPrincipal(); //Volta para o Menu Principal.
}

int main() {
    setlocale(LC_ALL, "pt_BR"); //Usado para que os acentos funcionem no console.
    menuPrincipal(); //Procedimento que chama o Menu Principal do programa AH-Empresa.
    return 0;
}